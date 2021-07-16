#include "Dairyfarm.h"
#define DAIRYFARM "C:/HeydayLogo/Dairyfarm_logo/cow.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Dairyfarm_logo/2644051.png"
#define REMOVAL "C:/HeydayLogo/Dairyfarm_logo/6571245.png"
#define UPGRADING "C:/HeydayLogo/Aviculture_logo/6154580.png"

Dairyfarm::Dairyfarm(QWidget *parent, Farm* _Myfarm)
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

void Dairyfarm::status() {
    if (myFarm->myDai.getupgrading() && myFarm->owner.getDay() - myFarm->myDai.get_start_day_of_upgrading >= 5) {
        myFarm->myDai.setcapacity(myFarm->myDai.getcapacity() * 2);
        myFarm->myDai.set_start_day_of_upgrading(2147483640);
        myFarm->myDai.setlevel(myFarm->myDai.getlevel() + 1);
        myFarm->myDai.setupgrading(false);
    }
    QString str = QString("current number of cows: %1\ncapacity of Dairyfarm: %2\nlevel of Dairyfarm: %3").arg(myFarm->myDai.getcurrent()).arg(myFarm->myDai.getcapacity()).arg(myFarm->myDai.getlevel());
    
    QMessageBox::information(this, "status", str);
}

void Dairyfarm::feeding() {
    QString str;

    if (myFarm->myDai.getupgrading() && myFarm->owner.getDay() - myFarm->myDai.get_start_day_of_upgrading >= 5) {
        myFarm->myDai.setcapacity(myFarm->myDai.getcapacity() * 2);
        myFarm->myDai.set_start_day_of_upgrading(2147483640);
        myFarm->myDai.setlevel(myFarm->myDai.getlevel() + 1);
        myFarm->myDai.setupgrading(false);
    }

    if (myFarm->myDai.getcurrent() == 0)
        str = "there is no cow for feeding";
    else if (myFarm->myDai.gethavecrop())
        str = "cows have milk you should harvest your crops first";
    else if (myFarm->mySto.getNumAlfalfa()<myFarm->myDai.getcurrent()*2)
        str = "not enough Alfalfa";
    else if (myFarm->myDai.getisfed())
        str = "hens have been fed already you should wait until they make milk";
    else {
        myFarm->myDai.set_start_day_of_produce(myFarm->owner.getDay());
        myFarm->myDai.setisfed(true);
        myFarm->mySto.addAlfalfa(myFarm->myDai.getcurrent() * -2);
        myFarm->owner.setExp(myFarm->owner.getExp() + 3);
        str = "cows fed successfully";
    }
    QMessageBox::information(this, "feeding", str);
}

void Dairyfarm::removal() {
    QString str;

    if (myFarm->myDai.getupgrading() && myFarm->owner.getDay() - myFarm->myDai.get_start_day_of_upgrading >= 5) {
        myFarm->myDai.setcapacity(myFarm->myDai.getcapacity() * 2);
        myFarm->myDai.set_start_day_of_upgrading(2147483640);
        myFarm->myDai.setlevel(myFarm->myDai.getlevel() + 1);
        myFarm->myDai.setupgrading(false);
    }

    if (myFarm->myDai.getisfed() && (myFarm->owner.getDay() - myFarm->myDai.get_start_day_of_produce >= 3)) {
        myFarm->myDai.sethavecrop(true);
        myFarm->myDai.setisfed(false);
        myFarm->myDai.set_start_day_of_produce(-1);
    }

    if (myFarm->myDai.getisfed() && !myFarm->myDai.gethavecrop())
        str = "cows have been fed but they have not made milk already";
    else if (!myFarm->myDai.gethavecrop())
        str = "there is no milk for milching";
    else if (myFarm->mySto.getCapacity() < myFarm->myDai.getcurrent())
        str = "garner has no place";
    else {
         myFarm->mySto.addMilk(myFarm->myDai.getcurrent());
         myFarm->owner.setExp(myFarm->owner.getExp() + 5);
        myFarm->myDai.sethavecrop(false);
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Dairyfarm::starting_upgrade() {
    QString str;

    if (myFarm->myDai.getupgrading() && myFarm->owner.getDay() - myFarm->myDai.get_start_day_of_upgrading >= 5) {
        myFarm->myDai.setcapacity(myFarm->myDai.getcapacity() * 2);
        myFarm->myDai.set_start_day_of_upgrading(2147483640);
        myFarm->myDai.setlevel(myFarm->myDai.getlevel() + 1);
        myFarm->myDai.setupgrading(false);
    }

    if (myFarm->owner.getLevel() < 5)
        str = "At least level 5 is required!";
    else if (myFarm->mySto.getNail() < 2)
        str = "At least 2 nail is required!";
    else if (myFarm->owner.getCoin() < 15)
        str = "At least 15 coin is required!";
    else if (myFarm->myDai.getupgrading())
        str = "upgrading. you should wait 5 days";
    else {
        myFarm->myDai.set_start_day_of_start_day_of_upgrading(myFarm->owner.getDay());
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 15);
        myFarm->owner.setExp(myFarm->owner.getExp() + 6);
        myFarm->mySto.addNail(-2);
        str = "start upgrading. It takes five days";
    }
    QMessageBox::information(this, "upgrading", str);
}
