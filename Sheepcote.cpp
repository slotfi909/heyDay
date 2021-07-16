#include "Sheepcote.h"
#define SHEEPCOTE "C:/HeydayLogo/Sheepcote_logo/1665662.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Sheepcote_logo/3382344.png"
#define REMOVAL "C:/HeydayLogo/Sheepcote_logo/5332241.png"
#define UPGRADING "C:/HeydayLogot/Aviculture_logo/6154580.png"


Sheepcote::Sheepcote(QWidget *parent, Farm* _Myfarm)
    : QWidget(parent)
{
    myFarm = _Myfarm;
    Layout = new QVBoxLayout();
    btn1 = new QPushButton();
    btn1->setIcon(QIcon(STATUS));
    btn1->setIconSize(QSize(65, 65));
    btn1->setToolTip("status");

    btn2 = new QPushButton();
    btn2->setIcon(QIcon(FEEDING));
    btn2->setIconSize(QSize(65, 65));
    btn2->setToolTip("feeding");

    btn3 = new QPushButton();
    btn3->setIcon(QIcon(REMOVAL));
    btn3->setIconSize(QSize(65, 65));
    btn3->setToolTip("removal");

    btn4 = new QPushButton();
    btn4->setIcon(QIcon(UPGRADING));
    btn4->setIconSize(QSize(65, 65));
    btn4->setToolTip("upgrading");

    Layout->addWidget(btn1);
    Layout->addWidget(btn2);
    Layout->addWidget(btn3);
    Layout->addWidget(btn4);

    setLayout(Layout);

    connect(btn1, SIGNAL(clicked()), this, SLOT(ststus()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(feeding()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(removal()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(starting_upgrade()));

   // ui.setupUi(this);
}

void Sheepcote::status() {
    if (myFarm->myShe.getupgrading() && myFarm->owner.getDay() - myFarm->myShe.get_start_day_of_upgrading >= 9) {
        myFarm->myShe.setcapacity(myFarm->myShe.getcapacity() * 2);
        myFarm->myShe.set_start_day_of_upgrading(2147483640);
        myFarm->myShe.setlevel(myFarm->myShe.getlevel() + 1);
        myFarm->myShe.setupgrading(false);
    }
    QString str = QString("current number of sheeps: %1\ncapacity of Sheepcote: %2\nlevel of Sheepcote: %3").arg(myFarm->myShe.getcurrent()).arg(myFarm->myShe.getcapacity()).arg(myFarm->myShe.getlevel());
    
    QMessageBox::information(this, "status", str);
}

void Sheepcote::feeding() {
    QString str;

    if (myFarm->myShe.getupgrading() && myFarm->owner.getDay() - myFarm->myShe.get_start_day_of_upgrading >= 9) {
        myFarm->myShe.setcapacity(myFarm->myShe.getcapacity() * 2);
        myFarm->myShe.set_start_day_of_upgrading(2147483640);
        myFarm->myShe.setlevel(myFarm->myShe.getlevel() + 1);
        myFarm->myShe.setupgrading(false);
    }

    if (myFarm->myShe.getcurrent() == 0)
        str = "there is no sheep for feeding";
    else if (myFarm->myShe.gethavecrop())
        str = "sheeps have fleece you should harvest your crops first";
    else if (myFarm->mySto.getNumAlfalfa() <myFarm->myShe.getcurrent())
        str = "not enough Alfalfa";
    else if (myFarm->myShe.getisfed())
        str = "sheeps have been fed already you should wait until their fleece grow";
    else {
         myFarm->myShe.set_start_day_of_produce(myFarm->owner.getDay());
         myFarm->myShe.setisfed(true);
         myFarm->mySto.addAlfalfa(myFarm->myShe.getcurrent() * -1);
         myFarm->owner.setExp(myFarm->owner.getExp() + 7);
        str = "sheeps fed successfully";
    }
    QMessageBox::information(this, "feeding", str);

}

void Sheepcote::removal() {
    QString str;

    if (myFarm->myShe.getupgrading() && myFarm->owner.getDay() - myFarm->myShe.get_start_day_of_upgrading >= 9) {
        myFarm->myShe.setcapacity(myFarm->myShe.getcapacity() * 2);
        myFarm->myShe.set_start_day_of_upgrading(2147483640);
        myFarm->myShe.setlevel(myFarm->myShe.getlevel() + 1);
        myFarm->myShe.setupgrading(false);
    }

    if (myFarm->myShe.getisfed() && (myFarm->owner.getDay() - myFarm->myShe.get_start_day_of_produce >= 10)) {
        myFarm->myShe.sethavecrop(true);
        myFarm->myShe.setisfed(false);
        myFarm->myShe.set_start_day_of_produce(-1);
    }

    if (myFarm->myShe.getisfed() && !myFarm->myShe.gethavecrop())
        str = "sheeps have been fed but their fleece have not grown already";
    else if (!myFarm->myShe.gethavecrop())
        str = "there is no fleece for croping";
    else if (myFarm->mySto.getCapacity() < myFarm->Dairyfarm.getcurrent())
        str = "garner has no place";
    else if (myFarm->owner.getCoin()< myFarm->myShe.getcurrent())
        str = QString("At least %1 coin is required!").arg(myFarm->myShe.getcurrent());
    else {
        myFarm->mySto.addFleece(myFarm->myShe.getcurrent());
        myFarm->owner.setExp(myFarm->owner.getExp() + 9);
        myFarm->myShe.sethavecrop(false);
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 15);
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Sheepcote::starting_upgrade() {
    QString str;

    if (myFarm->myShe.getupgrading() && myFarm->owner.getDay() - myFarm->myShe.get_start_day_of_upgrading >= 9) {
        myFarm->myShe.setcapacity(myFarm->myShe.getcapacity() * 2);
        myFarm->myShe.set_start_day_of_upgrading(2147483640);
        myFarm->myShe.setlevel(myFarm->myShe.getlevel() + 1);
        myFarm->myShe.setupgrading(false);
    }

    if (myFarm->owner.getLevel() < 7)
        str = "At least level 7 is required!";
    else if (myFarm->mySto.getNail() < 3)
        str = "At least 2 nail is required!";
    else if (myFarm->owner.getCoin() < 50)
        str = "At least 50 coin is required!";
    else if(myFarm->mySto.getShovel() < 1)
        str = "At least 1 shovel is required!";
    else if (myFarm->myShe.getupgrading())
        str = "upgrading. you should wait 9 days";
    else {
         myFarm->myShe.set_start_day_of_start_day_of_upgrading(myFarm->owner.getDay());

        myFarm->owner.setCoin(myFarm->owner.getCoin() - 50);
        myFarm->owner.setExp(myFarm->owner.getExp() + 15);
        myFarm->mySto.addNail(-3);
        myFarm->mySto.addshavel(-1);

        str = "start upgrading. It takes nine days";
    }
    QMessageBox::information(this, "upgrading", str);

}