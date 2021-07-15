#ifndef SILO_H
#define SILO_H

#include <QDialog>

namespace Ui {
class silo;
}

class silo : public QDialog
{
    Q_OBJECT

public:
    explicit silo(QWidget *parent = nullptr);
    ~silo();

//    void upgrade(person& player,const storage& playerStorage);
    int getCapaticy();
    int getNumWheat();
    int getLevel();
    void addWheat(int addedWheatNumber);
//void checkForUpgrade(person& player);
    friend class storage;
    friend class alfalfaField;

private:
    Ui::silo *ui;
    int capacity;
    int numWheat;
    int level;
    unsigned int siloTime;
    bool isBeingUpgraded;
};

#endif // SILO_H



