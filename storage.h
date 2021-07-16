#include <time.h>
#include <iostream>
#include <math.h>
#include <stdbool.h>
using namespace std;
class storage{

private:
    int capacity;
    int level;
    int numNail;
    int numAlfalfa ;
    int numShovel ;
    int numEgg; // level 2
    int numMilk; // level 4
    int numFleece; // level 6
    unsigned int upgradeStartTime;
    bool isBeingUpgraded;


public:
storage(int shenaseP);
    int getLevel();
    int getCapacity();
    int getNail();
    int getAlfalfa();
    int getShovel();
    int getEgg();
    int getMilk();
    int getFleece();
    int allMerchandises();
    int addNail(int numAddedNail);
    int addAlfalfa(int numAddedAlfalfa);
    int addShovel(int numAddedShovel);
    int addEgg(int numAddedEgg);
    int addMilk(int numAddedMilk);
    int addFleece(int numAddedFleece);
    void update_file();
    void upgrade(); //
    void checkForUpgrade(); //

};
