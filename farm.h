#ifndef FARM_H
#define FARM_H
#include "person.h"
#include <QMutex>
#include <fstream>
//using namespace std;
class Farm
{
public:
    Farm(int);
   person0 owner;
   QMutex mymutex;
   void write_milk(int shenase ,int tedad,int day);
   int read_milk(int shenase,int day);

};

#endif // FARM_H
