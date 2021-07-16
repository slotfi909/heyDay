#include "wheatland2.h"
#include "ui_wheatland2.h"
#include <QMessageBox>
#include <fstream>



bool endOfFarming = false;
int tmpId = 1, tmpArea = 5, tmpIsKeshting = 0, tmpAmountKeshting = 0, thisDay = 0, tmpday = 0, startDayFarming = 0;


wheatland2::wheatland2(QWidget *parent, Farm * _myfarm) :
    QDialog(parent),
    ui(new Ui::wheatland2)
{
    ui->setupUi(this);

    //for getting day of player
    myfarm = _myfarm;


    this->setWindowTitle("Wheat Land");


    //background
    QPixmap bkgnd("C:/HeydayLogo/Logo/wheatlandback.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window/*Background*/, bkgnd);
    this->setPalette(palette);


    //window icon
    setWindowIcon(QIcon("C:/HeydayLogo/Logo/wheat2.jpg"));


    //upgrade icon
    ui->upGrade->setIcon(QIcon("C:/HeydayLogo/Logo/upgrade2.png"));
    ui->upGrade->setIconSize(QSize(100, 100));


    //harvest icon
    ui->bardasht->setIcon(QIcon("C:/HeydayLogo/Logo/harvest.png"));
    ui->bardasht->setIconSize(QSize(100, 100));


    //planting icon
    ui->kesht->setIcon(QIcon("C:/HeydayLogo/Logo/plant.png"));
    ui->kesht->setIconSize(QSize(100, 100));


    //setting data with opening the wheatland file
          std::ifstream wheat("wheat.txt");
          std::ofstream wheat2("Wheat2.txt");
          if ( wheat.peek() == std::ifstream::traits_type::eof() )
          {
               //file is empty
               wheat2 << tmpId << ' ' << tmpArea << ' ' << tmpIsKeshting<< ' ' << tmpAmountKeshting<< ' ' << startDayFarming << '\n';
               myfarm->myWheatLandBack.setArea( tmpArea );
               myfarm->myWheatLandBack.setIsKeshting(tmpIsKeshting);
               myfarm->myWheatLandBack.setKeshtAmount( tmpAmountKeshting );
               myfarm->myWheatLandBack.setStartDay( startDayFarming );
               wheat2.close();
               wheat.close();
               remove("wheat.txt");
               rename("wheat2.txt", "wheat.txt");
          }
          else {
             //file is not empty
             while (wheat >> tmpId >> tmpArea >> tmpIsKeshting >> tmpAmountKeshting >> startDayFarming )
              {
                  if (tmpId == myfarm->owner.getShenaseP())
                  {
                      myfarm->myWheatLandBack.setArea( tmpArea );
                      myfarm->myWheatLandBack.setIsKeshting(tmpIsKeshting);
                      myfarm->myWheatLandBack.setKeshtAmount( tmpAmountKeshting );
                      myfarm->myWheatLandBack.setStartDay( startDayFarming );
                    break;
                  }
               wheat.close();
               wheat2.close();
               remove("wheat2.txt");
             }
          }

      //ui progressBar setup
      if(myfarm->myWheatLandBack.getIsKeshting() == false)
      {
          ui->progressBar->setValue(0);
          endOfFarming = true;
      }
      else
      {
          ui->progressBar->setValue(( myfarm->owner.getDay() - myfarm->myWheatLandBack.getKeshtStartDay() ) * 100 / 2);

          if( ( ( myfarm->owner.getDay() - myfarm->myWheatLandBack.getKeshtStartDay() ) * 100 / 2 ) >= 100){
              endOfFarming = true;
          }
          else{
              endOfFarming = false;
          }
      }


        //ui area display
        ui->AreaLabel->setText(QString::number(myfarm->myWheatLandBack.getArea()));


}

wheatland2::~wheatland2()
{
    delete ui;
}

void wheatland2::on_kesht_clicked()
{
    //check if we have enough wheat in silo
    int ans = 1;
    //if(myfarm->mySil->getwheat() < _keshtAmount)
       //ans = 0;
    //else
       //ans = 1;


    //enough wheat is availble
    if (ans == 1)
      {
       if( myfarm->myWheatLandBack.getIsKeshting() == false )
        {
          if ( ui->keshtSize->text().toInt() > myfarm->myWheatLandBack.getArea() )
              QMessageBox::critical(this,"ERROR","Not enough space availble!");
          else if( ui->keshtSize->text().isEmpty() )
              QMessageBox::critical(this,"ERROR","LineEdit can not be Empty!");
          else{
              keshtUpDate(ui->keshtSize->text().toInt());
              endOfFarming = false;
              QMessageBox::information(this,"DONE","Farming has begone!");
              }
        }
        else
         {
            QMessageBox::critical(this,"ERROR","Farming is already in progress!");
         }
    }
    else{
            QMessageBox::critical(this,"ERROR","Not enouph wheat is availble in silo!");
    }

}


void wheatland2::on_bardasht_clicked()
{
    if( myfarm->myWheatLandBack.getIsKeshting() == true )
    {
       if( myfarm->owner.getDay() - myfarm->myWheatLandBack.getKeshtStartDay() >= 2 )
       {
           //add wealth to garner and update file
           //myfarm->mySil->setWheat( myfarm->mySilo->getwheat() + myfarm->myWheatLandBack->getAmount() );
             myfarm->myWheatLandBack.setIsKeshting(false);
       }
    }
    else if( myfarm->myWheatLandBack.getIsKeshting() == false ){
        QMessageBox::critical(this,"ERROR","You must farm first!");
    }
    else{
        QMessageBox::critical(this,"ERROR","Sorry,but you must wait!");
    }
}


void wheatland2::on_upGrade_clicked()
{
    if(myfarm->owner.getCoin() > 5 && myfarm->owner.getLevel() > 1)
    {
        myfarm->myWheatLandBack.upGrade(myfarm->owner.getDay());
    }
    else{
        QMessageBox::critical(this,"ERROR","You can not do that right now!");
    }
}


void wheatland2::keshtUpDate(int _keshtAmount) {

    myfarm->myWheatLandBack.setIsKeshting(true);

    myfarm->myWheatLandBack.setKeshtAmount(_keshtAmount);

    myfarm->myWheatLandBack.setStartDay(myfarm->owner.getDay());


    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheat.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsKeshting2 = 0, tmpAmountKeshting2 = 0, tmpdayFarmStart = 0 ;
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsKeshting2 >> tmpAmountKeshting2 >> tmpdayFarmStart )
    {
        if (myfarm->owner.getShenaseP() == tmpId2)
        {
            tmpIsKeshting2 = 1;

            tmpAmountKeshting2 = _keshtAmount;

            tmpdayFarmStart = myfarm->owner.getDay();

            break;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsKeshting2 << ' ' << tmpAmountKeshting2 << ' ' << tmpdayFarmStart << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");

}
