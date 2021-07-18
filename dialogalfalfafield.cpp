#include "dialogalfalfafield.h"
#include "ui_dialogalfalfafield.h"
#include "QMessageBox"
#include <QString>
int tmpArea2=4,tmpId2=1;
bool tmpIsPlowed2=false,tmpIsBeingUpgraded2=0,tmpIsBeingPlowed2=0,tmpIsBeingPlanted2=0;
unsigned int tmpPlowStartTime2=0,tmpUpgradeStartTime2=0,tmpPlantStartTime2=0;

DialogAlfalfaField::DialogAlfalfaField(QWidget *parent,Farm *_myfarm) :
    QDialog(parent),
    ui(new Ui::DialogAlfalfaField)
{
    //for getting day of player
    myfarm = _myfarm;
//    if(myfarm->owner.getLevel()>=3){
    if(checkForUpgrade()){
        QMessageBox::information(this,"good News !","alfalfa field upgraded suucessfully");
    }

    ui->setupUi(this);

    this->setWindowTitle("alfalfa Field");


    {

    //background
    QPixmap bkgndAlf("C:/HeydayLogo/Logo/alfalfaback.jpg");
    bkgndAlf = bkgndAlf.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paletteAlf;
    paletteAlf.setBrush(QPalette::Window/*Background*/, bkgndAlf);
    this->setPalette(paletteAlf);
int wAlf=ui->pushButton->width();
int hAlf=ui->pushButton->height();

    //window icon
    setWindowIcon(QIcon("C:/HeydayLogo/Logo/alfalfa.jpg"));


    //upgrade icon
    ui->pushButton->setIcon(QIcon("C:/HeydayLogo/Logo/upgrade2.png"));
    ui->pushButton->setIconSize(QSize(wAlf,hAlf));
    ui->pushButton->setToolTip("upgrade");


    //harvest icon
    ui->pushButton_2->setIcon(QIcon("C:/HeydayLogo/Logo/harvest.png"));
    ui->pushButton_2->setIconSize(QSize(wAlf,hAlf));
    ui->pushButton_2->setToolTip("harvest");


    //planting icon
    ui->pushButton_3->setIcon(QIcon("C:/HeydayLogo/Logo/plant.png"));
    ui->pushButton_3->setIconSize(QSize(wAlf,hAlf));
    ui->pushButton_3->setToolTip("plant");

    //plow icon
    ui->pushButton_4->setIcon(QIcon("C:/HeydayLogo/Logo/plow1.png"));
    ui->pushButton_4->setIconSize(QSize(wAlf,hAlf));
    ui->pushButton_4->setToolTip("plow");
    }


    //ui progressBar setup
      if(myfarm->myAlf.isBeingPlanted == false){
           ui->progressBar->setValue(0);

      }
      else
          {
              ui->progressBar->setValue(( myfarm->owner.getDay() - myfarm->myAlf.plantStartTime ) * 100 / 2);

          }

      if(myfarm->myAlf.isBeingUpgraded == false){
           ui->progressBar_2->setValue(0);
      }
      else{
          ui->progressBar_2->setValue(( myfarm->owner.getDay() - myfarm->myAlf.upgradeStartTime ) * 100 / 2);

      }

      if(myfarm->myAlf.isBeingPlowed == false){
           ui->progressBar_3->setValue(0);
      }
      else{
          ui->progressBar_3->setValue(( myfarm->owner.getDay() - myfarm->myAlf.plowStartTime ) * 100 / 2);

      }




      ui->label_2->setText(QString::number(myfarm->myAlf.getArea()));

//}
//else{
//    QMessageBox::critical(this,"ERROR","least required level is 3!");
//}
}

DialogAlfalfaField::~DialogAlfalfaField()
{
    delete ui;
}



