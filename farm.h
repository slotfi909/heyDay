#ifndef FARM_H
#define FARM_H
#include "person.h"
#include <QMutex>
class Farm
{
public:
    Farm(int);
   person0 owner;
   QMutex mymutex;

};

#endif // FARM_H
