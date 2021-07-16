#ifndef SILO_H
#define SILO_H
#include<storage.h>
class silo{
int capacity;
int numWheat;
int level;
unsigned int siloTime;
bool isBeingUpgraded;
public:
    //constructor
    silo(int shenase);
    int getCapaticy();
    int getNumWheat();
    int getLevel();
    void addWheat(int addedWheatNumber);
void checkForUpgrade(int shenase);
bool isFull();
    friend class storage;
    friend class alfalfaField;
};

#endif // SILO_H
