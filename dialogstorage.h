#ifndef DIALOGSTORAGE_H
#define DIALOGSTORAGE_H

#include <QDialog>
//#include "milk.h"
#include <time.h>
#include <iostream>
//#include <person.h>
#include <math.h>
#include <stdbool.h>
using namespace std;
namespace Ui {
class DialogStorage;
}

class DialogStorage : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStorage(QWidget *parent = nullptr);
    ~DialogStorage();

    friend class alfalfaField;
    friend class silo;

private:
    Ui::DialogStorage *ui;

};

#endif // DIALOGSTORAGE_H





