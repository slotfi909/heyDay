#pragma once

#include <QtWidgets/QWidget>
#include "ui_Aviculture.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>

class Aviculture : public QWidget
{
    Q_OBJECT

public:
    Aviculture(QWidget *parent = Q_NULLPTR);

public slots:
    void open_second_window();

private:
    QVBoxLayout* mainLayout;
    QPushButton* button;

    Ui::AvicultureClass ui;
};
