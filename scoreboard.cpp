#include "scoreboard.h"
#include "ui_scoreboard.h"

using namespace std;



scoreboard::scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scoreboard)
{
    ui->setupUi(this);

    this->setWindowTitle("Ranking Table");

    QPixmap starIcon("F:/qt projects/projectAP/Logo/rank.jpg");
    ui->label->setPixmap(starIcon.scaled(30,30));

    //set background color
    this->setStyleSheet("background-color: lightgreen");
    ui->listWidget->setStyleSheet("background-color: white");

    ui->pushButton->setIcon(QIcon("F:/qt projects/projectAP/Logo/ok.png"));
    ui->pushButton->setIconSize(QSize(45, 45));


    /*ifstream infile;
    infile.open("person.txt",ios::in);
    if(infile.good()){
        infile.seekg(0, ios::end);
        int size = infile.tellg();
        infile.seekg(0, ios_base::beg);
        while(infile.tellg()<size){
               infile.read((char*)&person,sizeof(person));
               QString qstr = QString::fromStdString(person.name);
               QString tmp = qstr +  "    " +QString::number(person.level);
               ui->listWidget->addItem(tmp);
               }
        }*/

}

scoreboard::~scoreboard()
{
    delete ui;
}
