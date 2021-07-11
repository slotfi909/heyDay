#pragma once

#include <QtWidgets/QWidget>
//#include "ui_Sheepcote.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>

class Sheepcote : public QWidget
{
    Q_OBJECT

public:
    Sheepcote(QWidget *parent = Q_NULLPTR);

public slots:
    void open_second_window();

private:
    QVBoxLayout* mainLayout;
    QPushButton* button;

    //Ui::SheepcoteClass ui;
};
