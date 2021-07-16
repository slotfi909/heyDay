#include "alfalfafield.h"
#include "ui_alfalfafield.h"

#include <person.h>
#include <QMessageBox>
#include <fstream>
using namespace std;

person0* player;

int tmpArea=4,tmpday=0,tmpId=1,tmpPlowStartDay=0,tmpUpgradeStartDay=0,tmpPlantStartDay=0;
bool tmpIsPlowed=0,tmpIsBeingPlowed=0,tmpIsBeingUpgraded=0,tmpIsBeingPlanted=0;

//order in file
//
//id--area--day--isplowed--isbeingplowed--isbeingupgraded--isbeingplanted--plowStartDay--upgradeStartDay--plantStartDay
alfalfaField::alfalfaField(QWidget *parent,int _id) :
    QDialog(parent),
    ui(new Ui::alfalfaField)
{
    ui->setupUi(this);
    player = new person0(_id);
    tmpday=player->getDay();
    tmpId=_id;
    
    ifstream alfalfaField1("alfalfaField1.txt");
        ofstream alfalfaField2("alfalfaField2.txt");

        if ( alfalfaField1.peek() == std::ifstream::traits_type::eof() )
        {
             //file is empty
             alfalfaField2 << tmpId << ' ' << tmpArea << ' ' << tmpday<< ' ' << tmpIsPlowed<< ' ' << tmpIsBeingPlowed <<' '<<tmpIsBeingUpgraded<<' '<< tmpIsBeingPlanted<<tmpPlowStartDay<<' '<<tmpUpgradeStartDay<<' '<<tmpPlantStartDay<<'\n';
             area = tmpArea;
             day=tmpday;
             isPlowed=tmpIsPlowed;
             isBeingPlowed=tmpIsBeingPlowed;
             isBeingUpgraded=tmpIsBeingUpgraded;
             isBeingPlanted=tmpIsBeingPlanted;
             plowStartDay=tmpPlowStartDay;
             upgradeStartDay=tmpUpgradeStartDay;
             plantStartDay=tmpPlantStartDay;
             alfalfaField2.close();
             alfalfaField1.close();
             remove("alfalfaField1.txt");
             rename("alfalfaField2.txt", "alfalfaField1.txt");
        }
        else {
           //file is not empty
           while (alfalfaField1 >> tmpId >> tmpArea >> tmpday >> tmpIsPlowed >> tmpIsBeingPlowed>>tmpIsBeingUpgraded>>tmpIsBeingPlanted>>tmpPlowStartDay>>tmpUpgradeStartDay>>tmpPlantStartDay )
            {
                if (tmpId == _id)
                {
                    area = tmpArea;
                    day=tmpday;
                    isPlowed=tmpIsPlowed;
                    isBeingPlowed=tmpIsBeingPlowed;
                    isBeingUpgraded=tmpIsBeingUpgraded;
                    isBeingPlanted=tmpIsBeingPlanted;
                    plowStartDay=tmpPlowStartDay;
                    upgradeStartDay=tmpUpgradeStartDay;
                    plantStartDay=tmpPlantStartDay;
                  break;
             alfalfaField1.close();
             alfalfaField2.close();
             remove("alfalfaField2.txt");
           }
           }
        }
        
        
        //ui progressBar setup
        if(tmpIsBeingPlanted == false)
            ui->progressBar->setValue(0);
        
        else
        {
            ui->progressBar->setValue(( player->getDay() - tmpPlantStartDay ) * 100 / 2);
  }
ui->label_2->setText(QString::number(tmpArea));

        
}

alfalfaField::~alfalfaField()
{
    delete ui;
}


int alfalfaField::getArea(){return area;}
void alfalfaField::plow(){
isPlowed=true;
}








void alfalfaField::on_pushButton_3_clicked() //plant
{
    

        if(!tmpIsBeingPlanted)
        {
           if ( ui->lineEdit->text().toInt() > tmpArea )
               QMessageBox::critical(this,"ERROR","Not enough space availble!");
//           else if( ui->lineEdit->text().isEmpty() )
//               QMessageBox::critical(this,"ERROR","LineEdit can not be Empty!");
//           else{
//               keshtUpDate(ui->lineEdit->text().toInt());
//               QMessageBox::information(this,"DONE","Farming has begone!");
           }
        else
        {
            QMessageBox::critical(this,"ERROR","planting is already in progress!");
        }

    
    
}


void alfalfaField::on_pushButton_2_clicked() // harvest
{
    if(tmpIsBeingPlanted){
 if(player->getDay()>=tmpPlantStartDay+2) // enough days has passed

 {

 }
 else{
     QMessageBox::critical(this,"ERROR","not enough time has passed!");

 }
}
    else{
        QMessageBox::critical(this,"ERROR","You must farm first!");
    }
    }


void alfalfaField::on_pushButton_clicked() //upgrade
{
    
}

void alfalfaField::upDate(){

   day = player->getDay();
}
