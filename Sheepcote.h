#pragma once

#include <QtWidgets/QWidget>
//#include "ui_Sheepcote.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include "farm.h"

class Sheepcote : public QWidget
{
    Q_OBJECT

public:
    Sheepcote(QWidget *parent = Q_NULLPTR, farm* _Myfarm);

public slots:
    void status();
    void feeding();
    void removal();
    void starting_upgrade();
private:

    farm* myFarm;
    QVBoxLayout* Layout;
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;

   // Ui::SheepcoteClass ui;
};
