#include "Dairyfarm.h"
#define DAIRYFARM "C:/HeydayLogo/Dairyfarm_logo/cow.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Dairyfarm_logo/2644051.png"
#define REMOVAL "C:/HeydayLogo/Dairyfarm_logo/6571245.png"
#define UPGRADING "C:/HeydayLogo/Aviculture_logo/6154580.png"

Dairyfarm::Dairyfarm(QWidget *parent, farm* _Myfarm)
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


    ui.setupUi(this);
}

void Dairyfarm::status() {
    QString str = QString("current number of cows: %1\ncapacity of Dairyfarm: %2\nlevel of Dairyfarm: %3").arg(/*myFarm->myDairyfarm.getcurrent()*/).arg(/*myFarm->myDairyfarm.getcapacity()*/).arg(/*myFarm->myDairyfarm.getlevel()*/);

    QMessageBox::information(this, "status", str);
}

void Dairyfarm::feeding() {
    QString str;

    if (/*myFarm->myDairyfarm.getcurrent()*/ == 0)
        str = "there is no cow for feeding";
    else if (/*myFarm->myDairyfarm.gethavecrop()*/)
        str = "cows have milk you should harvest your crops first";
    else if (/*myFarm->mystorage.getNumAlfalfa()*/</*myFarm->myaviculture.getcurrent()*2*/)
        str = "not enough Alfalfa";
    else if (/*myFarm->myDairyfarm.getisfed()*/)
        str = "hens have been fed already you should wait until they make milk";
    else {
       // myFarm->myDairyfarm.set_start_day_of_produce(myFarm->owner.getday());
       // myFarm->myDairyfarm.setisfed(true);
      //  myFarm->mystorage.addWheat(myFarm->myaviculture.getcurrent() * -2);
        //myFarm->owner.setExp(myFarm->owner.getExp() + 3);
        str = "hens fed successfully";
    }
    QMessageBox::information(this, "feeding", str);
}

void Dairyfarm::removal() {
    QString str;

    if (myFarm->Dairyfarm.getisfed() && !myFarm->Dairyfarm.gethavecrop())
        str = "cows have been fed but they have not make milk already";
    else if (!myFarm->Dairyfarm.gethavecrop())
        str = "there is no milk for milch";
    else if (myFarm->mystorage.getCapacity() < myFarm->Dairyfarm.getcurrent())
        str = "garner has no place";
    else {
         myFarm->mystorage.addMilk(myFarm->Dairyfarm.getcurrent());
         myFarm->owner.setExp(myFarm->owner.getExp() + 5);
        myFarm->Dairyfarm.sethavecrop(false);
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Dairyfarm::starting_upgrade() {
    QString str;

    if (myFarm->owner.getLevel() < 5)
        str = "At least level 5 is required!";
    else if (myFarm->mystorage.getNail() < 2)
        str = "At least 2 nail is required!";
    else if (myFarm->owner.getCoin() < 15)
        str = "At least 15 coin is required!";
    else {
        // myFarm->Dairyfarm.set_start_day_of_start_day_of_upgrading(myFarm->owner.getday());

        //myFarm->owner.setCoin(myFarm->owner.getCoin() - 15);
        //myFarm->owner.setExp(myFarm->owner.getExp() + 6);
      //  myFarm->mystorage.addNail(-2);
        str = "start upgrading. It takes five days";
    }
    QMessageBox::information(this, "upgrading", str);
}
