#include "dialogsilo.h"
#include "ui_dialogsilo.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include "QMessageBox"

int tmpId1=1,tmpCapacity1=10,tmpNumWheat1=1,tmpLevel1=1,tmpUpgradeStartTime1=0;
        bool tmpIsBeingUpgraded1=0;

using namespace std;
DialogSilo::DialogSilo(QWidget *parent,Farm *_myfarm) :
    QDialog(parent),
    ui(new Ui::DialogSilo)
{

    ui->setupUi(this);

    //for getting day of player
    myfarm = _myfarm;
    this->setWindowTitle("silo");

   // std::ifstream silo1("silo.txt");
    //std::ofstream silo2("silo2.txt");

    //tmpId1--tmpCapacity1--tmpNumWheat1--tmpLevel1--tmpUpgradeStartTime1--isBeingUpgraded
       /* if ( silo1.peek() == std::ifstream::traits_type::eof() )
         {
              //file is empty
              silo2 << tmpId1 << ' ' << tmpCapacity1 << ' ' << tmpNumWheat1<< ' ' << tmpLevel1<< ' ' << tmpUpgradeStartTime1 <<' '<<tmpIsBeingUpgraded1<<'\n';

              myfarm->mySil.capacity=tmpCapacity1;
              myfarm->mySil.numWheat=tmpNumWheat1;
              myfarm->mySil.level=tmpLevel1;
              myfarm->mySil.upgradeStartTime=tmpUpgradeStartTime1;
              myfarm->mySil.isBeingUpgraded=tmpIsBeingUpgraded1;


              silo2.close();
              silo1.close();
              remove("silo.txt");
              rename("silo2.txt", "silo.txt");
         }

        else {
              //file is not empty
              while (silo1>>tmpId1>>tmpCapacity1>>tmpNumWheat1>>tmpLevel1>>tmpUpgradeStartTime1>>tmpIsBeingUpgraded1)
               {
                   if (tmpId1 == myfarm->owner.getShenaseP())
                   {

                       myfarm->mySil.capacity=tmpCapacity1;
                       myfarm->mySil.numWheat=tmpNumWheat1;
                       myfarm->mySil.level=tmpLevel1;
                       myfarm->mySil.upgradeStartTime=tmpUpgradeStartTime1;
                       myfarm->mySil.isBeingUpgraded=tmpIsBeingUpgraded1;



                     break;
                   }
                silo1.close();
                silo2.close();
                remove("silo2.txt");
              }
           }*/

        ui->label_2->setText(QString::number(myfarm->mySil.level));
        ui->label_4->setText(QString::number(myfarm->mySil.capacity));
        ui->label_6->setText(QString::number(myfarm->mySil.numWheat));


}

DialogSilo::~DialogSilo()
{
    delete ui;
}

void DialogSilo::on_pushButton_clicked()// upgrade
{
 if(myfarm->mySto.getNail()>=myfarm->mySil.getLevel()*2){
     if(myfarm->mySto.getShovel()>=pow(myfarm->mySil.getLevel()*2,2)*100){
         myfarm->mySil.isBeingUpgraded=true;
         QMessageBox::critical(this,"OK","silo is upgrading!");
          myfarm->mySil.upgradeStartTime= myfarm->owner.getDay();
     }
 }
    else
     QMessageBox::critical(this,"ERROR","can't upgrade silo!");


}

int DialogSilo::checkForUpgrade(){

    if(myfarm->mySil.isBeingUpgraded){
       if( myfarm->owner.getDay()-myfarm->mySil.upgradeStartTime>=4){

         myfarm->mySil.capacity*=2;

         myfarm->owner.setExp(myfarm->owner.getExp()+(myfarm->mySil.getLevel())*2);
         return 1;
         myfarm->mySil.isBeingUpgraded=false;
   }
    }
    return 0;

}
