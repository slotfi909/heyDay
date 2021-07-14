#include "silo.h"
#include <math.h>
    silo::silo(){
    numWheat=1;
    capacity=10;
    }
    void silo::upgrade(person& player,const storage& playerStorage){
        bool canGetUpgraded=0;

   if(level<(player.level)-2)
    if(playerStorage.numNail>=2*level)
     if(player.coin>=(pow(2,2*level)*100))
      if(playerStorage.numShovel>=level-2)
         canGetUpgraded=1;

        if(canGetUpgraded){
                cout<<"are you sure?\nenter y for yes and n for no\n";
        char input;
        cin>>input;
        if(input=='n')
            return;
              isBeingUpgraded=1;
              siloTime=time(0);
     cout<<"silo is upgrading(it takes 5 days to complete!)\n";
        }
        else
        cout<<"silo can't upgrade!";

    }
    int silo::getCapaticy(){return capacity;}
    int silo::getNumWheat(){return numWheat;}
    int silo::getLevel(){return level;}
    void silo::addWheat(int addedWheatNumber){
    int freeSpace=capacity-numWheat;
    if(addedWheatNumber<=freeSpace){
        numWheat+=addedWheatNumber;
        cout<<"added successfully!\n";
    }
    else
        cout<<"not enough space!\n";
    }
void silo::checkForUpgrade(person& player){
{
if(isBeingUpgraded){
        if(time(0)>4*24*3600+siloTime){ // 4 days has passed
                  capacity*=2;
              player.exp+=level*2;
              cout <<"storage upgraded successfully!";
/* // needed things must be decreased?
numNail-=2*level;
    player.coin-=(power(2,2*level)*100));
      playerStorage.numShovel-=level-2;
*/

        }
else
    cout <<"not enough time has passed!";
}
else
    cout <<"silo is not upgrading!";

}



}

