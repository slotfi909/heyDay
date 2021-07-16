#ifndef ALFALFAFIELD_H
#define ALFALFAFIELD_H
#include <fstream>
using namespace std;
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
alfalfaField(int shenaseP=1);
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
friend class DialogAlfalfaField;
};

#endif // ALFALFAFIELD_H
