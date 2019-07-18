#include "progress.h"
#include <stdlib.h>
#include<time.h>

progress::progress(unsigned int ins_size, unsigned int p_size)
{
    progress_size = ins_size;
    page_size = p_size;
    page_number = progress_size/page_size;

    current_ins = 0;
    memory_capacity = 0;
    run_times = 0;
    page_fault = 0;
    page_offset = 0;
    memory_offset = 0;

    all_ins_vec = new Instruction[progress_size];
    all_page_vec = new CPage[page_number];
    memory_page_vec = new CPage[4];


    init_ins();
}

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
    for(int i = 0; i<page_number; i++){             //指令分配页面
        CPage page_temp(page_size);
        page_temp.setPageId(i);
        for(int j = 0; j<page_size; j++){
            page_temp[j] = all_ins_vec[i*10 + j];
        }

        all_page_vec[i] = page_temp;
    }
}

int progress::jump_front(int m)
{
    srand((unsigned)time(NULL));
    return rand()%m;
}

int progress::jump_back(int m)
{
    srand((unsigned)time(NULL));
    return rand()%(progress_size - m) + m;
}

bool progress::search_ins(int address, int &page_pos)
{
    int belong_page_id = address/page_size;
    for(int i = 0; i < memory_capacity;i++){
        if(belong_page_id == memory_page_vec[i].getPageId()){
            page_pos = i;
            return true;
        }
    }
    page_pos = -1;
    return false;
}

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

int progress::RAND_SWAP()
{
    return rand()%4;                        //返回随机内存块偏移
}

int progress::single_run(Algorithm ALGORITHM)
{
    run_times +=1;
    Instruction ins_temp = all_ins_vec[current_ins];

    page_offset = current_ins%page_size;

    int page_id = current_ins/page_size;

    int page_pos;
    if(search_ins(current_ins,page_pos) == true){
        memory_offset = page_pos;
        memory_page_vec[page_pos].setLastUsedPoint(run_times);
        current_ins = ins_temp.next_address;
        return -1;
    }
    else{
        if(memory_capacity < 4){
            memory_page_vec[memory_capacity] = all_page_vec[page_id];
            memory_page_vec[memory_capacity].setInPoint(run_times);
            memory_page_vec[memory_capacity].setLastUsedPoint(run_times);
            memory_capacity +=1;

            memory_offset =memory_capacity - 1;
        }
        else if(ALGORITHM == FIFO){
            memory_offset = FIFO_SWAP();
            memory_page_vec[memory_offset] = all_page_vec[page_id];
            memory_page_vec[memory_offset].setInPoint(run_times);
            memory_page_vec[memory_offset].setLastUsedPoint(run_times);
        }
        else if(ALGORITHM == LRU){
            memory_offset = LRU_SWAP();
            memory_page_vec[memory_offset] = all_page_vec[page_id];
            memory_page_vec[memory_offset].setInPoint(run_times);
            memory_page_vec[memory_offset].setLastUsedPoint(run_times);
        }
        else{
            memory_offset = RAND_SWAP();
            memory_page_vec[memory_offset] = all_page_vec[page_id];
            memory_page_vec[memory_offset].setInPoint(run_times);
            memory_page_vec[memory_offset].setLastUsedPoint(run_times);
        }
        page_fault += 1;
        current_ins = ins_temp.next_address;
        return memory_offset;
    }
}

void progress::clear_memory()
{
    for(int i = 0;i < memory_capacity;i++){
        memory_page_vec[i] = NULL;
    }
    current_ins = 0;
    memory_capacity = 0;
    run_times = 0;
    page_fault = 0;
    page_offset = 0;
    memory_offset = 0;
}

Instruction *progress::getAllInsVec()
{
    return all_ins_vec;
}

CPage *progress::getMemoryVec()
{
    return memory_page_vec;
}

unsigned progress::getPageFault()
{
    return page_fault;
}

unsigned progress::getRunTimes()
{
    return run_times;
}

unsigned progress::getMemoryOffset()
{
    return memory_offset;
}

unsigned progress::getPageOffset()
{
    return page_offset;
}

unsigned progress::getCurrentIns()
{
    return current_ins;
}
