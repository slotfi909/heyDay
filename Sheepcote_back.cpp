#include "Sheepcote_back.h"

struct temp {
	int current;
	int capacity;
	int level;
	int start_day_of_upgrading;
	int start_day_of_produce;
	int shenaseP;
	bool isfed;
	bool havecrop;

};

Sheepcote_back::Sheepcote_back(int _shenaseP) {

	temp A;

	ifstream fin;
	ofstream fout;
	fin.open("Sheepcote.txt");
	if (!fin) {
		fin.close();
		fout.open("Sheepcote.txt");
		fout.close();
		fin.open("Sheepcote.txt", ios::app);
	}
	bool find = 1;
	while (!fin.eof()) {
		fin.read((char*)&A, sizeof(temp));
		if (A.shenaseP == _shenaseP) {
			current = A.current;
			capacity = A.capacity;
			level = A.level;
			start_day_of_upgrading = A.start_day_of_upgrading;
			start_day_of_produce = A.start_day_of_produce;
			shenaseP = A.shenaseP;
			isfed = A.isfed;
			havecrop = A.havecrop;
			find = 0;
			break;
		}
	}
	fin.close();
	if (find) {    //first login
		current = 0;
		capacity = 2;
		level = 1;
		start_day_of_upgrading = -1;
		start_day_of_produce = -1;
		shenaseP = _shenaseP;
		isfed = false;
		havecrop = false;

		//..................
		A.current = 0;
		A.capacity = 2;
		A.level = 1;
		A.start_day_of_upgrading = -1;
		A.start_day_of_produce = -1;
		A.shenaseP = _shenaseP;
		A.isfed = false;
		A.havecrop = false;


		fout.open("Sheepcote.txt", ios::app);
		fout.write((char*)&A, sizeof(temp));
		fout.close();
	}
}

Sheepcote_back::~Sheepcote_back() {
	Update_file();
}

void Sheepcote_back::setcurrent(int _current) { current = _current; }
void Sheepcote_back::setcapacity(int _capacity) { capacity = _capacity; }
void Sheepcote_back::setlevel(int _level) { level = _level; }
void Sheepcote_back::set_start_day_of_upgrading(int _start_day_of_upgrading) { start_day_of_upgrading = _start_day_of_upgrading; }
void Sheepcote_back::set_start_day_of_produce(int _start_day_of_produce) { start_day_of_produce = _start_day_of_produce; }
void Sheepcote_back::setshenaseP(int _shenaseP) { shenaseP = _shenaseP; }
void Sheepcote_back::setisfed(bool _isfed) { isfed = _isfed; }
void Sheepcote_back::sethavecrop(bool _havecrop) { havecrop = _havecrop; }

int Sheepcote_back::getcurrent() { return current; }
int Sheepcote_back::getcapacity() { return capacity; }
int Sheepcote_back::getlevel() { return level; }
int Sheepcote_back::get_start_day_of_upgrading() { return start_day_of_upgrading; }
int Sheepcote_back::get_start_day_of_produce() { return start_day_of_produce; }
int Sheepcote_back::getshenaseP() { return shenaseP; }
bool Sheepcote_back::getisfed() { return isfed; }
bool Sheepcote_back::gethavecrop() { return havecrop; }

int Sheepcote_back::isfull() {
	if (current == capacity)
		return 0;
	return capacity - current;
}

int Sheepcote_back::addsheep(int num) {
	if (capacity - current < num)
		return 2;//nabod zarfiat;
	else if (isfed)
		return 3;//darhal ghaza khordan
	else if (havecrop)
		return 4;//mahsolat jam avari nashodeand

	current += num;
	return 1;
}

int Sheepcote_back::removesheep(int num) {
	if (current < num)
		return 2;//in teadad morgh mojod nist;
	else if (isfed)
		return 3;//darhal ghaza khordan
	else if (havecrop)
		return 4;//mahsolat jam avari nashodeand
	current -= num;
	return 1;
}
/*
int Sheepcote_back::starting_upgrade() {
	if (owner.getlevel() < 7)
		return 2
	else if (getnail() < 3)
		return 3;
	else if (owner.getcoin() < 50)
		return 4;
	else if (get.shavel() < 1)
		return 5;

	start_day_of_upgrading = /*getday();

	//owner.setCoin(owner.getCoin() - 50);
	//owner.setExp(owner.getExp() + 15);
	//va anbar ke codesh felan nist;
	return 1;
}
*/
//zamani....
void Sheepcote_back::upgrading() {
	if (/*getday()*/ -start_day_of_upgrading >= 9) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
	}
}
/*
int Sheepcote_back::feeding() {
	if (current == 0)
		return 2;//morghi braye ghaza dadan nist;
	else if (havecrop)
		return 3;//mahsolat jam avari nashodeand
	else if (/*tabe ke check kone anbar be andaze curren yonje dare ya na)
		return 4;//yonje kafi nist;

	start_day_of_produce = /*getday();
	isfed = true;
	//yonje ra kam mikonim;
	//owner.setExp(owner.getExp() + 7);
}
*/
//zamani.........
void Sheepcote_back::cropready() {
	if (isfed && (/*getday()*/-start_day_of_produce >= 10) {
		havecrop = true;
	    isfed = false;
    	start_day_of_produce = -1;
	}
}
/*
int Sheepcote_back::removal() {
	if (isfed && !havecrop)
		return 2; //farayande dorost kardan shir tamam nashode ast;
	else if (!havecrop)
		return 3; //mahsoli baray bardasht nist;
	else if (/*check inke aya anbar zarfiat pashm be teadad current dare aya?)
		return 4; //anbar ja nadard;
	else if (owner.getcoin() < current)
		return 5;//coin kafi nist;

		//set pashm dakhel anbar
	//owner.setExp(owner.getExp() + 9);

	//owner.setCoin(owner.getCoin() - current);
	havecrop = false;
	return 1;
}
*/
void Sheepcote_back::Update_file() {

	temp p;

	ofstream outfile;//for writing in new file.
	ifstream infile;//for reading.

	infile.open("Sheepcote.txt", ios::in);
	if (infile.is_open()) {
		outfile.open("Sheepcote-temp.txt", ios::out);//make file.
		infile.seekg(0, ios::end);
		int size = infile.tellg();
		infile.seekg(0, ios_base::beg);
		while (infile.tellg() < size) {
			infile.read((char*)&p, sizeof(p));
			if (shenaseP == p.shenaseP) {
				p.current = current;
				p.capacity = capacity;
				p.level = level;
				p.start_day_of_upgrading = start_day_of_upgrading;
				p.start_day_of_produce = start_day_of_produce;
				p.isfed = isfed;
				p.havecrop = havecrop;
				p.shenaseP = shenaseP;
			}
			outfile.write((char*)&p, sizeof(p));
		}
		outfile.close();
		infile.close();
		remove("Sheepcote.txt");
		rename("Sheepcote-temp.txt", "Sheepcote.txt");
	}
}