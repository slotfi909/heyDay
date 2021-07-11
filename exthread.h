#ifndef EXTHREAD_H
#define EXTHREAD_H
#include <time.h>
#include <QThread>
#include<QLabel>
#include <QString>
#include <QFile>
class Exthread :public QThread
{
public:
    Exthread();
    void run();
    int get_day();
    void setLabel1(QLabel*L2){L1=L2;}
    void set_Day(int);
    void ExupdateFile(int);
private:
    time_t now;
    int day;
    QLabel * L1;
};

#endif // EXTHREAD_H
