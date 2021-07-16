#include "Aviculture.h"
#define AVICULTURE "C:/HeydayLogo/Aviculture_logo/Aviculture.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Aviculture_logo/5247235.png"
#define REMOVAL "C:/HeydayLogo/Aviculture_logo/5466852.png"
#define UPGRADING "C:/HeydayLogo/Aviculture_logo/6154580.png"

Aviculture::Aviculture(QWidget *parent, Farm* _Myfarm)
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

    connect(btn1, SIGNAL(clicked()), this, SLOT(status()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(feeding()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(removal()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(starting_upgrade()));

  //  ui.setupUi(this);
}

void Aviculture::status() {
    if ((myFarm->myAvi.getupgrading()) && (myFarm->owner.getDay() - myFarm->myAvi.get_start_day_of_upgrading()) >= 3) {
        myFarm->myAvi.setcapacity(myFarm->myAvi.getcapacity() * 2);
        myFarm->myAvi.set_start_day_of_upgrading(2147483640);
        myFarm->myAvi.setlevel(myFarm->myAvi.getlevel() + 1);
        myFarm->myAvi.setupgrading(false);
    }
    QString str = QString("current number of chickens: %1\ncapacity of aviculture: %2\nlevel of aviculture: %3").arg(myFarm->myAvi.getcurrent()).arg(myFarm->myAvi.getcapacity()).arg(myFarm->myAvi.getlevel());

    QMessageBox::information(this, "status", str);
}

void Aviculture::feeding() {
    QString str;
    //in bakhsh be aval store azafe konam;................................................
    if ((myFarm->myAvi.getupgrading()) && (myFarm->owner.getDay() - myFarm->myAvi.get_start_day_of_upgrading()) >= 3) {
        myFarm->myAvi.setcapacity(myFarm->myAvi.getcapacity() * 2);
        myFarm->myAvi.set_start_day_of_upgrading(2147483640);
        myFarm->myAvi.setlevel(myFarm->myAvi.getlevel() + 1);
        myFarm->myAvi.setupgrading(false);
    }
    //....................................................................................
    if (myFarm->myAvi.getcurrent() == 0)
        str = "there is no chicken for feeding";
    else if (myFarm->myAvi.gethavecrop())
        str = "hens have egg you should harvest your crops first";
    else if (myFarm->mySil.getNumWheat()<myFarm->myAvi.getcurrent())
        str = "not enough wheat";
    else if (myFarm->myAvi.getisfed())
        str = "hens have been fed already you should wait until they lay";
    else {
        myFarm->myAvi.set_start_day_of_produce(myFarm->owner.getDay());
        myFarm->myAvi.setisfed(true);
        myFarm->mySil.addWheat(myFarm->myAvi.getcurrent() * -1);
        myFarm->owner.setExp(myFarm->owner.getExp() + 1);
        str = "hens fed successfully";
    }
    QMessageBox::information(this, "feeding", str);
}

void Aviculture::removal() {
    QString str;

    if ((myFarm->myAvi.getupgrading()) && (myFarm->owner.getDay() - myFarm->myAvi.get_start_day_of_upgrading()) >= 3) {
        myFarm->myAvi.setcapacity(myFarm->myAvi.getcapacity() * 2);
        myFarm->myAvi.set_start_day_of_upgrading(2147483640);
        myFarm->myAvi.setlevel(myFarm->myAvi.getlevel() + 1);
        myFarm->myAvi.setupgrading(false);
    }

    if ((myFarm->myAvi.getisfed()) && (myFarm->owner.getDay() - myFarm->myAvi.get_start_day_of_produce() >= 2)) {
        myFarm->myAvi.sethavecrop(true);
        myFarm->myAvi.setisfed(false);
        myFarm->myAvi.set_start_day_of_produce(-1);
    }

    if (myFarm->myAvi.getisfed() && !myFarm->myAvi.gethavecrop())
        str = "hens have been fed but they have not laid already";
    else if (!myFarm->myAvi.gethavecrop())
        str = "there is no egg for removal";
    else if (myFarm->mySto.getCapacity()< myFarm->myAvi.getcurrent())
        str = "garner has no place";
    else {
        myFarm->mySto.addEgg(myFarm->myAvi.getcurrent());
        myFarm->owner.setExp(myFarm->owner.getExp() + 2);
        myFarm->myAvi.sethavecrop(false);
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Aviculture::starting_upgrade() {
    QString str;

    if ((myFarm->myAvi.getupgrading()) && (myFarm->owner.getDay() - myFarm->myAvi.get_start_day_of_upgrading()) >= 3) {
        myFarm->myAvi.setcapacity(myFarm->myAvi.getcapacity() * 2);
        myFarm->myAvi.set_start_day_of_upgrading(2147483640);
        myFarm->myAvi.setlevel(myFarm->myAvi.getlevel() + 1);
        myFarm->myAvi.setupgrading(false);
    }

    if (myFarm->owner.getLevel() < 3)
        str = "At least level 3 is required!";
    else if (myFarm->mySto.getNail() < 1)
        str = "At least 1 nail is required!";
    else if (myFarm->owner.getCoin() < 10)
        str = "At least 10 coin is required!";
    else if (myFarm->myAvi.getupgrading())
        str = "upgrading. you should wait 3 days";
    else{
         myFarm->myAvi.set_start_day_of_upgrading(myFarm->owner.getDay());
         myFarm->myAvi.setupgrading(true);
         myFarm->owner.setCoin(myFarm->owner.getCoin() - 10);
         myFarm->owner.setExp(myFarm->owner.getExp() + 5);
         myFarm->mySto.addNail(-1);
        str = "start upgrading. It takes three days";
    }
    QMessageBox::information(this, "upgrading", str);
}

