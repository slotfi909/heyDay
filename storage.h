#ifndef STORAGE_H
#define STORAGE_H
#include "milk.h"
#include <time.h>
#include <iostream>
#include <person.h>
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
unsigned int storageTime;
bool isBeingUpgraded;
milk* milklist;
public:
// constructor
storage();

// functions
void upgrade(person0& player);
int getLevel();
int getCapacity();
int allMerchandises();
void addNail(int numAddedNail);
void addAlfalfa(int numAddedAlfalfa);
void addShovel(int numAddedShovel);
void addEgg(int numAddedEgg);
void addMilk(milk AddedMilk);
void addFleece(int numAddedFleece);
void checkSpoiledMilk();
//friends
friend class alfalfaField;
friend class silo;
};

#endif // STORAGE_H

