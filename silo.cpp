#include "silo.h"
#include <math.h>
silo::silo(int shenaseP){
        struct temp {
  int numWheat;
  int capacity;
  int level;
  unsigned int siloTime;
  int shenaseP;
  bool isBeingUpgradede;
};

  temp A;

  ifstream fin;
  ofstream fout;
  fin.open("silo.txt");
  if (!fin) {
    fin.close();
    fout.open("silo.txt");
    fout.close();
    fin.open("silo.txt", ios::app);
  }
  bool find = 1;
  while (!fin.eof()) {/////////////////////taghir dar hame
    fin.read((char*)&A, sizeof(temp));
    if (A.shenaseP == shenaseP) {
      numWheat=A.numWheat;
      capacity = A.capacity;
      level = A.level;
      siloTime=A.siloTime;
      shenaseP = A.shenaseP;
      isBeingUpgrade=A.isBeingUpgradede;
            find=0;
      break;
    }
  }
  fin.close();
  if (find) {    //first login
    numWheat=0;
      capacity = 10;
      level = 1;
      siloTime=0;
      isBeingUpgrade=0;
    //..................
    A.numWheat=0;
      A.capacity = 10;
      A.level = 1;
      A.siloTime=0;
      A.isBeingUpgrade=0;
            A.shenaseP=shenaseP;

    fout.open("silo.txt",ios::app);
    fout.write((char*)&A, sizeof(temp));
    fout.close();
  }

    }
    int silo::getCapaticy(){return capacity;}
    int silo::getNumWheat(){return numWheat;}
    int silo::getLevel(){return level;}
    void silo::addWheat(int addedWheatNumber){
    int freeSpace=capacity-numWheat;
    if(addedWheatNumber<=freeSpace){
        numWheat+=addedWheatNumber;
        // cout<<"added successfully!\n";
    }
    else
        cout<<"not enough space!\n";
    }
void silo::checkForUpgrade(int shenase){
    
}
bool silo::isFull(){
if(numWheat==capacity)
    return true;
else
    return false;
}
