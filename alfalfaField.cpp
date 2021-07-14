#include "alfalfaField.h"

//constructor
alfalfaField::alfalfaField(person player){
    if(player.level>=3)
area=4;
else
    area=0;
isPlowed=0;
isBeingPlowed=0;
isBeingUpgraded=0;
isBeingPlanted=0;
}
//functions
int alfalfaField::getArea(){return area;}
void alfalfaField::upgrade(person& player,storage& playerStorage){
        bool canGetUpgraded=0;

   if(player.level>=4)
    if(playerStorage.numShovel>=2*area)
     if(player.coin>=5*area)
         canGetUpgraded=1;
        if(canGetUpgraded){
                cout<<"are you sure?\nenter y for yes and n for no\n";
        char input;
        cin>>input;
        if(input=='n')
            return;
   alfalfaFieldTime=time(0);
   isBeingUpgraded=1;
        cout<<"alfalfaField is upgrading!";

        }
        else
        cout<<"alfalfaField didn't upgrade!";

    }
void alfalfaField::planting(int chosenArea,person player,storage& playerStorage){
playerStorage.numAlfalfa-=chosenArea;
}
void alfalfaField::harvest(storage& playerStorage){
int freeSpace=playerStorage.capacity-playerStorage.allMerchandises();

}
void alfalfaField::plow(){
isPlowed=true;
}
void alfalfaField::checkForUpgrade(person& player){
if(isBeingUpgraded){
        if(time(0)>3*24*3600+alfalfaFieldTime){ // 3 days has passed
                  area*=2;
              player.exp+=area*3;
              cout <<"storage upgraded successfully!";
        }
        else
            cout <<"not enough time has passed!";

}
else
    cout <<"silo is not upgrading!";

}







