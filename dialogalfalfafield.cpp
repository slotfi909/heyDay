#include "dialogalfalfafield.h"
#include "ui_dialogalfalfafield.h"
#include "QMessageBox"

int tmpArea2=4,tmpId2=1;
bool tmpIsPlowed2=false,tmpIsBeingUpgraded2=0,tmpIsBeingPlowed2=0,tmpIsBeingPlanted2=0;
unsigned int tmpPlowStartTime2=0,tmpUpgradeStartTime2=0,tmpPlantStartTime2=0;

DialogAlfalfaField::DialogAlfalfaField(QWidget *parent,Farm *_myfarm) :
    QDialog(parent),
    ui(new Ui::DialogAlfalfaField)
{
    ui->setupUi(this);
    //for getting day of player
    myfarm = _myfarm;
    this->setWindowTitle("alfalfa Field");


    {

    //background
    QPixmap bkgnd("C:/HeydayLogo/Logo/alfalfaback.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window/*Background*/, bkgnd);
    this->setPalette(palette);


    //window icon
    setWindowIcon(QIcon("C:/HeydayLogo/Logo/alfalfa.jpg"));


    //upgrade icon
    ui->pushButton->setIcon(QIcon("C:/HeydayLogo/Logo/upgrade2.png"));
    ui->pushButton->setIconSize(QSize(100, 100));


    //harvest icon
    ui->pushButton_2->setIcon(QIcon("C:/HeydayLogo/Logo/harvest.png"));
    ui->pushButton_2->setIconSize(QSize(100, 100));


    //planting icon
    ui->pushButton_3->setIcon(QIcon("C:/HeydayLogo/Logo/plant.png"));
    ui->pushButton_3->setIconSize(QSize(100, 100));

    //plow icon
    ui->pushButton_4->setIcon(QIcon("C:/HeydayLogo/Logo/plow.png"));
    ui->pushButton_4->setIconSize(QSize(100, 100));

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


}

DialogAlfalfaField::~DialogAlfalfaField()
{
    delete ui;
}



void DialogAlfalfaField::on_pushButton_3_clicked()//plant
{
    if(myfarm->myAlf.isBeingPlanted==false){
      if(ui->lineEdit->text().toInt()>tmpArea2){
 if(myfarm->mySto.getAlfalfa()>ui->lineEdit->text().toInt()){
  myfarm->myAlf.plantStartTime=myfarm->owner.getDay();
   myfarm->myAlf.isBeingPlanted=true;
    QMessageBox::critical(this,"OK","the planting has begun");
    myfarm->owner.setExp(myfarm->owner.getExp()+2);


      }
 //
 else{
//          QMessageBox::critical(this,"ERROR","your chosen area must be less than your total area!");
          QMessageBox::critical(this,"ERROR","Not enough alfalfa availble!");
      }
    }



      else{
//     QMessageBox::critical(this,"ERROR","Not enough alfalfa availble!");
          QMessageBox::critical(this,"ERROR","your chosen area must be less than your total area!");

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
            QMessageBox::critical(this,"OK","harvest is done!");

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
    if(myfarm->mySto.getShovel()>=2*myfarm->myAlf.getArea()){
        if(myfarm->owner.getCoin()>=5*myfarm->myAlf.getArea()){
            myfarm->myAlf.isBeingUpgraded=true;
            QMessageBox::critical(this,"OK","alfalfa field is upgrading!");
             myfarm->myAlf.upgradeStartTime= myfarm->owner.getDay();
        }
        else{
            QMessageBox::critical(this,"ERROR","upgrade can't be done!\nmore coin is needed!");

        }


    }

  //
    else{
        QMessageBox::critical(this,"ERROR","upgrade can't be done!\nmore shovel is needed!");

    }
}

int DialogAlfalfaField::checkForUpgrade(){
 if(myfarm->myAlf.isBeingUpgraded){
    if( myfarm->owner.getDay()- myfarm->myAlf.upgradeStartTime>=3){

       myfarm->myAlf.area*=2;

      myfarm->owner.setExp(myfarm->owner.getExp()+3);
      myfarm->myAlf.isBeingUpgraded=false;
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
          return 1;
         }

    }
 return 0;

}
