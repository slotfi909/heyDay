#include "storage.h"
storage::~storage()
{

}
int storage::getLevel(){return level;}
int storage::getCapacity(){return capacity;}
int storage::allMerchandises(){
return (numNail+numFleece+numEgg+numMilk+numShovel+numAlfalfa);
}
int storage::addNail(int numAddedNail){
        if(numAddedNail+allMerchandises()<=capacity){
           numNail+=numAddedNail;
           return 1;
        }

       return 0;
    }

    int storage::addAlfalfa(int numAddedAlfalfa){
        if(numAddedAlfalfa+allMerchandises()<=capacity){

    numAlfalfa+=numAddedAlfalfa;
    return 1;
        }
return 0;

    }

    int storage::addShovel(int numAddedShovel){
      if(numAddedShovel+allMerchandises()<=capacity){
            numShovel+=numAddedShovel;
return 1;

}
return 0;
    }

    int storage::addEgg(int numAddedEgg){
    if(numAddedEgg+allMerchandises()<=capacity){
    if(level>=2){
    numEgg+=numAddedEgg;
    return 1;
    }
    }
return 0;



    }

    int storage::addFleece(int numAddedFleece){
      if(numAddedFleece+allMerchandises()<=capacity){

  if(level>=6){
    numFleece+=numAddedFleece;
    return 1;
  }

      }
return 0;


}




storage::storage(int shenaseP){
            struct temp {
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
    int shenaseP;

};
 temp A;

  ifstream fin;
  ofstream fout;
  fin.open("storage.txt");
    if (!fin) { // if fin is empty
    fin.close();
    fout.open("storage.txt");
    fout.close();
    fin.open("storage.txt", ios::app);
  }
  bool isFirst = 1;

 while (!fin.eof()) {
    fin.read((char*)&A, sizeof(temp));
    if (A.shenaseP == shenaseP) {
            //////////////
            capacity=A.capacity;
            level=A.level;
            numNail=A.numNail;
            numAlfalfa=A.numAlfalfa;
            numShovel=A.numShovel;
            numEgg=A.numEgg;
            numMilk=A.numMilk;
            numFleece=A.numFleece;
            storageTime=A.storageTime;
            isBeingUpgraded=A.isBeingUpgraded;
            shenaseP=A.shenaseP;
            isFirst=0;
      break;
    }
  }

 if (isFirst) {    //first login
    capacity=5;
    level=1;
    numNail=1;
    numAlfalfa=1 ;
    numShovel=0;
    numEgg=0; // level 2
    numMilk=0; // level 4
    numFleece=0; // level 6
    storageTime=0;
    isBeingUpgraded=0;
//....................................
    A.capacity=5;
    A.level=1;
    A.numNail=1;
    A.numAlfalfa=1 ;
    A.numShovel=0;
    A.numEgg=0; // level 2
    A.numMilk=0; // level 4
    A.numFleece=0; // level 6
    A.storageTime=0;
    A.isBeingUpgraded=0;
    A.shenaseP=shenaseP;

    fout.open("storage.txt",ios::app);
    fout.write((char*)&A, sizeof(temp));
    fout.close();
    
  }
    
    
}

    int storage::getNail(){return numNail;}
    int storage::getAlfalfa(){return numAlfalfa;}
    int storage::getShovel(){return numShovel;}
    int storage::getEgg(){return numEgg;}
    int storage::getMilk(){return numMilk;}
    int storage::getFleece(){return numFleece;}
