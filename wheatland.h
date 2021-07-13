#ifndef WHEATLAND_H
#define WHEATLAND_H

#include <QWidget>

namespace Ui {
class wheatland;
}

class wheatland : public QWidget
{
    Q_OBJECT

public:
    explicit wheatland(QWidget *parent = nullptr, int id = 1);
    ~wheatland();

private slots:
    void on_kesht_clicked();

    void on_bardasht_clicked();

    void on_upGrade_clicked();

private:
    Ui::wheatland *ui;
    int area;
    bool isKeshting;
    int keshtAmount;
    int startDay;
    int startMonth;
    int startYear;
    int id;
};

#endif // WHEATLAND_H
