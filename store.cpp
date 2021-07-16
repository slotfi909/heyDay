#include "store.h"
#include "ui_store.h"

store::store(QWidget *parent,Farm*_m)
    : QWidget(parent)
    , ui(new Ui::store)
{
    ui->setupUi(this);
 myfarm=_m;

connect(ge,SIGNAL(mysell(int,int)),this,SLOT(slotToSell(int,int)));
connect(ge,SIGNAL(mybuy(int,int)),this,SLOT(slotToBuy(int,int)));

}

store::~store()
{
    delete ui;
}

void store::slotToSell(int kodom,int tedad){

    if(kodom==1){

        if(myfarm->mySil.addWheat(-tedad)){
            myfarm->owner.changeCoin(tedad*2);
            //myfarm->owner.changeExp(1);
            QMessageBox::information(this,"success","SELL successfully");
    }
    }else if(kodom==2){


        if(myfarm->mySto.addAlfalfa(-tedad)){
            myfarm->owner.changeCoin(tedad*4);
            //myfarm->owner.changeExp(2);
            QMessageBox::information(this,"success","SELL successfully");
    }
        }else if (kodom==3){


        int x=myfarm->myAvi.removechicken(tedad);
        if(x==3)
            QMessageBox::information(this,"ERROR","Hens are feedding");
        if(x==4)
            QMessageBox::information(this,"ERROR","Products have not been collected");
          if(x==1){
               myfarm->owner.changeCoin(tedad*15);
            //myfarm->owner.changeExp(5);
            QMessageBox::information(this,"success","SELL successfully");
            }
        }else if(kodom==4){

        int x=myfarm->mySto.addEgg(-tedad);

          if(x==1){
               myfarm->owner.changeCoin(tedad*8);
            //myfarm->owner.changeExp(3);
            QMessageBox::information(this,"success","SELL successfully");
            }
      //QMessageBox::information(this,"ERROR","You cant buy eggs from shop");

        }
    else if(kodom==5){

        int x=myfarm->myDai.removecow(tedad);
        if(x==3)
            QMessageBox::information(this,"ERROR","cows are feedding");
        if(x==4)
            QMessageBox::information(this,"ERROR","Products have not been collected");
          if(x==1){
               myfarm->owner.changeCoin(tedad*50);
            //myfarm->owner.changeExp(10);
            QMessageBox::information(this,"success","SELL successfully");
            }
    }
    else if (kodom==6){

        int x=myfarm->mySto.addMilk(-tedad);

          if(x==1){
               myfarm->owner.changeCoin(tedad*12);
            //myfarm->owner.changeExp(5);
            QMessageBox::information(this,"success","SELL successfully");
            }

        //QMessageBox::information(this,"ERROR","You cant buy milk from shop");

    }else if (kodom==7){

        int x=myfarm->myShe.removesheep(tedad);
        if(x==3)
            QMessageBox::information(this,"ERROR","sheeps are feedding");
        if(x==4)
            QMessageBox::information(this,"ERROR","Products have not been collected");
          if(x==1){
               myfarm->owner.changeCoin(tedad*70);
           // myfarm->owner.changeExp(15);
            QMessageBox::information(this,"success","SELL successfully");
            }
    }else if(kodom==8){
        int x=myfarm->mySto.addFleece(-tedad);

          if(x==1){
               myfarm->owner.changeCoin(tedad*23);
            //myfarm->owner.changeExp(10);
            QMessageBox::information(this,"success","SELL successfully");
            }
    }else if(kodom==9){
        int x=myfarm->mySto.addNail(-tedad);

          if(x==1){
               myfarm->owner.changeCoin(tedad*20);
           // myfarm->owner.changeExp(4);
            QMessageBox::information(this,"success","SELL successfully");
            }
    }else if(kodom==10){
        int x=myfarm->mySto.addShovel(-tedad);

          if(x==1){
               myfarm->owner.changeCoin(tedad*30);
            //myfarm->owner.changeExp(8);
            QMessageBox::information(this,"success","SELL successfully");
            }
    }





}
void store::slotToBuy(int kodom,int tedad){
    if(kodom==1){

        if(myfarm->mySil.addWheat(tedad)){
            myfarm->owner.changeCoin(-tedad*3);
            myfarm->owner.changeExp(1);
            QMessageBox::information(this,"success","BUY successfully");
    }
    }else if(kodom==2){


        if(myfarm->mySto.addAlfalfa(tedad)){
            myfarm->owner.changeCoin(-tedad*6);
            myfarm->owner.changeExp(2);
            QMessageBox::information(this,"success","BUY successfully");
    }
        }else if (kodom==3){


        int x=myfarm->myAvi.addchicken(tedad);
        if(x==3)
            QMessageBox::information(this,"ERROR","Hens are feedding");
        if(x==4)
            QMessageBox::information(this,"ERROR","Products have not been collected");
          if(x==1){
               myfarm->owner.changeCoin(-tedad*20);
            myfarm->owner.changeExp(5);
            QMessageBox::information(this,"success","BUY successfully");
            }
        }else if(kodom==4){


        QMessageBox::information(this,"ERROR","You cant buy eggs from shop");

        }
    else if(kodom==5){

        int x=myfarm->myDai.addcow(tedad);
        if(x==3)
            QMessageBox::information(this,"ERROR","cows are feedding");
        if(x==4)
            QMessageBox::information(this,"ERROR","Products have not been collected");
          if(x==1){
               myfarm->owner.changeCoin(-tedad*70);
            myfarm->owner.changeExp(10);
            QMessageBox::information(this,"success","BUY successfully");
            }
    }
    else if (kodom==6){



        QMessageBox::information(this,"ERROR","You cant buy milk from shop");

    }else if (kodom==7){

        int x=myfarm->myShe.addsheep(tedad);
        if(x==3)
            QMessageBox::information(this,"ERROR","sheeps are feedding");
        if(x==4)
            QMessageBox::information(this,"ERROR","Products have not been collected");
          if(x==1){
               myfarm->owner.changeCoin(-tedad*80);
            myfarm->owner.changeExp(15);
            QMessageBox::information(this,"success","BUY successfully");
            }
    }else if(kodom==8){
        QMessageBox::information(this,"ERROR","You cant buy fleece from shop");
    }else if(kodom==9){
        int x=myfarm->mySto.addNail(tedad);

          if(x==1){
               myfarm->owner.changeCoin(-tedad*30);
            myfarm->owner.changeExp(4);
            QMessageBox::information(this,"success","BUY successfully");
            }
    }else if(kodom==10){
        int x=myfarm->mySto.addShovel(tedad);

          if(x==1){
               myfarm->owner.changeCoin(tedad*50);
            myfarm->owner.changeExp(8);
            QMessageBox::information(this,"success","BUY successfully");
            }
    }
}

