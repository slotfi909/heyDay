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
    explicit alfalfaField(QWidget *parent = nullptr);
    ~alfalfaField();

    int getArea();
//        void upgrade(person& player,storage& playerStorage);
//    void planting(int chosenArea,person player,storage& playerStorage);
//    void harvest(storage& playerStorage);
    void plow();
//    void checkForUpgrade(person& player);
    friend class storage;
    friend class silo;

private:
    Ui::alfalfaField *ui;
    int area;
    bool isPlowed;
    unsigned int plowTime_Start;
    unsigned int alfalfaFieldTime;
    bool isBeingUpgraded;
    bool isBeingPlowed;
    bool isBeingPlanted;

};

#endif // ALFALFAFIELD_H



