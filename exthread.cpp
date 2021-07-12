#include "exthread.h"

Exthread::Exthread()
{
    now=time(0);

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



void Exthread::set_Day(int shenase){
    struct fileday{
        int shenase;
        int day;
    }temp;

    QFile fp("tedadD.txt");
    fp.open(QIODevice::ReadOnly);
    if (!fp.isOpen()) {
        fp.close();
        fp.open(QIODevice::WriteOnly);
        fp.close();
         fp.open(QIODevice::ReadOnly);
    }
    bool peyda=1;
      while(!fp.atEnd()){
    fp.read((char*)&temp,sizeof(temp));
    if(temp.shenase==shenase){
        day=temp.day;
        peyda=0;
        break;
    }
    }
    fp.close();

    if(peyda){    //first login
        temp.shenase=shenase;
        temp.day=0;
        day=0;
        fp.open(QIODevice::Append);
        fp.write((char*)&temp,sizeof(temp));
        fp.close();
    }
}


void Exthread::ExupdateFile(int shenaseP){
    struct temp{
        int shenaseP;
        int day;
    }p;

    QFile outfile("tedadD-temp.txt");//for writing in new file.
    QFile infile("tedadD.txt");//for reading.

    infile.open(QIODevice::ReadOnly);
     if(infile.isOpen()){
    outfile.open(QIODevice::Append);//make file.

    while(!infile.atEnd()){
           infile.read((char*)&p,sizeof(p));
           if(shenaseP==p.shenaseP){
                   p.day=day;
                   p.shenaseP=shenaseP;

           }
           outfile.write((char*)&p,sizeof(p));
    }
    outfile.close();
    infile.close();
    remove("tedadD.txt");
    rename("tedadD-temp.txt","tedadD.txt");
    }

}

