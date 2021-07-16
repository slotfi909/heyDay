#include "dialogalfalfafield.h"
#include "ui_dialogalfalfafield.h"

DialogAlfalfaField::DialogAlfalfaField(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAlfalfaField)
{
    ui->setupUi(this);

}

DialogAlfalfaField::~DialogAlfalfaField()
{
    delete ui;
}








