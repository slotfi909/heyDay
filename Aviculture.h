#pragma once

#include <QtWidgets/QWidget>
//#include "ui_Aviculture.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QMessageBox>
#include "farm.h"

class Aviculture : public QWidget
{
    Q_OBJECT

public:
    Aviculture(QWidget *parent = Q_NULLPTR,Farm * _Myfarm= Q_NULLPTR);

public slots:
    void status();
    void feeding();
    void removal();
    void starting_upgrade();
private:

    Farm* myFarm;
    QVBoxLayout* Layout;
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;

   // Ui::AvicultureClass ui;
};