void DialogAlfalfaField::on_pushButton_3_clicked()//plant
{




    if(myfarm->myAlf.isBeingPlanted==false){
        if(!ui->lineEdit->text().isEmpty()){
      if(ui->lineEdit->text().toInt() <= myfarm->myAlf.getArea()){
 if(myfarm->mySto.getAlfalfa() >= ui->lineEdit->text().toInt()){
  myfarm->myAlf.plantStartTime=myfarm->owner.getDay();
   myfarm->myAlf.isBeingPlanted=true;
    QMessageBox::information(this,"OK","the planting has begun");
    myfarm->owner.setExp(myfarm->owner.getExp()+2);
myfarm->mySto.setAlfalfa(myfarm->mySto.getAlfalfa() - ui->lineEdit->text().toInt() );


      }
 //
 else{
          QMessageBox::critical(this,"ERROR","more alafalfa is required:"+QString::number(ui->lineEdit->text().toInt() - myfarm->mySto.getAlfalfa()));
      }
    }



      else{
//     QMessageBox::critical(this,"ERROR","Not enough alfalfa availble!");
          QMessageBox::critical(this,"ERROR","your chosen area must be less than your total area!");

 }
    }
        else{
            QMessageBox::critical(this,"ERROR","input can't be empty!");

        }

    }


    //
    else{
        QMessageBox::critical(this,"OK","the planting is alredy happening");

    }

}


void DialogAlfalfaField::on_pushButton_2_clicked()//harvest
{
    if(myfarm->myAlf.isBeingPlanted==true){
        if(myfarm->owner.getDay() - myfarm->myAlf.plantStartTime >=4){
            myfarm->mySto.addAlfalfa(myfarm->myAlf.getArea()*2);
            QMessageBox::information(this,"OK","harvest is done!");

            myfarm->myAlf.isBeingPlanted=0;
            myfarm->owner.setExp(myfarm->owner.getExp()+2);

        }

        //
        else{
            QMessageBox::critical(this,"ERROR","not enough time has passed!");


    }
    }

    //
    else {
        QMessageBox::critical(this,"ERROR","you must plant first!");

 }
}


void DialogAlfalfaField::on_pushButton_clicked()//upgrade
{

    if(myfarm->myAlf.isBeingUpgraded==false)
    {
    if(myfarm->mySto.getShovel()>=2*myfarm->myAlf.getArea()){
        if(myfarm->owner.getCoin()>=5*myfarm->myAlf.getArea()){
            myfarm->myAlf.isBeingUpgraded=true;
            QMessageBox::information(this,"OK","alfalfa field is upgrading!\nit will takes 3 days to complete!");
             myfarm->myAlf.upgradeStartTime= myfarm->owner.getDay();
             myfarm->owner.changeCoin(-1*5*myfarm->myAlf.getArea());
             myfarm->mySto.addShovel(-1*2*myfarm->myAlf.getArea());
        }
        else{
            QMessageBox::critical(this,"ERROR","upgrade can't be done!\nmore coin is needed:"+QString::number(5*myfarm->myAlf.getArea() - myfarm->owner.getCoin()));

        }


    }

  //
    else{
        QMessageBox::critical(this,"ERROR","upgrade can't be done!\nmore shovel is needed:"+QString::number(2*myfarm->myAlf.getArea() - myfarm->mySto.getShovel()));

    }
}
    else
        QMessageBox::critical(this,"ERROR","upgrade is in process!\nremaining days:"+QString::number(myfarm->myAlf.upgradeStartTime+3 - myfarm->owner.getDay()));

}

int DialogAlfalfaField::checkForUpgrade(){
 if(myfarm->myAlf.isBeingUpgraded){
    if( myfarm->owner.getDay()- myfarm->myAlf.upgradeStartTime>=3){

       myfarm->myAlf.area*=2;

      myfarm->owner.setExp(myfarm->owner.getExp()+3);
      myfarm->myAlf.isBeingUpgraded=false;
      QMessageBox::information(this,"OK","alfalfa field fully upgraded!");
      return 1;
}
 }
 else{
 return 0;
}
}

int DialogAlfalfaField::checkForPlow(){
    if(myfarm->myAlf.isBeingPlowed){
         if( myfarm->owner.getDay()- myfarm->myAlf.upgradeStartTime>=1){
          myfarm->myAlf.isPlowed=true;
          myfarm->myAlf.isBeingPlowed=false;
          QMessageBox::information(this,"OK","alfalfa field fully plowed!");
                    return 1;
         }

    }
 return 0;

}
