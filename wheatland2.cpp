#include "wheatland2.h"
#include "ui_wheatland2.h"
#include <person.h>
#include <QMessageBox>
#include <fstream>
using namespace std;

person0* player;
bool endOfFarming = false;
int tmpId = 1, tmpArea = 5, tmpIsKeshting = 0, tmpAmountKeshting = 0, thisDay = 0, tmpday = 0, startDayFarming = 0;

int difDate(int dd1, int mm1, int yyyy1);
void keshtUpDate(int _keshtAmount);

//this function updates day of player's game
void wheatland2::upDate(){

   thisDay = player->getDay();
}


wheatland2::wheatland2(QWidget *parent, int _id) :
    QDialog(parent),
    ui(new Ui::wheatland2)
{
    ui->setupUi(this);

    //for getting day of player
    player = new person0(_id);
    thisDay = player->getDay();


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


    //seting id of wheatland
    tmpId = _id;


    //setting data with opening the wheatland file
      ifstream wheat("wheat.txt");
      ofstream wheat2("Wheat2.txt");
      if ( wheat.peek() == std::ifstream::traits_type::eof() )
      {
           //file is empty
           wheat2 << tmpId << ' ' << tmpArea << ' ' << tmpIsKeshting<< ' ' << tmpAmountKeshting<< ' ' << startDayFarming << '\n';
           area = tmpArea;
           isKeshting = tmpIsKeshting;
           keshtAmount = tmpAmountKeshting;
           startDay = startDayFarming;
           wheat2.close();
           wheat.close();
           remove("wheat.txt");
           rename("wheat2.txt", "wheat.txt");
      }
      else {
         //file is not empty
         while (wheat >> tmpId >> tmpArea >> tmpIsKeshting >> tmpAmountKeshting >> startDayFarming )
          {
              if (tmpId == _id)
              {
                area = tmpArea;
                isKeshting = tmpIsKeshting;
                keshtAmount = tmpAmountKeshting;
                startDay = startDayFarming;
                break;
              }
           wheat.close();
           wheat2.close();
           remove("wheat2.txt");
         }
      }


      //ui progressBar setup
      if(tmpIsKeshting == false)
          ui->progressBar->setValue(0);
      else
      {
          ui->progressBar->setValue(( player->getDay() - startDayFarming ) * 100 / 2);

          if( ( ( player->getDay() - startDayFarming ) * 100 / 2 ) >= 100){
              endOfFarming = true;
          }
          else{
              endOfFarming = false;
          }
      }


        //ui area display
        ui->AreaLabel->setText(QString::number(tmpArea));


}

wheatland2::~wheatland2()
{
    delete ui;
}

void wheatland2::on_kesht_clicked()
{
    if(!tmpIsKeshting)
    {
       if ( ui->keshtSize->text().toInt() > tmpArea )
           QMessageBox::critical(this,"ERROR","Not enough space availble!");
       else if( ui->keshtSize->text().isEmpty() )
           QMessageBox::critical(this,"ERROR","LineEdit can not be Empty!");
       else{
           keshtUpDate(ui->keshtSize->text().toInt());
           QMessageBox::information(this,"DONE","Farming has begone!");
       }
    }
    else
    {
        QMessageBox::critical(this,"ERROR","Farming is already in progress!");
    }
}


void wheatland2::on_bardasht_clicked()
{
    if(endOfFarming)
    {
        //add wealth to garner and update file
    }
    else if(tmpIsKeshting == 0){
        QMessageBox::critical(this,"ERROR","You must farm first!");
    }
    else{
        QMessageBox::critical(this,"ERROR","Sorry,but you must wait!");
    }
}


void wheatland2::on_upGrade_clicked()
{

}


void keshtUpDate(int _keshtAmount) {

    ofstream temp("temp.txt");
    ifstream wheat("wheat.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsKeshting2 = 0, tmpAmountKeshting2 = 0, tmpdayFarmStart = 0 ;
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsKeshting2 >> tmpAmountKeshting2 >> tmpdayFarmStart )
    {
        if (tmpId == tmpId2)
        {
            tmpIsKeshting2 = 1;
            tmpIsKeshting = 1;
            tmpAmountKeshting2 = _keshtAmount;
            tmpAmountKeshting = _keshtAmount;
            tmpdayFarmStart = player->getDay();
            tmpday = player->getDay();
            break;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsKeshting2 << ' ' << tmpAmountKeshting2 << ' ' << tmpdayFarmStart << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");
}
