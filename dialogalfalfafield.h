#ifndef DIALOGALFALFAFIELD_H
#define DIALOGALFALFAFIELD_H

#include <QDialog>
#
namespace Ui {
class DialogAlfalfaField;
}

class DialogAlfalfaField : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAlfalfaField(QWidget *parent = nullptr);
    ~DialogAlfalfaField();


    friend class storage;
    friend class silo;

private:
    Ui::DialogAlfalfaField *ui;


};

#endif // DIALOGALFALFAFIELD_H



