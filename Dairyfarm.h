#pragma once

#include <QtWidgets/QWidget>
#include "ui_Dairyfarm.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>

class Dairyfarm : public QWidget
{
    Q_OBJECT

public:
    Dairyfarm(QWidget *parent = Q_NULLPTR);

public slots:
    void open_second_window();

private:
    QVBoxLayout* mainLayout;
    QPushButton* button;

    Ui::DairyfarmClass ui;
};
