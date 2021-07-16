#ifndef ALFALFAFIELD_H
#define ALFALFAFIELD_H

#include <QDialog>
#
namespace Ui {
class alfalfaField;
}

class alfalfaField : public QDialog
{
    Q_OBJECT

public:
    explicit alfalfaField(QWidget *parent = nullptr,int _id=1);
    ~alfalfaField();

    int getArea();
    void upDate();
//        void upgrade(person& player,storage& playerStorage);
//    void planting(int chosenArea,person player,storage& playerStorage);
//    void harvest(storage& playerStorage);
    void plow();
//    void checkForUpgrade(person& player);
    friend class storage;
    friend class silo;

private slots:
    void on_pushButton_3_clicked();
    
    void on_pushButton_2_clicked();
    
    void on_pushButton_clicked();
    
private:
    Ui::alfalfaField *ui;
    int area;
    bool isPlowed;
    bool isBeingUpgraded;
    bool isBeingPlowed;
    bool isBeingPlanted;
    int plowStartDay;
    int upgradeStartDay;
    int day;
    int plantStartDay;
    int id;

};

#endif // ALFALFAFIELD_H



