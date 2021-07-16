#include "Sheepcote.h"
#define SHEEPCOTE "C:/HeydayLogo/Sheepcote_logo/1665662.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Sheepcote_logo/3382344.png"
#define REMOVAL "C:/HeydayLogo/Sheepcote_logo/5332241.png"
#define UPGRADING "C:/HeydayLogot/Aviculture_logo/6154580.png"


Sheepcote::Sheepcote(QWidget *parent, farm* _Myfarm)
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

    ui.setupUi(this);
}

void Sheepcote::status() {
    QString str = QString("current number of sheeps: %1\ncapacity of Sheepcote: %2\nlevel of Sheepcote: %3").arg(/*myFarm->mySheepcote.getcurrent()*/).arg(/*myFarm->mySheepcote.getcapacity()*/).arg(/*myFarm->mySheepcote.getlevel()*/);

    QMessageBox::information(this, "status", str);
}

void Sheepcote::feeding() {
    QString str;

    if (/*myFarm->mySheepcote.getcurrent()*/ == 0)
        str = "there is no sheep for feeding";
    else if (/*myFarm->mySheepcote.gethavecrop()*/)
        str = "sheeps have fleece you should harvest your crops first";
    else if (/*myFarm->mystorage.getNumAlfalfa()*/ </*myFarm->myaviculture.getcurrent()*/)
        str = "not enough Alfalfa";
    else if (/*myFarm->mySheepcote.getisfed()*/)
        str = "sheeps have been fed already you should wait until their fleece grow";
    else {
        // myFarm->mySheepcote.set_start_day_of_produce(myFarm->owner.getday());
        // myFarm->mySheepcote.setisfed(true);
       //  myFarm->mystorage.addFleece(myFarm->mySheepcote.getcurrent() * -1);
         //myFarm->owner.setExp(myFarm->owner.getExp() + 7);
        str = "sheeps fed successfully";
    }
    QMessageBox::information(this, "feeding", str);

}

void Sheepcote::removal() {
    QString str;

    if (myFarm->Sheepcote.getisfed() && !myFarm->Sheepcote.gethavecrop())
        str = "sheeps have been fed but their fleece have not grown already";
    else if (!myFarm->Sheepcote.gethavecrop())
        str = "there is no fleece for croping";
    else if (myFarm->mystorage.getCapacity() < myFarm->Dairyfarm.getcurrent())
        str = "garner has no place";
    else if (myFarm->owner.getCoin()< myFarm->mySheepcote.getcurrent())
        str = QString("At least %1 coin is required!").arg(myFarm->mySheepcote.getcurrent());
    else {
        myFarm->mystorage.addFleece(myFarm->mySheepcote.getcurrent());
        myFarm->owner.setExp(myFarm->owner.getExp() + 9);
        myFarm->mySheepcote.sethavecrop(false);
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 15);
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Sheepcote::starting_upgrade() {
    QString str;

    if (myFarm->owner.getLevel() < 7)
        str = "At least level 7 is required!";
    else if (myFarm->mystorage.getNail() < 3)
        str = "At least 2 nail is required!";
    else if (myFarm->owner.getCoin() < 50)
        str = "At least 50 coin is required!";
    else if(myFarm->mystorage.getShovel() < 1)
        str = "At least 1 shovel is required!";
    else {
         myFarm->Sheepcote.set_start_day_of_start_day_of_upgrading(myFarm->owner.getday());

        //myFarm->owner.setCoin(myFarm->owner.getCoin() - 50);
        //myFarm->owner.setExp(myFarm->owner.getExp() + 15);
        //myFarm->mystorage.addNail(-3);
        //myFarm->mystorage.addshavel(-1);

        str = "start upgrading. It takes nine days";
    }
    QMessageBox::information(this, "upgrading", str);

}
