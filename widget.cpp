#include "widget.h"
#include "ui_widget.h"
#pragma once

struct temp{
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
QDataStream &operator>>(QDataStream &in, struct temp &p){ //for read from the file
    in >> p.name >> p.pass >>p.username>>p.email>>p.coin>>p.exp>>p.level>>p.shenaseP>>p.maxExp;
    return in;
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{

    delete ui;
}


void Widget::on_pushButton_pressed()
{

    D=new DialogFormakeAccount(this);
    D->show();
}


void Widget::on_pushButton_2_clicked()
{

struct temp p;
    bool peyda=1;
    QFile infile("person.txt");
    infile.open(QIODevice::ReadOnly);
    if(infile.isOpen()){

        while(!infile.atEnd()){

            QDataStream in(&infile);
            in>>p;
               if(ui->userLine->text()==p.username&&ui->passlineEdit->text()==p.pass){

                   peyda=0;
				   //poya code
                  m=new MainWindow(this,p.shenaseP);
                  this->close();
                  m->Ex.set_Day(p.shenaseP);
                   m->Ex.start();
                  m->show();


               }

        }

    }
    if(peyda){
        QMessageBox::information(this,"ERROR","acc not found !");
        this->close();
    }
    infile.close();
}

