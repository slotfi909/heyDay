#include "dialogstorage.h"
#include "ui_dialogstorage.h"
#include "QMessageBox"
#include "farm.h"

int tmpIds=1,tmpCapacitys=5,tmpLevels=1,tmpNumNails=0,tmpNumAlfalfas=1,tmpNumShovels=1,tmpNumEggs=0,tmpNumMilks=0,tmpNumFleeces=0,tmpUpgrafeStartTimes=0;
bool tmpIsBeingUpgradeds=false;
DialogStorage::~DialogStorage()
{
    delete ui;
}


DialogStorage::DialogStorage(QWidget *parent,Farm *_myfarm) :
    QDialog(parent),
    ui(new Ui::DialogStorage)
{
    ui->setupUi(this);
    //for getting day of player
      myfarm = _myfarm;
      this->setWindowTitle("storage");
      std::ifstream storage1("storage.txt");
      std::ofstream storage2("storage2.txt");
      //order in file
      //tmpCapacity--tmpLevel--tmpNumNail--tmpNumAlfalfa--tmpNumShovel--tmpNumEgg--tmpNumMilk--tmpNumFleece--tmpUpgradeStartTime--isBeingUpgraded

      if ( storage1.peek() == std::ifstream::traits_type::eof() )
          {
               //file is empty
               storage2 << tmpIds << ' ' << tmpLevels << ' ' << tmpNumNails<< ' ' << tmpNumAlfalfas<< ' ' << tmpNumShovels <<' '<<tmpNumEggs <<' '<<tmpNumMilks <<' '<<tmpNumFleeces <<' '<<tmpUpgrafeStartTimes <<' '<<tmpIsBeingUpgradeds << '\n';

               myfarm->mySto.level=tmpLevels;
               myfarm->mySto.numNail=tmpNumNails;
               myfarm->mySto.numAlfalfa=tmpNumAlfalfas;
               myfarm->mySto.numShovel=tmpNumShovels;
               myfarm->mySto.numEgg=tmpNumEggs;
               myfarm->mySto.numMilk=tmpNumMilks;
               myfarm->mySto.numFleece=tmpNumFleeces;
               myfarm->mySto.upgradeStartTime=tmpUpgrafeStartTimes;
               myfarm->mySto.isBeingUpgraded=tmpIsBeingUpgradeds;

               storage2.close();
               storage1.close();
               remove("storage.txt");
               rename("storage2.txt", "storage.txt");
          }

         else {
               //file is not empty
               while (storage1>>tmpIds>>tmpLevels>>tmpNumNails>>tmpNumAlfalfas>>tmpNumShovels>>tmpNumEggs>>tmpNumMilks>>tmpNumFleeces>>tmpUpgrafeStartTimes>>tmpIsBeingUpgradeds )
                {
                    if (tmpIds == myfarm->owner.getShenaseP())
                    {
                        myfarm->mySto.level=tmpLevels;
                        myfarm->mySto.numNail=tmpNumNails;
                        myfarm->mySto.numAlfalfa=tmpNumAlfalfas;
                        myfarm->mySto.numShovel=tmpNumShovels;
                        myfarm->mySto.numEgg=tmpNumEggs;
                        myfarm->mySto.numMilk=tmpNumMilks;
                        myfarm->mySto.numFleece=tmpNumFleeces;
                        myfarm->mySto.upgradeStartTime=tmpUpgrafeStartTimes;
                        myfarm->mySto.isBeingUpgraded=tmpIsBeingUpgradeds;

                      break;
                    }
                 storage1.close();
                 storage2.close();
                 remove("storage2.txt");
               }
            }
      ui->label_2->setText(QString::number(myfarm->mySto.level));
      ui->label_4->setText(QString::number(myfarm->mySto.capacity));
      ui->label_6->setText(QString::number(myfarm->mySto.getShovel()));
      ui->label_8->setText(QString::number(myfarm->mySto.getNail()));
      ui->label_10->setText(QString::number(myfarm->mySto.getAlfalfa()));
      ui->label_12->setText(QString::number(myfarm->mySto.getEgg()));
      ui->label_14->setText(QString::number(myfarm->mySto.getMilk()));
      ui->label_16->setText(QString::number(myfarm->mySto.getFleece()));


}

void DialogStorage::on_pushButton_clicked() // upgrade
{

    if(myfarm->mySto.getNail()>=myfarm->mySto.getLevel()){
        if(myfarm->mySto.getShovel()>=myfarm->mySto.getLevel()-1){
        if(myfarm->owner.getCoin()>=pow(myfarm->mySto.getLevel(),3)*10){
            myfarm->mySto.isBeingUpgraded=true;
            QMessageBox::critical(this,"OK","alfalfa field is upgrading!");
             myfarm->mySto.upgradeStartTime= myfarm->owner.getDay();
        }
        }
    }
    else{
        QMessageBox::critical(this,"ERROR","upgrade can't be done!");

    }

}

int DialogStorage::checkForUpgrade(){
    if(myfarm->mySto.isBeingUpgraded){
       if( myfarm->owner.getDay() - myfarm->mySto.upgradeStartTime>=5){
           myfarm->owner.setExp(myfarm->owner.getExp()+myfarm->mySto.getLevel()*3);
                    myfarm->mySto.setCapacity(ceil(1.5*myfarm->mySto.getCapacity()));

         myfarm->mySto.isBeingUpgraded=false;
         return 1;
   }
    }
    return 0;



}

