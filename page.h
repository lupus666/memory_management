#ifndef PAGE_H
#define PAGE_H
#include<QString>
#include<vector>

struct Instruction{
    int current_address;        //指令地址及指令序号
    QString content;            //指令内容
    int next_address;           //下一条指令地址及指令序号
    Instruction(int current = -1, int next = -1, QString str = "DO SOMETHING"):current_address(current), content(str), next_address(next){}
};

class CPage{
private:
    int last_used_point;        //页面最近使用的时间，用运行周期来记录
    int in_point;               //页面调入内存的时间，用运行周期来记录
    Instruction* ins_vec;       //指令数组
    unsigned int page_size;     //页面大小，默认值为10
    int page_id;                //页面标识
public:
    CPage(unsigned int size = 10){  //构造函数
        page_size = size;
        ins_vec = new Instruction[page_size];
    }
    void setInPoint(int x);         //设置调入时间
    int getInPoint();               //返回调入时间
    void setLastUsedPoint(int x);   //设置最近使用时间
    int getLastUsedPoint();         //返回最近使用时间
    void setPageId(int x);          //设置页面标识
    int getPageId();                //返回页面标识

    Instruction& operator[](unsigned int offset);   //[]操作符的重载
};

#endif // PAGE_H
