#include "exthread.h"

Exthread::Exthread()
{
    now=time(0);
    day=0;

}

void Exthread::run()
{
    L1->setText("day : "+QString::number(day));
    while(1){
        time_t later=time(0);
        if(later-now>=4){
            now=later;
            day++;
            L1->setText("day : "+QString::number(day));
        }
    }

}

int Exthread::get_day()
{
    return day;
}

int Exthread::day=0;
