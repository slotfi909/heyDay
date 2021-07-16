#include "dialogstorage.h"
#include "ui_dialogstorage.h"
#include "QMessageBox"
#include "farm.h"

int tmpId=1,tmpCapacity=10,tmpLevel=1,tmpNumNail=10,tmpNumAlfalfa=0,tmpNumShovel=1,tmpNumEgg=0,tmpNumMilk=0,tmpNumFleece=0,tmpUpgrafeStartTime=0;
bool tmpIsBeingUpgraded=false;
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
               storage2 << tmpId << ' ' << tmpLevel << ' ' << tmpNumNail<< ' ' << tmpNumAlfalfa<< ' ' << tmpNumShovel <<' '<<tmpNumEgg<<' '<<tmpNumMilk<<' '<<tmpNumFleece<<' '<<tmpUpgrafeStartTime<<' '<<tmpIsBeingUpgraded<< '\n';

               myfarm->mySto.level=tmpLevel;
               myfarm->mySto.numNail=tmpNumNail;
               myfarm->mySto.numAlfalfa=tmpNumAlfalfa;
               myfarm->mySto.numShovel=tmpNumShovel;
               myfarm->mySto.numEgg=tmpNumEgg;
               myfarm->mySto.numMilk=tmpNumMilk;
               myfarm->mySto.numFleece=tmpNumFleece;
               myfarm->mySto.upgradeStartTime=tmpUpgrafeStartTime;
               myfarm->mySto.isBeingUpgraded=tmpIsBeingUpgraded;

               storage2.close();
               storage1.close();
               remove("storage.txt");
               rename("storage2.txt", "storage.txt");
          }

         else {
               //file is not empty
               while (storage1>>tmpId>>tmpLevel>>tmpNumNail>>tmpNumAlfalfa>>tmpNumShovel>>tmpNumEgg>>tmpNumMilk>>tmpNumFleece>>tmpUpgrafeStartTime>>tmpIsBeingUpgraded )
                {
                    if (tmpId == myfarm->owner.getShenaseP())
                    {
                        myfarm->mySto.level=tmpLevel;
                        myfarm->mySto.numNail=tmpNumNail;
                        myfarm->mySto.numAlfalfa=tmpNumAlfalfa;
                        myfarm->mySto.numShovel=tmpNumShovel;
                        myfarm->mySto.numEgg=tmpNumEgg;
                        myfarm->mySto.numMilk=tmpNumMilk;
                        myfarm->mySto.numFleece=tmpNumFleece;
                        myfarm->mySto.upgradeStartTime=tmpUpgrafeStartTime;
                        myfarm->mySto.isBeingUpgraded=tmpIsBeingUpgraded;

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
