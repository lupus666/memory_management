#ifndef PROGRESS_H
#define PROGRESS_H
#include"page.h"

enum Algorithm{
    FIFO,LRU,RAND
};

const static char* Algorithm_array[]={
    "FIFO","LRU","RAND"
};

class progress
{
public:
    progress(unsigned int ins_size = 320, unsigned int p_size = 10);
    void init_ins();                        //指令初始化
    int jump_front(int m);                  //向前随机生成指令算法
    int jump_back(int m);                   //向后随机生成指令算法

    bool search_ins(int address,int &page_pos); //搜索内存，判断当前指令所在页面是否已经调入内存
    int FIFO_SWAP();                        //FIFO替换算法，返回替换的内存块号
    int LRU_SWAP();                         //LRU替换算法，返回替换的内存块号
    int RAND_SWAP();                        //RAND替换算法，返回替换的内存块号

    int single_run(Algorithm ALGORITHM);    //单步执行
    void clear_memory();

    Instruction* getAllInsVec();    //返回作业指令数组
    CPage* getMemoryVec();          //返回内存页面数组，即页目录
    unsigned getPageFault();        //返回缺页错误数
    unsigned getRunTimes();         //返回指令执行次数
    unsigned getMemoryOffset();     //返回内存块偏移
    unsigned getPageOffset();       //返回页内偏移

    unsigned getCurrentIns();       //返回当前指令序号

private:
    CPage* all_page_vec;            //作业页面数组
    CPage* memory_page_vec;         //内存页面数组，即页目录
    Instruction* all_ins_vec;       //作业指令数组

    unsigned int progress_size;     //作业指令数
    unsigned int page_size;         //页面大小，即页面最大指令数
    unsigned int page_number;       //作业页面数

    unsigned int memory_capacity;   //当前内存页面数
    unsigned int current_ins;       //当前指令序号

    unsigned int run_times;         //执行指令次数
    unsigned int page_fault;        //缺页错误数
    unsigned int page_offset;       //页内偏移
    unsigned int memory_offset;     //内存块偏移

};

#endif // PROGRESS_H
