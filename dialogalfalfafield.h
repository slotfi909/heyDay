#ifndef DIALOGALFALFAFIELD_H
#define DIALOGALFALFAFIELD_H

#include <QDialog>
#include "farm.h"


namespace Ui {
class DialogAlfalfaField;
}

class DialogAlfalfaField : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAlfalfaField(QWidget *parent = nullptr,Farm *_myfarm = nullptr);
    ~DialogAlfalfaField();
int checkForPlow();
    int checkForUpgrade();
    friend class storage;
    friend class silo;
void update_file();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogAlfalfaField *ui;
Farm *myfarm;

};

#endif // DIALOGALFALFAFIELD_H



