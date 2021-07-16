#include "dialogsilo.h"
#include "ui_dialogsilo.h"
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
DialogSilo::DialogSilo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSilo)
{

    ui->setupUi(this);

}

DialogSilo::~DialogSilo()
{
    delete ui;
}










