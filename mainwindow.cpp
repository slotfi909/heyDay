#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <string>
#include <QDataStream>


MainWindow::MainWindow(QWidget *parent, int shenaseP)
    : QMainWindow(parent),myfarm(shenaseP),Ex(&myfarm)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);
    Ex.setLabel1(ui->label_5);
    Ex.set_Day(shenaseP);
    Ex.start();
    //menu title
    this->setWindowTitle("HeyDay");

    //background image
    QPixmap bkgnd("C:/HeydayLogo/Logo/back.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window/*Background*/, bkgnd);
       this->setPalette(palette);

    //main window title icon
    setWindowIcon(QIcon("C:/HeydayLogo/Logo/heyday1.jpg"));

    //level icon
    QPixmap starIcon("C:/HeydayLogo/Logo/images.png");
    ui->label->setPixmap(starIcon.scaled(30,30));

    //coin icon
    QPixmap coinIcon("C:/HeydayLogo/Logo/coin.png");
    ui->label_2->setPixmap(coinIcon.scaled(35,35));

    //next day button icon
    ui->pushButton_2->setIcon(QIcon("C:/HeydayLogo/Logo/images.jpg"));
    ui->pushButton_2->setIconSize(QSize(54, 52));

    //scorebored button icon
    ui->pushButton->setIcon(QIcon("C:/HeydayLogo/Logo/score.jpg"));
    ui->pushButton->setIconSize(QSize(40, 40));

    //shop button icon
    ui->pushButton_3->setIcon(QIcon("C:/HeydayLogo/Logo/shop.jpg"));
    ui->pushButton_3->setIconSize(QSize(61, 62));

    //silo button icon
    ui->pushButton_3->setIcon(QIcon("C:/HeydayLogo/Logo/shop.jpg"));
    ui->pushButton_3->setIconSize(QSize(61, 62));

    //garner button icon

}

MainWindow::~MainWindow()
{
    Ex.terminate();
    Ex.ExupdateFile(myfarm.owner.getShenaseP());
    myfarm.owner.Update_file();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    sc=new scoreboard(this);
    sc->setWindowIcon(QIcon("C:/HeydayLogo/Logo/score.jpg"));
    sc->setModal(true);
    sc->show();
}



void MainWindow::showLevel()
{
    QString stringNumber = QString::number(myfarm.owner.getLevel());
    ui->label_4->setText(stringNumber);
}



//Display persentage of XP
void MainWindow::showXp()
{
   ui->XP->setValue( myfarm.owner.getExp()/myfarm.owner.getMaxExp() * 100 );
}





void MainWindow::showCoin()
{
    QString stringNumber = QString::number(myfarm.owner.getCoin());
    ui->label_3->setText(stringNumber);

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
  /* wheatland wh;
   wh.setModal(true);
   wh.exec();*/
}


//Aviculture button (Ahmad)
void MainWindow::on_Aviculture_clicked()
{
    Avi=new Aviculture(this);
    Avi->show();

}

//Dairyfarm (Ahmad)
void MainWindow::on_Dairyfarm_clicked()
{
    Da=new Dairyfarm(this);
    Da->show();
}

//Sheepcote (Ahmad)
void MainWindow::on_Sheepcote_clicked()
{
    Sh=new Sheepcote(this);
    Sh->show();

}

