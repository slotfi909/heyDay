#include "alfalfaField.h"

//constructor
alfalfaField::alfalfaField(int shenaseP){
        struct temp {
int area;
bool isPlowed;
unsigned int plowTime_Start;
unsigned int alfalfaFieldTime;
unsigned int plantTime;
bool isBeingUpgraded;
bool isBeingPlowed;
bool isBeingPlanted;
};

  temp A;

  ifstream fin;
  ofstream fout;
  fin.open("alfalfaField.txt");
  if (!fin) { // if fin is empty
    fin.close();
    fout.open("alfalfaField.txt");
    fout.close();
    fin.open("alfalfaField.txt", ios::app);
  }
  bool isFirst = 1;
  while (!fin.eof()) {/////////////////////taghir dar hame
    fin.read((char*)&A, sizeof(temp));
    if (A.shenaseP == shenaseP) {
area=A.area;
isPlowed=A.isPlowed;
 plowTime_Start=A.plowTime_Start;
 alfalfaFieldTime=A.alfalfaFieldTime;
 plantTime=A.plantTime;
 isBeingUpgraded=A.isBeingUpgraded;
 isBeingPlowed=A.isBeingPlowed;
 isBeingPlanted=A.isBeingPlanted;
            isFirst=0;
      break;
    }
  }
  fin.close();
  if (isFirst) {    //first login
area=4;
isPlowed=0;
 plowTime_Start=0;
 alfalfaFieldTime=0;
 plantTime=0;
 isBeingUpgraded=0;
 isBeingPlowed=0;
 isBeingPlanted=0;
    //..................
A.area=4;
A.isPlowed=0;
A.plowTime_Start=0;
A.alfalfaFieldTime=0;
A.plantTime=0;
A.isBeingUpgraded=0;
A.isBeingPlowed=0;
A.isBeingPlanted=0;
            A.shenaseP=shenaseP;

    fout.open("alfalfaField.txt",ios::app);
    fout.write((char*)&A, sizeof(temp));
    fout.close();
  }

    }
//functions
int alfalfaField::getArea(){return area;}
void alfalfaField::upgrade(){
    
}
void alfalfaField::planting(){
    
}
void alfalfaField::harvest(){
    
}
void alfalfaField::plow(){}
void alfalfaField::checkForUpgrade(){}
void alfalfaField::checkForPlow(){

}







