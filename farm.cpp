#include "farm.h"

Farm::Farm(int shenase):owner(shenase)
{


}


void Farm::write_milk(int shenase ,int tedad,int day){

struct milk{
int shenaseP;//male chekasei.
int day;//roz vared shodan be storage.
int tedad;//tedadi ke onroz vard storage shode.
bool spoiled;//kharab shode =>1 , kharab nashode=>0.
}m;
m.day=day;
m.shenaseP=shenase;
m.tedad=tedad;
m.spoiled=0;
ofstream outfile;//for writing in new file.
outfile.open("milk.txt",ios::app);
outfile.write((char*)&m,sizeof(m));
outfile.close();
}

int Farm::read_milk(int shenase,int day){

struct milk{
int shenaseP;//male chekasei.
int day;//roz vared shodan be storage.
int tedad;//tedadi ke onroz vard storage shode.
bool spoiled;//kharab shode =>1 , kharab nashode=>0.
}m;


ifstream infile;
infile.open("milk.txt",ios::in);
if(infile.is_open()){

infile.seekg(0,ios::end);
int size=infile.tellg();
infile.seekg(0,ios::beg);
while(infile.tellg()<size){
    infile.read((char*)&m,sizeof(m));
    if(m.shenaseP==shenase)
    if(!m.spoiled)
    if((day-m.day)>=10){
       m.spoiled=1;
       return -(m.tedad);//tedadi ke bayad az anbar kam beshe.
    }

}
}
 return 0;
}
