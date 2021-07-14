#include "wheatland.h"
#include "ui_wheatland.h"
#include <QMessageBox>
#include <fstream>
using namespace std;

bool endOfFarming = false;
int tmpId = 1, tmpArea = 5, tmpIsKeshting = 0, tmpAmountKeshting = 0, day = 0 , month = 0, year = 0;

int difDate(int dd1, int mm1, int yyyy1);
void UpDate(int _keshtAmount);

wheatland::wheatland(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wheatland)
{
    ui->setupUi(this);

    this->setWindowTitle("Wheat Land");

    //set background
    //this->setStyleSheet("background-color: lightyellow");
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
      //id = _id;

    //setting data with opening the wheatland file
      ifstream wheat("wheat.txt");
      ofstream wheat2("Wheat2.txt");
      //int tmpId = 1, tmpArea = 5, tmpIsKeshting = 0, tmpAmountKeshting = 0, day = 0 , month = 0, year = 0;
      if ( wheat.peek() == std::ifstream::traits_type::eof() )
      {
         //file is empty
           wheat2 << tmpId << ' ' << tmpArea << ' ' << tmpIsKeshting<< ' ' << tmpAmountKeshting<< ' ' << day<< ' ' << month<< ' ' << year << '\n';
           area = tmpArea;
           isKeshting = tmpIsKeshting;
           keshtAmount = tmpAmountKeshting;
           startDay = day;
           startMonth = month;
           startYear = year;
           wheat2.close();
           wheat.close();
           remove("wheat.txt");
           rename("wheat2.txt", "wheat.txt");
      }
      else {
          //file is not empty
      while (wheat >> tmpId >> tmpArea >> tmpIsKeshting >> tmpAmountKeshting >> day >> month >> year)
      {
          if (tmpId == id)
          {
              area = tmpArea;
              isKeshting = tmpIsKeshting;
              keshtAmount = tmpAmountKeshting;
              startDay = day;
              startMonth = month;
              startYear = year;
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
          ui->progressBar->setValue(difDate(day, month, year)*100/2);
          if((difDate(day, month, year)*100/2) >= 100){
              endOfFarming = true;
          }
          else{
              endOfFarming = false;
          }
      }
      //ui area display
        ui->AreaLabel->setText(QString::number(tmpArea));

}

wheatland::~wheatland()
{
    delete ui;
}

int difDate(int dd1, int mm1, int yyyy1) {

    int dd, mm, yyyy;
    int dd2, mm2, yyyy2;
    time_t t = time(0);
    struct tm* now = localtime(&t);
    yyyy2 = (now->tm_year + 1900);
    mm2 = (now->tm_mon + 1);
    dd2 = now->tm_mday;

    yyyy = yyyy2 - yyyy1;
    mm = mm2 - mm1;
    dd = dd2 - dd1;

    if (dd < 0)
    {
        mm--;
        dd += 30;
    }

    if (mm < 0)
    {
        yyyy--;
        mm += 12;
    }
    double tmp = (((yyyy*365)+mm*31+dd));
    return tmp;
}

void wheatland::on_kesht_clicked()
{
    if(!tmpIsKeshting)
    {
       if( ui->keshtSize->text().toInt() > tmpArea )
           QMessageBox::critical(this,"ERROR","Not enough space availble!");
       else if(ui->keshtSize->text().isEmpty())
           QMessageBox::critical(this,"ERROR","LineEdit can not be Empty!");
       else{
          UpDate(ui->keshtSize->text().toInt());
           QMessageBox::information(this,"DONE","Farming has begone!");
       }
    }
    else{
        QMessageBox::critical(this,"ERROR","Farming is already in progress!");
    }
}


void wheatland::on_bardasht_clicked()
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


void wheatland::on_upGrade_clicked()
{

}


void UpDate(int _keshtAmount) {

    ofstream temp("temp.txt");
    ifstream wheat("wheat.txt");
    int tmpId2 = 1,tmpArea2 = 5, tmpIsKeshting2 = 0, tmpAmountKeshting2 = 0, day2 = 0 , month2 = 0, year2 = 0;
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsKeshting2 >> tmpAmountKeshting2 >> day2 >> month2 >> year2)
    {
        if (tmpId == tmpId2)
        {
            int dd, mm, yyyy;
            time_t t = time(0);
            struct tm* now = localtime(&t);
            yyyy = (now->tm_year + 1900);
            mm = (now->tm_mon + 1);
            dd = now->tm_mday;
            tmpIsKeshting2 = 1;
            tmpIsKeshting = 1;
            tmpAmountKeshting2 = _keshtAmount;
            tmpAmountKeshting = _keshtAmount;
            day2 = dd;
            day = dd;
            month2 = mm;
            month = mm;
            year2 = yyyy;
            year = yyyy;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsKeshting2 << ' ' << tmpAmountKeshting2 << ' ' << day2 << ' ' << month2 << ' ' << year2 << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");
}
