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
    silo();
    void upgrade(person& player,const storage& playerStorage);
    int getCapaticy();
    int getNumWheat();
    int getLevel();
    void addWheat(int addedWheatNumber);
void checkForUpgrade(person& player);
    friend class storage;
    friend class alfalfaField;
};

#endif // SILO_H
