#ifndef EXTHREAD_H
#define EXTHREAD_H
#include <time.h>
#include <QThread>
#include<QLabel>
#include <QString>
#include <QFile>
#include "farm.h"
class Exthread :public QThread
{
public:
    Exthread(Farm*);
    void run();
    int get_day();
    void setLabel1(QLabel*L2){L1=L2;}
    void set_Day(int);
    void ExupdateFile(int);
    Farm * farmInEx;
private:
    time_t now;
    int day;
    QLabel * L1;
};

#endif // EXTHREAD_H
