#ifndef ALFALFAFIELD_H
#define ALFALFAFIELD_H
#include <fstream>
using namespace std;
class alfalfaField{ // opens in level 3

int area;
bool isPlowed;
unsigned int plowTime_Start;
unsigned int alfalfaFieldTime;
unsigned int plantTime;
bool isBeingUpgraded;
bool isBeingPlowed;
bool isBeingPlanted;

public:
//constructor
alfalfaField(int shenase);
//functions
int getArea();
    void upgrade(); //
void planting(); //
void harvest(); /// 
void plow();  ///
void checkForUpgrade(); //
void checkForPlow();  //
void update_file();

friend class storage;
friend class silo;
};

#endif // ALFALFAFIELD_H
