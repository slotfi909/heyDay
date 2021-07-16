#include <time.h>
#include <iostream>
#include <math.h>
#include <stdbool.h>
#include <fstream>

using namespace std;

class storage1{

private:
    int capacity;
    int level;
    int numNail;
    int numAlfalfa ;
    int numShovel ;
    int numEgg; // level 2
    int numMilk; // level 4
    int numFleece; // level 6
    unsigned int storageTime;
    bool isBeingUpgraded;


public:
storage1(int shenase);
~storage1();
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



};
