#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <string>
#include <QDataStream>
//using namespace std;

struct tmp{
QString name;
QString pass;
QString username;
QString email;
int coin;
int exp;
int level;
int shenaseP;
int maxExp;
};

QDataStream &operator>>(QDataStream &in, struct tmp &p){ //for read from the file
    in >> p.name >> p.pass >>p.username>>p.email>>p.coin>>p.exp>>p.level>>p.shenaseP>>p.maxExp;
    return in;
}

MainWindow::MainWindow(QWidget *parent, int _id)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    userId = _id;

    ui->setupUi(this);
    this->setWindowTitle("HeyDay");

    QPixmap bkgnd("C:/Users/Radikal/Desktop/Logo/back.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window/*Background*/, bkgnd);
       this->setPalette(palette);

    //main window title icon
    setWindowIcon(QIcon("C:/Users/Radikal/Desktop/Logo/heyday1.jpg"));

    //level icon
    QPixmap starIcon("C:/Users/Radikal/Desktop/Logo/images.png");
    ui->label->setPixmap(starIcon.scaled(30,30));

    //coin icon
    QPixmap coinIcon("C:/Users/Radikal/Desktop/Logo/coin.png");
    ui->label_2->setPixmap(coinIcon.scaled(35,35));

    //next day button icon
    ui->pushButton_2->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/images.jpg"));
    ui->pushButton_2->setIconSize(QSize(54, 52));

    //scorebored button icon
    ui->pushButton->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/score.jpg"));
    ui->pushButton->setIconSize(QSize(40, 40));

    //shop button icon
    ui->pushButton_3->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/shop.jpg"));
    ui->pushButton_3->setIconSize(QSize(61, 62));

    struct tmp p;
        QFile infile("person.txt");
        infile.open(QIODevice::ReadOnly);
        if(infile.isOpen()){
            while(!infile.atEnd()){
                QDataStream in(&infile);
                in >> p;
                   if(p.shenaseP == userId){



                   }
            }
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    scoreboard sc;
    sc.setWindowIcon(QIcon("C:/Users/Radikal/Desktop/Logo/score.jpg"));
    sc.setModal(true);
    sc.exec();
}

void MainWindow::setLevel(int _level)
{
    level = _level;
    showLevel();
}

void MainWindow::showLevel()
{
    QString stringNumber = QString::number(level);
    ui->label_4->setText(stringNumber);
}

void MainWindow::setXp(int _xp)
{
    xp = _xp;
    showXp();
}

//Display persentage of XP
void MainWindow::showXp()
{
    int XpOfLvl = 0;
    for (int i = 0 ; i < level ; i++) {
        XpOfLvl = 10 + 2 * XpOfLvl;
    }
   ui->XP->setValue( xp/XpOfLvl * 100 );
}

//Update value of xp and level
void MainWindow::upDateXp(int additionalXp){
    int xp2 = 0;
    xp2 = xp + additionalXp;

}

void MainWindow::setCoin(int _coin)
{
    coin = _coin;
    showCoin();
}

void MainWindow::showCoin()
{
    QString stringNumber = QString::number(coin);
    ui->label_3->setText(stringNumber);

}

void MainWindow::setPassedDay(int _passed)
{
    passedDays = _passed;
    showPassedDay();
}

void MainWindow::showPassedDay()
{
    QString stringNumber = QString::number(passedDays);
    ui->label_5->setText(stringNumber);
}

//shop button (AmirAli)
void MainWindow::on_pushButton_3_clicked()
{

}

//next day button(AmirAli)
void MainWindow::on_pushButton_2_clicked()
{

}

//silo button (Soroosh)
void MainWindow::on_silo_clicked()
{

}

//garner button(Soroosh)
void MainWindow::on_garner_clicked()
{

}

//alfalfa land(Soroosh)
void MainWindow::on_alfalfaLand_clicked()
{

}

//Wheatland (Pouya)
void MainWindow::on_WheatLand_clicked()
{

}

//Aviculture button (Ahmad)
void MainWindow::on_Aviculture_clicked()
{

}

//Dairyfarm (Ahmad)
void MainWindow::on_Dairyfarm_clicked()
{

}

//Sheepcote (Ahmad)
void MainWindow::on_Sheepcote_clicked()
{

}

