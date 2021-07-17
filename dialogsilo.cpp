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

    QPixmap bkgndSil("C:/HeydayLogo/Logo/silo.jpg");
    bkgndSil = bkgndSil.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paletteSil;
    paletteSil.setBrush(QPalette::Window/*Background*/, bkgndSil);
    this->setPalette(paletteSil);


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
if(myfarm->mySil.isBeingUpgraded==false)
    {
    if(myfarm->mySto.getNail()>=myfarm->mySil.getLevel()*2){
     if(myfarm->mySto.getShovel()>=pow(myfarm->mySil.getLevel()*2,2)*100){
         myfarm->mySil.isBeingUpgraded=true;
         QMessageBox::critical(this,"OK","silo is upgrading!");
          myfarm->mySil.upgradeStartTime= myfarm->owner.getDay();
     }

 else{
         QMessageBox::critical(this,"ERROR","can't upgrade silo!\n more shovel is required!");

     }
 }


 //
 else
     QMessageBox::critical(this,"ERROR","can't upgrade silo!\n more nail is required!");
}
else{
    QMessageBox::critical(this,"ERROR","upgrade is in process");

}
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
