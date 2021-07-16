#ifndef DIALOGSILO_H
#define DIALOGSILO_H

#include <QDialog>

namespace Ui {
class DialogSilo;
}

class DialogSilo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSilo(QWidget *parent = nullptr);
    ~DialogSilo();


    friend class storage;
    friend class alfalfaField;

private:
    Ui::DialogSilo *ui;

};

#endif // DIALOGSILO_H



