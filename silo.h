#ifndef SILO_H
#define SILO_H
#include<storage.h>
class silo{
int capacity;
int numWheat;
int level;
unsigned int upgradeStartTime;
bool isBeingUpgraded;
public:
    //constructor
    silo(int shenaseP);
    int getCapaticy();
    int getNumWheat();
    int getLevel();
    int addWheat(int addedWheatNumber);
    void checkForUpgrade(int shenaseP); // //shenasep mikhad?
    bool isFull();
    friend class storage;
    friend class alfalfaField;
    void update_file();

};

#endif // SILO_H
