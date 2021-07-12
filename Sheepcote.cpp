#include "Sheepcote.h"
#define SHEEPCOTE "C:/HeydayLogo/Sheepcote_logo/1665662.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Sheepcote_logo/3382344.png"
#define REMOVAL "C:/HeydayLogo/Sheepcote_logo/5332241.png"
#define UPGRADING "C:/HeydayLogot/Aviculture_logo/6154580.png"


Sheepcote::Sheepcote(QWidget *parent)
    : QWidget(parent)
{
    //mainLayout = new QVBoxLayout();
   /* button = new QPushButton();
    button->setIcon(QIcon(SHEEPCOTE));
    button->setIconSize(QSize(200, 200));
    button->setToolTip("Sheepcote");*/
    //mainLayout->addWidget(button);
    //setLayout(mainLayout);

    //connect(button, SIGNAL(clicked()), this, SLOT(open_second_window()));

    //ui.setupUi(this);

    QDialog* wdg = new QDialog(this);
    QVBoxLayout* Layout = new QVBoxLayout();
    QPushButton* btn1 = new QPushButton();
    btn1->setIcon(QIcon(STATUS));
    btn1->setIconSize(QSize(65, 65));
    btn1->setToolTip("status");
    QPushButton* btn2 = new QPushButton();
    btn2->setIcon(QIcon(FEEDING));
    btn2->setIconSize(QSize(65, 65));
    btn2->setToolTip("feeding");
    QPushButton* btn3 = new QPushButton();
    btn3->setIcon(QIcon(REMOVAL));
    btn3->setIconSize(QSize(65, 65));
    btn3->setToolTip("removal");
    QPushButton* btn4 = new QPushButton();
    btn4->setIcon(QIcon(UPGRADING));
    btn4->setIconSize(QSize(65, 65));
    btn4->setToolTip("upgrading");
    Layout->addWidget(btn1);
    Layout->addWidget(btn2);
    Layout->addWidget(btn3);
    Layout->addWidget(btn4);

    wdg->setLayout(Layout);
    wdg->show();

    // connect(btn1, SIGNAL(clicked()), this, SLOT(ststus()));
    // connect(btn2, SIGNAL(clicked()), this, SLOT(feeding()));
    // connect(btn3, SIGNAL(clicked()), this, SLOT(removal()));
    // connect(btn4, SIGNAL(clicked()), this, SLOT(starting_upgrade()));
}

void Sheepcote::open_second_window() {
    QDialog* wdg = new QDialog(this);
    QVBoxLayout* Layout = new QVBoxLayout();
    QPushButton* btn1 = new QPushButton();
    btn1->setIcon(QIcon(STATUS));
    btn1->setIconSize(QSize(65, 65));
    btn1->setToolTip("status");
    QPushButton* btn2 = new QPushButton();
    btn2->setIcon(QIcon(FEEDING));
    btn2->setIconSize(QSize(65, 65));
    btn2->setToolTip("feeding");
    QPushButton* btn3 = new QPushButton();
    btn3->setIcon(QIcon(REMOVAL));
    btn3->setIconSize(QSize(65, 65));
    btn3->setToolTip("removal");
    QPushButton* btn4 = new QPushButton();
    btn4->setIcon(QIcon(UPGRADING));
    btn4->setIconSize(QSize(65, 65));
    btn4->setToolTip("upgrading");
    Layout->addWidget(btn1);
    Layout->addWidget(btn2);
    Layout->addWidget(btn3);
    Layout->addWidget(btn4);

    wdg->setLayout(Layout);
    wdg->show();

    // connect(btn1, SIGNAL(clicked()), this, SLOT(ststus()));
    // connect(btn2, SIGNAL(clicked()), this, SLOT(feeding()));
    // connect(btn3, SIGNAL(clicked()), this, SLOT(removal()));
    // connect(btn4, SIGNAL(clicked()), this, SLOT(starting_upgrade()));
}
