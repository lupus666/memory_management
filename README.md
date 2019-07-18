# memory_management
基于qt5界面库的内存管理模拟系统
## 项目背景
- 一个作业有320条指令
- 一个页面可以容纳10条指令
- 内存分为4块，一个内存块可以容纳一个页面
- 作业运行前，内存块均为分配
- 50%的指令是顺序执行的，25%是均匀分布在前地址部分，25%是均匀分布在后地址部分
- 发生缺页错误，要将页面调入内存

## 开发/运行环境
- 开发环境：Windows10 1809
- 开发语言：C++
- 开发工具：QT Creator 4.9.0
- 开发框架：QT 5.12.2

## 使用说明
![main](https://github.com/lupus666/memory_management/raw/master/image/mainn.png)
这是该模拟系统的GUI界面，以下是对应功能的介绍
1. “NEW”按钮  
    新建新的作业,即产生新的指令序列；并且清空内存块以及统计数据
2. “Clear”按钮  
    清空内存块内容，但仍保留之前生成的指令序列，并清空统计数据
2. “SINGLE STEP”按钮  
    单步执行指令，指令执行情况可在内存区和统计数据区中查看
3. “SEQUENTIAL EXECUTION”按钮  
    顺序执行指令到执行完320条指令
4. “Algorithm”选择按钮  
    选择页面替换算法，可以选择FIFO算法，LRU算法，RAND算法
5. 指令列表区  
    右侧的“Instruction List”区域显示了该作业的320条指令序列
6. 统计数据区  
    中间区域显示了缺页次数，缺页率，当前指令所在内存页号，当前指令所在页的页偏移，当前指令序号等信息
7. 内存区  
    左侧“Memory”区域显示了当前内存情况

## 项目解决方案
### 指令结构
```C++
struct Instruction{
    int current_address;        //指令地址及指令序号
    QString content;            //指令内容
    int next_address;           //下一条指令地址及指令序号
    Instruction(int current = -1, int next = -1, QString str = "DO SOMETHING"):current_address(current), content(str), next_address(next){}
};
```
指令结构采用结构体进行组织，其中：
1. current_address：int类型，当前指令地址及指令序号标识
2. content：string类型，指令内容
3. next_address：int类型，下一条指令地址以及指令序号标识
4. Instruction()：指令构造函数

### 页面结构
```C++
class CPage{
private:
    int last_used_point;        //页面最近访问的时间，用运行周期来记录
    int in_point;               //页面调入内存的时间，用运行周期来记录
    Instruction* ins_vec;       //指令数组
    unsigned int page_size;     //页面大小，默认值为10
    int page_id;                //页面标识号
    //省略函数
```
1. last_used_point：记录页面最近访问的时间，用于实现LRU算法，其中用当前已执行指令的数量来代表使用时间，last_used_point越大，最后一次访问越近。
2. in_point：记录页面调入内存的时间，用于实现FIFO算法，其中用当前已执行指令的数量来代表使用时间，in_point越小，调入内存时间越早。
3. ins_vec：存储了若干条指令（10条）的数组，其中的指令都属于该页面。
4. page_size：页面大小，即可存储指令的数量。
5. page_id：页面标识号，方便页面的识别和搜索。

### 页目录结构
```C++
    CPage* memory_page_vec;         //内存页面数组，即页目录
```
页目录是一个页面指针数组，数组下标即为内存块偏移量

### 算法实现
#### 指令随机生成算法
```C++
void progress::init_ins()
{
    srand((unsigned)time(NULL));
    int current = 0;
    int next = 1;
    for(int i = 0; i < progress_size;i++){
        if(i%4 == 1){                               //随机生成后地址指令
            next = jump_back(current + 2);
        }else if(i%4 == 3){                         //随机生成前地址指令
            next = jump_front(current - 1);
        }else{
            next = current + 1;                     //生成顺序指令
        }
        Instruction ins_temp(current, next);
        all_ins_vec[current] = ins_temp;
        current +=1;
    }
    //省略指令分配页面
}
/*随机生成前地址算法*/
int progress::jump_front(int m)
{
    srand((unsigned)time(NULL));
    return rand()%m;
}
/*随机生成后地址转算法*/
int progress::jump_back(int m)
{
    srand((unsigned)time(NULL));
    return rand()%(progress_size - m) + m;
}
```
为了简化问题，将指令序号用作指令地址。根据指令条数模4的值来确定下一条指令的地址，其中：
1. 余数为0和2时，下一条指令地址为顺序下一条的地址
2. 余数为1时，下一条指令地址为该指令地址后的任一地址
3. 余数为3时，下一条指令地址为该指令地址前的任一地址

从而实现50%是顺序执行，25%是均匀分布前地址部分，25%是均匀分布后地址部分
#### FIFO算法
```C++
int progress::FIFO_SWAP()
{
    int in_point_min = progress_size;
    int offset = -1;
    for(int i = 0; i < 4; i++){            //选出最早调入的内存块页面
        int in_point = memory_page_vec[i].getInPoint();
        if(in_point < in_point_min){
            in_point_min = in_point;
            offset = i;
        }
    }
    return offset;                          //返回内存块偏移

}
```
根据页面对象的in_point成员变量选出最早调入内存块的页面并将其替换出，该函数返回需要替换的内存块号
#### LRU算法
```C++
int progress::LRU_SWAP()
{
    int last_used_min = progress_size;
    int offset = -1;
    for(int i = 0; i < 4; i++){             //选出最近使用的内存块页面
        int last_used = memory_page_vec[i].getLastUsedPoint();
        if(last_used < last_used_min){
            last_used_min = last_used;
            offset = i;
        }
    }
    return offset;                          //返回内存块偏移

}
```
根据页面对象的last_used_point成员变量选出最近最远被访问内存块的页面并将其替换出，该函数返回需要替换的内存块号
#### RAND算法
```C++
int progress::RAND_SWAP()
{
    return rand()%4;                        //返回随机内存块偏移
}
```
该函数随机返回一个内存块号
### 模拟过程
1. 根据作业对象current_ins成员,计算该指令所在页面，并在内存中搜索该页面号  
    (1)若搜索成功，即指令页面已经调入内存，不发生替换
    (2)若搜索失败，即指令页面不在内存中，需要发生页面调入/替换，其中内存未满时直接顺序调入，内存已满时发生页面替换
2. 将current_ins更新为下一条指令的标识，并更新各项统计数据
3. 重复以上步骤，直到所有（320条）指令执行完成  

### 存在问题
#### 随机指令生成问题  
1. 由于指令生成算法的缺陷，即当指令序号较少时，前地址生成容易陷入循环。
2. 由于指令生成算法的随机性，无法使得所有（320）条指令链接在一起，有部分指令无法执行

#### 算法效果问题
1. FIFO算法和LRU算法的区别无法体现，即对于同一指令序列两种算法的缺页数和缺页率相同，但是两种算法的指令执行过程和页面替换是有明显区别的
2. 分析可知，上述问题的原因其实是内存块数过少以及指令的不满足局部性原理。因为内存块过少，而且指令生成算法中的跳转生成，页面替换频繁发生，虽然替换的页面不同，但是替换数是相同的。
