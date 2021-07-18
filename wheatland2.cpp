#include "wheatland2.h"
#include "ui_wheatland2.h"
#include <QMessageBox>
#include <fstream>


bool endOfFarming = false;


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
    palette.setBrush(QPalette::Window, bkgnd);
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

      //ui progressBar setup
      if(myfarm->myWhe.getIsKeshting() == false)
      {
          ui->progressBar->setValue(0);
          endOfFarming = true;
      }
      else
      {
          ui->progressBar->setValue(( myfarm->owner.getDay() - myfarm->myWhe.getKeshtStartDay() ) * 100 / 2);

          if( ( ( myfarm->owner.getDay() - myfarm->myWhe.getKeshtStartDay() ) * 100 / 2 ) >= 100){
              endOfFarming = true;
          }
          else{
              endOfFarming = false;
          }
      }


        //ui area display
       int tmp = myfarm->myWhe.getArea();
        ui->AreaLabel->setText(QString::number(myfarm->myWhe.getArea()));


}

wheatland2::~wheatland2()
{
    delete ui;
}

void wheatland2::on_kesht_clicked()
{
    //check if we have enough wheat in silo
    int ans = 1;
    if(myfarm->mySil.getNumWheat() < ui->keshtSize->text().toInt())
       ans = 0;
    else
       ans = 1;

    //enough wheat is availble
    if (ans == 1)
      {
       if( myfarm->myWhe.getIsKeshting() == false )
        {
          if ( ui->keshtSize->text().toInt() > myfarm->myWhe.getArea() )
              QMessageBox::critical(this,"ERROR","Not enough space availble!");
          else if( ui->keshtSize->text().isEmpty() )
              QMessageBox::critical(this,"ERROR","LineEdit can not be Empty!");
          else{
              myfarm->mySil.addWheat(-myfarm->mySil.getNumWheat());
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
    if( myfarm->myWhe.getIsKeshting() == true )
    {
       if( myfarm->owner.getDay() - myfarm->myWhe.getKeshtStartDay() >= 2 )
       {
           //add wealth to garner and update file
            myfarm->mySil.addWheat( myfarm->myWhe.getAmount() * 2);
            myfarm->myWhe.setIsKeshting(false);
            myfarm->myWhe.setStartDay(0);
            myfarm->myWhe.setKeshtAmount(0);
            ui->progressBar->setValue(0);
            QMessageBox::information(this,"info","wheat added to silo!");
       }
    }
    else if( myfarm->myWhe.getIsKeshting() == false ){
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
       int ans = myfarm->myWhe.upGrade(myfarm->owner.getDay());
       if(ans == 0)
            QMessageBox::critical(this,"ERROR","Upgrade already in progress!!!");
       else
            QMessageBox::information(this,"info","Upgrade strated successfully!");
    }
    else{
        QMessageBox::critical(this,"ERROR","You can not do that right now!");
    }
}

//upDate kesht file
void wheatland2::keshtUpDate(int _keshtAmount) {


    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheat.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsKeshting2 = 0, tmpAmountKeshting2 = 0, tmpdayFarmStart = 0 , tmpIsupgrading = 0 ,tmpStartDauUpgrading = 0;
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsKeshting2 >> tmpAmountKeshting2 >> tmpdayFarmStart >> tmpIsupgrading >> tmpStartDauUpgrading)
    {
        if (myfarm->owner.getShenaseP() == tmpId2)
        {
            tmpIsKeshting2 = 1;

            tmpAmountKeshting2 = _keshtAmount;

            tmpdayFarmStart = myfarm->owner.getDay();
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsKeshting2 << ' ' << tmpAmountKeshting2 << ' ' << tmpdayFarmStart << ' ' << tmpIsupgrading << ' ' << tmpStartDauUpgrading << ' ' <<'\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");


    myfarm->myWhe.setIsKeshting(true);

    myfarm->myWhe.setKeshtAmount(_keshtAmount);

    myfarm->myWhe.setStartDay(myfarm->owner.getDay());

}
