#ifndef WHEATLAND2_H
#define WHEATLAND2_H

#include <QDialog>

namespace Ui {
class wheatland2;
}

class wheatland2 : public QDialog
{
    Q_OBJECT

public:
    explicit wheatland2(QWidget *parent = nullptr, int _id = 1);
    ~wheatland2();
public:
    void upDate();
private slots:
    void on_kesht_clicked();

    void on_bardasht_clicked();

    void on_upGrade_clicked();

private:
    Ui::wheatland2 *ui;
    int area;
    bool isKeshting;
    int keshtAmount;
    int startDay;
    int startMonth;
    int startYear;
    int id;
};

#endif // WHEATLAND2_H