//nail
void store::on_pushButton_2_clicked()
{
    ge=new getAmount(this,20,30,myfarm->owner.getCoin(),myfarm->mySto.getNail(),9);
    ge->show();
}


void store::on_pushButton_clicked()
{
    ge=new getAmount(this,2,3,myfarm->owner.getCoin(),myfarm->mySil.getNumWheat(),1);
    ge->show();
}


void store::on_pushButton_3_clicked()
{
    if(myfarm->owner.getLevel()>=2){
    ge=new getAmount(this,15,20,myfarm->owner.getCoin(),myfarm->myAvi.getcurrent(),3);
    ge->show();
    }else {
         QMessageBox::information(this,"ERROR","YOU need level 2");
    }
}


void store::on_pushButton_4_clicked()
{
    if(myfarm->owner.getLevel()>=3){
    ge=new getAmount(this,4,6,myfarm->owner.getCoin(),myfarm->mySil.getNumWheat(),2);
    ge->show();
    }else {
        QMessageBox::information(this,"ERROR","YOU need level 3");
    }
}


void store::on_pushButton_5_clicked()
{
    if(myfarm->owner.getLevel()>=4){
    ge=new getAmount(this,50,70,myfarm->owner.getCoin(),myfarm->myDai.getcurrent(),5);
    ge->show();
    }else {
        QMessageBox::information(this,"ERROR","YOU need level 4");
    }
}


void store::on_pushButton_6_clicked()
{
    if(myfarm->owner.getLevel()>=2){
    ge=new getAmount(this,8,0,myfarm->owner.getCoin(),myfarm->mySto.getEgg(),4);
    ge->show();
    }else{
    QMessageBox::information(this,"ERROR","YOU need level 2");
    }
}


void store::on_pushButton_7_clicked()
{
    if(myfarm->owner.getLevel()>=6){
    ge=new getAmount(this,70,80,myfarm->owner.getCoin(),myfarm->myShe.getcurrent(),7);
    ge->show();
    }else {
         QMessageBox::information(this,"ERROR","YOU need level 7");
    }


}


void store::on_pushButton_8_clicked()
{
    if(myfarm->owner.getLevel()>=4){
    ge=new getAmount(this,12,0,myfarm->owner.getCoin(),myfarm->mySto.getMilk(),6);
    ge->show();
    }else {
         QMessageBox::information(this,"ERROR","YOU need level 4");
    }
}


void store::on_pushButton_9_clicked()
{
    ge=new getAmount(this,30,50,myfarm->owner.getCoin(),myfarm->mySto.getShovel(),10);
    ge->show();
}


void store::on_pushButton_10_clicked()
{
    if(myfarm->owner.getLevel()>=6){
    ge=new getAmount(this,23,0,myfarm->owner.getCoin(),myfarm->mySto.getFleece(),8);
    ge->show();
    }else {
     QMessageBox::information(this,"ERROR","YOU need level 7");
    }
}

