#include "dialogstorage.h"
#include "ui_dialogstorage.h"


DialogStorage::~DialogStorage()
{
    delete ui;
}


DialogStorage::DialogStorage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogStorage)
{
    ui->setupUi(this);


}
