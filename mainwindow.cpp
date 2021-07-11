#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <string>
#include <QDataStream>
//using namespace std;





MainWindow::MainWindow(QWidget *parent, int _id)
    : QMainWindow(parent),owner(_id)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    this->setWindowTitle("HeyDay");

    QPixmap bkgnd("F:/qt projects/projectAP/Logo/back.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window/*Background*/, bkgnd);
       this->setPalette(palette);

    //main window title icon
    setWindowIcon(QIcon("F:/qt projects/projectAP/Logo/heyday1.jpg"));

    //level icon
    QPixmap starIcon("F:/qt projects/projectAPLogo/images.png");
    ui->label->setPixmap(starIcon.scaled(30,30));

    //coin icon
    QPixmap coinIcon("F:/qt projects/projectAP/Logo/coin.png");
    ui->label_2->setPixmap(coinIcon.scaled(35,35));

    //next day button icon
    ui->pushButton_2->setIcon(QIcon("F:/qt projects/projectAP/Logo/images.jpg"));
    ui->pushButton_2->setIconSize(QSize(54, 52));

    //scorebored button icon
    ui->pushButton->setIcon(QIcon("F:/qt projects/projectAP/Logo/score.jpg"));
    ui->pushButton->setIconSize(QSize(40, 40));

    //shop button icon
    ui->pushButton_3->setIcon(QIcon("F:/qt projects/projectAP/Logo/shop.jpg"));
    ui->pushButton_3->setIconSize(QSize(61, 62));


    Ex.setLabel1(ui->label_5);


}

MainWindow::~MainWindow()
{
    Ex.terminate();

    Ex.ExupdateFile(owner.getShenaseP());
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    sc.setWindowIcon(QIcon("F:/qt projects/projectAP/Logo/score.jpg"));
    sc.setModal(true);
    sc.show();
}

void MainWindow::setLevel(int _level)
{
    owner.ge = _level;
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

