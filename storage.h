#ifndef STORAGE_H
#define STORAGE_H

#include <QDialog>
//#include "milk.h"
#include <time.h>
#include <iostream>
//#include <person.h>
#include <math.h>
#include <stdbool.h>
using namespace std;
namespace Ui {
class storage;
}

class storage : public QDialog
{
    Q_OBJECT

public:
    explicit storage(QWidget *parent = nullptr);
    ~storage();
//    void upgrade(person& player);
    int getLevel();
    int getCapacity();
    int allMerchandises();
    void addNail(int numAddedNail);
    void addAlfalfa(int numAddedAlfalfa);
    void addShovel(int numAddedShovel);
    void addEgg(int numAddedEgg);
//    void addMilk(milk AddedMilk);
    void addFleece(int numAddedFleece);
    void checkSpoiledMilk();
    //friends
    friend class alfalfaField;
    friend class silo;

private:
    Ui::storage *ui;
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
//    milk* milklist;
};

#endif // STORAGE_H





