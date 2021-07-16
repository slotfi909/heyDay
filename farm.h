#ifndef FARM_H
#define FARM_H
#include "person.h"
#include "Aviculture_back.h"
#include "Dairyfarm_back.h"
#include "Sheepcote_back.h"
#include "silo.h"
#include "storage.h"
#include <QMutex>
#include <fstream>
//using namespace std;
class Farm
{
public:
    Farm(int);
   person0 owner;
   QMutex mymutex;
   Aviculture_back myAvi;
   Dairyfarm_back myDai;
   Sheepcote_back myShe;
   silo mySil;
   storage mySto;
   void write_milk(int shenase ,int tedad,int day);
   int read_milk(int shenase,int day);

};

#endif // FARM_H
