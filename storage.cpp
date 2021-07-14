#include "storage.h"
#include "milk.h"
storage::storage(){
capacity=5;
level=1;
numNail=1;
numAlfalfa=1;
numShovel=0;
numMilk=0;
numFleece=0;
isBeingUpgraded=0;
}

// functions
void storage::upgrade(person& player){
    bool canGetUpgraded=0;
   if(level<player.level)
    if(numNail>=level)
     if(numShovel>=level-1)
      if(player.coin>=(pow(level,3)*10))
         canGetUpgraded=1;

        if(canGetUpgraded){
                cout<<"are you sure?\nenter y for yes and n for no\n";
        char input;
        cin >>input;
        if(input=='n'){
            return;
             //upgrade didn't happen
        }
            isBeingUpgraded=1;
storageTime=time(0);
        cout<<"storage is upgrading(it takes 5 days to complete!)\n";


        }
        else
        cout<<"storage can't upgrade!";

}
int storage::getLevel(){return level;}
int storage::getCapacity(){return capacity;}
int storage::allMerchandises(){
//cout<<'\n'<<"numNail:"<<numNail<<'\n';
//cout<<'\n'<<"numFleece:"<<numFleece<<'\n';
//cout<<'\n'<<"numEgg:"<<numEgg<<'\n';
//cout<<'\n'<<"numMilk:"<<numMilk<<'\n';
//cout<<'\n'<<"numShovel:"<<numShovel<<'\n';
//cout<<'\n'<<"numAlfalfa:"<<numAlfalfa<<'\n';
return (numNail+numFleece+numEgg+numMilk+numShovel+numAlfalfa);
}
void storage::addNail(int numAddedNail){
        if(numAddedNail+allMerchandises()<=capacity){
           numNail+=numAddedNail;
        }
    else{
        cout<<"not enough capacity!";
    }
    }
void storage::addAlfalfa(int numAddedAlfalfa){
        if(numAddedAlfalfa+allMerchandises()<=capacity){

    numAlfalfa+=numAddedAlfalfa;
        }
    else{
        cout<<"not enough capacity!";
    }
    }
void storage::addShovel(int numAddedShovel){
      if(numAddedShovel+allMerchandises()<=capacity){
            numShovel+=numAddedShovel;

}
    else{
        cout<<"not enough capacity!";
    }
    }
void storage::addEgg(int numAddedEgg){
    if(numAddedEgg+allMerchandises()<=capacity){
    if(level>=2)
    numEgg+=numAddedEgg;
    else
        cout<<"can't add any egg due to low level!";
    }
    else{
        cout<<"not enough capacity!";
    }

    }
void storage::addMilk(milk AddedMilk){
        if(AddedMilk.getAmount()+allMerchandises()<=capacity){

   if(level>=4){
    numMilk+=AddedMilk.getAmount();
    for(int i=0;i<100;i++){
        if(milklist+i==0)
        milklist[i]=AddedMilk;

    }

    }
    else
        cout<<"can't add any milk due to low level!";
    }

    else{
        cout<<"not enough capacity!";
    }

}
void storage::addFleece(int numAddedFleece){
      if(numAddedFleece+allMerchandises()<=capacity){

  if(level>=6)
    numFleece+=numAddedFleece;
    else
        cout<<"can't add any fleece due to low level!";
      }
          else{
        cout<<"not enough capacity!";
    }
}
void storage::checkSpoiledMilk(){
for(int i=0;i<100;i++){
    if(time(0)>=10*24*3600+milklist[i].getDate()){ // if 10 days has passed since the produce date
       numMilk-=milklist[i].getAmount();
//        (milklist+i)=0;

    }
}


}
