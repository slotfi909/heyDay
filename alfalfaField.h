#ifndef ALFALFAFIELD_H
#define ALFALFAFIELD_H
#include <storage.h>

class alfalfaField{ // opens in level 3

int area;
bool isPlowed;
unsigned int plowTime_Start;
unsigned int alfalfaFieldTime;
bool isBeingUpgraded;
bool isBeingPlowed;
bool isBeingPlanted;

public:
//constructor
alfalfaField(person player);
//functions
int getArea();
    void upgrade(person& player,storage& playerStorage);
void planting(int chosenArea,person player,storage& playerStorage);
void harvest(storage& playerStorage);
void plow();
void checkForUpgrade(person& player);
friend class storage;
friend class silo;
};

#endif // ALFALFAFIELD_H
