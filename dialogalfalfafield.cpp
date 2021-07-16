#include "dialogalfalfafield.h"
#include "ui_dialogalfalfafield.h"
#include "QMessageBox"

int tmpArea=4,tmpId=1;
bool tmpIsPlowed=false,tmpIsBeingUpgraded=0,tmpIsBeingPlowed=0,tmpIsBeingPlanted=0;
unsigned int tmpPlowStartTime=0,tmpUpgradeStartTime=0,tmpPlantStartTime=0;

DialogAlfalfaField::DialogAlfalfaField(QWidget *parent,Farm *_myfarm) :
    QDialog(parent),
    ui(new Ui::DialogAlfalfaField)
{
    ui->setupUi(this);
    //for getting day of player
    myfarm = _myfarm;
    this->setWindowTitle("alfalfa Field");
    std::ifstream alfalfaField1("alfalfaField.txt");
    std::ofstream alfalfaField2("alfalfaField2.txt");
    //order in file
//    id--area--isplowed--isbeingplowed--isbeingupgraded--isbeingplanted--plowstarttime--upgradestarttime--plantstarttime
    if ( alfalfaField1.peek() == std::ifstream::traits_type::eof() )
     {
          //file is empty
          alfalfaField2 << tmpId << ' ' << tmpIsPlowed << ' ' << tmpIsBeingPlowed<< ' ' << tmpIsBeingUpgraded<< ' ' << tmpIsBeingPlanted <<' '<<tmpPlowStartTime<<' '<<tmpUpgradeStartTime<<' '<<tmpPlantStartTime<< '\n';
          myfarm->myAlf.area= tmpArea ;
          myfarm->myAlf.isPlowed= tmpIsPlowed ;
          myfarm->myAlf.isBeingPlowed= tmpIsBeingPlowed ;
          myfarm->myAlf.isBeingUpgraded= tmpIsBeingUpgraded ;
          myfarm->myAlf.isBeingPlanted= tmpIsBeingPlanted ;
          myfarm->myAlf.plowStartTime= tmpPlowStartTime ;
          myfarm->myAlf.upgradeStartTime= tmpUpgradeStartTime ;
          myfarm->myAlf.plantStartTime= tmpPlantStartTime ;


          alfalfaField2.close();
          alfalfaField1.close();
          remove("alfalfaField.txt");
          rename("alfalfaField2.txt", "alfalfaField.txt");
     }

    else {
          //file is not empty
          while (alfalfaField1>>tmpId>>tmpIsPlowed>>tmpIsBeingPlowed>>tmpIsBeingUpgraded>>tmpIsBeingPlanted>>tmpPlowStartTime>>tmpUpgradeStartTime>>tmpPlantStartTime )
           {
               if (tmpId == myfarm->owner.getShenaseP())
               {
                   myfarm->myAlf.area= tmpArea ;
                   myfarm->myAlf.isPlowed= tmpIsPlowed ;
                   myfarm->myAlf.isBeingPlowed= tmpIsBeingPlowed ;
                   myfarm->myAlf.isBeingUpgraded= tmpIsBeingUpgraded ;
                   myfarm->myAlf.isBeingPlanted= tmpIsBeingPlanted ;
                   myfarm->myAlf.plowStartTime= tmpPlowStartTime ;
                   myfarm->myAlf.upgradeStartTime= tmpUpgradeStartTime ;
                   myfarm->myAlf.plantStartTime= tmpPlantStartTime ;

                 break;
               }
            alfalfaField1.close();
            alfalfaField2.close();
            remove("alfalfaField2.txt");
          }
       }

    //ui progressBar setup
      if(myfarm->myAlf.isBeingPlanted == false){
           ui->progressBar->setValue(0);

      }
      else
          {
              ui->progressBar->setValue(( myfarm->owner.getDay() - myfarm->myAlf.plantStartTime ) * 100 / 2);

          }
ui->label_2->setText(QString::number(myfarm->myAlf.getArea()));


}

DialogAlfalfaField::~DialogAlfalfaField()
{
    delete ui;
}



void DialogAlfalfaField::on_pushButton_3_clicked()//plant
{
    if(myfarm->myAlf.isBeingPlanted==false){
 if(myfarm->mySto.getAlfalfa()>tmpArea){
  myfarm->myAlf.plantStartTime=myfarm->owner.getDay();
   myfarm->myAlf.isBeingPlanted=true;
    QMessageBox::critical(this,"OK","the planting has begun");
    myfarm->owner.setExp(myfarm->owner.getExp()+2);

 }
     else{
     QMessageBox::critical(this,"ERROR","Not enough alfalfa availble!");

 }
    }
    else{
        QMessageBox::critical(this,"OK","the planting is alredy happening");

    }

}


void DialogAlfalfaField::on_pushButton_2_clicked()//harvest
{
    if(myfarm->myAlf.isBeingPlanted==true){
        if(myfarm->owner.getDay() - myfarm->myAlf.plantStartTime >4){
            myfarm->mySto.addAlfalfa(myfarm->myAlf.getArea()*2);
            QMessageBox::critical(this,"OK","harvest is done!");

            myfarm->myAlf.isBeingPlanted=0;
            myfarm->owner.setExp(myfarm->owner.getExp()+2);

        }
 else{
            QMessageBox::critical(this,"ERROR","not enough time has passed!");


    }
    }
    else {
        QMessageBox::critical(this,"ERROR","you must plant first!");

 }
}


void DialogAlfalfaField::on_pushButton_clicked()//upgrade
{
    if(myfarm->mySto.getShovel()>=2*myfarm->myAlf.getArea()){
        if(myfarm->owner.getCoin()>=5*myfarm->myAlf.getArea()){
            myfarm->myAlf.isBeingUpgraded=true;
            QMessageBox::critical(this,"OK","alfalfa field is upgrading!");
             myfarm->myAlf.upgradeStartTime= myfarm->owner.getDay();
        }
    }
    else{
        QMessageBox::critical(this,"ERROR","upgrade can't be done!");

    }
}

int DialogAlfalfaField::checkForUpgrade(){
 if(myfarm->myAlf.isBeingUpgraded){
    if( myfarm->owner.getDay()-myfarm->myAlf.upgradeStartTime>=3){

       myfarm->myAlf.area*=2;

      myfarm->owner.setExp(myfarm->owner.getExp()+3);
      myfarm->myAlf.isBeingUpgraded=false;
      return 1;
}
 }
 return 0;

}

int DialogAlfalfaField::checkForPlow(){
    if(myfarm->myAlf.isBeingPlowed){
         if( myfarm->owner.getDay()-myfarm->myAlf.upgradeStartTime>=1){
          myfarm->myAlf.isPlowed=true;
          myfarm->myAlf.isBeingPlowed=false;
          return 1;
         }

    }
 return 0;

}
