#ifndef ALFALFAFIELD_H
#define ALFALFAFIELD_H
#include <storage.h>

class alfalfaField{ // opens in level 3

int area;
bool isPlowed;
unsigned int plowStartTime;
unsigned int upgradeStartTime;
unsigned int plantStartTime;
bool isBeingUpgraded;
bool isBeingPlowed;
bool isBeingPlanted;

public:
//constructor
alfalfaField(int shenaseP);
//functions
int getArea();
void upgrade(); ////
void planting(); //// 
void harvest(); //////
void plow();  //////
void checkForUpgrade(); ///
void checkForPlow(); ////
void update_file();


friend class storage;
friend class silo;
};

#endif // ALFALFAFIELD_H
