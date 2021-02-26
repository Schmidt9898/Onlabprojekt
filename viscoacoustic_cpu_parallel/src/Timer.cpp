#include "Timer.h"
#include <iostream>

float Totaltime=0;
int Sum_Timers=0;
Timer * root=nullptr;

Timer::Timer(){
    Sum_Timers++;
    start = std::chrono::high_resolution_clock::now();};
//Timer::Timer(std::string msg_):msg(msg_){};

Timer::Timer(std::string msg_):msg(msg_)
{
    if(root==nullptr) root=this;
    else {
            parent=root;
            root=this;
            root_num=parent->root_num+1;
            //std::cout<<root_num;
    }
    Sum_Timers++;
    Print_start();
    start = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    Stop();
    Print();
    root=parent;
}


void Timer::Start(){
 start = std::chrono::high_resolution_clock::now();

};
void Timer::Stop(){
    end=std::chrono::high_resolution_clock::now();
    duration = end-start;

    Totaltime+=(parent==nullptr)?duration.count():0;
};
void Timer::Print(){
    for(int i=0;i<root_num;i++)
        std::cout<<"----";
    std::cout<<msg.c_str()<<" took "<<duration.count()<<" sec.\n";
};
void Timer::Print_start(){
    for(int i=0;i<root_num;i++)
        std::cout<<"    ";
    std::cout<<msg.c_str()<<"->\n";
};

void Timer_Print_all(){

    std::cout<<"Total time: "<<Totaltime<<" sec.\n";
    std::cout<<"Number of timers: "<<Sum_Timers<<".\n";

};