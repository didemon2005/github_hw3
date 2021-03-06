//
// Created by tapuz_000 on 22/12/2018.
//

#ifndef GITHUB_HW3_TASK_HPP
#define GITHUB_HW3_TASK_HPP

#include "Headers.hpp"

class Task
{
private:
    int start_index;
    int end_index;
    int **curr_table;
    int **next_table;
    int hight;
    int width;
    int* task_counter;
    Semaphore* mutex;
    Semaphore* barrier;
public:
    Task(): start_index(0),end_index(0),curr_table(0),next_table(0),hight(0),width(0),task_counter(0),mutex(NULL),barrier(NULL){}
    Task(int start,int ending,int** curr,int** next,int table_higth,int table_width,int* counter, Semaphore* mutex, Semaphore* barrier)
                            : start_index(start),end_index(ending),curr_table(curr),next_table(next)
                                                            ,hight(table_higth),width(table_width),task_counter(counter),mutex(mutex), barrier(barrier){}
    int getStartIndex(){ return start_index;}
    int getEndIndex(){ return end_index;}
    int getWidth(){ return width;}
    int getHight(){ return hight;}
    int getNumOfRows(){ return end_index-start_index;}
    int** getCurr(){ return curr_table;}
    int** getNext(){ return next_table;}
    void counterDown(){(*task_counter)=(*task_counter)-1;}
    Semaphore* get_mutex(){ return mutex;}
    Semaphore* get_barrier(){ return barrier;}
    int check_counte(){ return *task_counter;}

    Task(const Task& task)= default;
    ~Task() = default;
};


#endif //GITHUB_HW3_TASK_HPP
