#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <iostream>
#include <QFile>
using namespace std;

class person{
    private:
    QString name;
    QString pass;
    QString username;
    QString email;
    int coin;
    int exp;
    int level;
    int shenaseP;
    int maxExp;
    public://functions
    void setName(QString);
    void setPass(QString);
    void setUsername(QString);
    void setEmail(QString);
    void setCoin(int);
    void setExp(int);
    void setLevel(int);
    void setShenaseP(int);
    void setMaxExp(int);
    person(int);//constructor
    QString getName();
    QString getUsername();
    QString getEmail();
    int getShenaseP();
    int changeCoin(int);//return coin
    int changeExp(int);
    int changeLevel();
    int getMaxExp();
    void Update_file();
};


void person::Update_file(){

    struct temp{
    QString name;
    QString pass;
    QString username;
    QString email;
    int coin;
    int exp;
    int level;
    int shenaseP;
    int maxExp;
    }p;

    QFile outfile("person-temp.txt");//for writing in new file.
    QFile infile("person.txt");//for reading.

    infile.open(QIODevice::ReadOnly);
     if(infile.isOpen()){
    outfile.open(QIODevice::Append);//make file.

    while(!infile.atEnd()){
           infile.read((char*)&p,sizeof(p));
           if(shenaseP==p.shenaseP){
                   p.name=name;
                   p.pass=pass;
                   p.username=username;
                   p.email=email;
                   p.coin=coin;
                   p.exp=exp;
                   p.level=level;
                   p.shenaseP=shenaseP;
                   p.maxExp=maxExp;
           }
           outfile.write((char*)&p,sizeof(p));
    }
    outfile.close();
    infile.close();
    remove("person.txt");
    rename("person-temp.txt","person.txt");
    }

}
///

    void person::setName(QString _name){name=_name;}
    void person::setPass(QString _Pass){pass=_Pass;}
    void person::setUsername(QString _username){username=_username;}
    void person::setEmail(QString _Email){email=_Email;}
    void person::setCoin(int _coin){coin=_coin;}
    void person::setExp(int _Exp){exp=_Exp;}
    void person::setLevel(int _Level){level=_Level;}
    void person::setShenaseP(int _Shenasep){shenaseP=_Shenasep;}
    void person::setMaxExp(int _MaxExp){maxExp=_MaxExp;}

 /////
    person::person(int _shenasep){
         struct temp{
    QString name;
    QString pass;
    QString username;
    QString email;
    int coin;
    int exp;
    int level;
    int shenaseP;
    int maxExp;
    }p;


    QFile infile("person.txt");//for reading.

    infile.open(QIODevice::ReadOnly);
     if(infile.isOpen()){


    while(infile.atEnd()){
           infile.read((char*)&p,sizeof(p));
           if(_shenasep==p.shenaseP){
              name=p.name;
              pass=p.pass;
              username=p.username;
              email=p.email;
              coin=p.coin;
              exp=p.exp;
              level=p.level;
              shenaseP=p.shenaseP;
              maxExp=p.maxExp;
              break;
           }
          }


    infile.close();

     }
    }
    QString person::getName(){return name;}

    QString person::getUsername(){return username;}

    QString person::getEmail(){return email;}

    int person::getShenaseP(){return shenaseP;}

    int person::changeCoin(int _coin){
      return coin+=_coin;
    }

    int person::changeExp(int _Exp){
        return exp+=_Exp;
    }

    int person::changeLevel(){
        if(exp==maxExp){
         level++;
         maxExp=2*maxExp+10;
         exp=0;
        }
        return level;
    }

    int person::getMaxExp(){return maxExp;}

#endif // PERSON_H
