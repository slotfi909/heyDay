#include "silo.h"
#include "ui_silo.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
silo::silo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::silo)
{
    numWheat=1;
    capacity=10;
    level=1;
    ui->setupUi(this);
char tmpstr[3];
    ui->label_2->setText(itoa(this->getLevel(),tmpstr,10));
    ui->label_4->setText(itoa(this->getCapaticy(),tmpstr,10));
    ui->label_6->setText(itoa(this->getNumWheat(),tmpstr,10));


}

silo::~silo()
{
    delete ui;
}



/*
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
    */
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
/*
    void silo::checkForUpgrade(person& player){
{
if(isBeingUpgraded){
        if(time(0)>4*24*3600+siloTime){ // 4 days has passed
                  capacity*=2;
              player.exp+=level*2;
              cout <<"storage upgraded successfully!";


        }
else
    cout <<"not enough time has passed!";
}
else
    cout <<"silo is not upgrading!";

}
*/






