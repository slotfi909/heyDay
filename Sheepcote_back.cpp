#include "Sheepcote_back.h"
Sheepcote_back::Sheepcote_back(int _shenaseP) {
	current = 0;
	capacity = 2;
	level = 1;
	start_day_of_upgrading = -1;
	isfed = false;
	havewool = false;
	shenaseP = _shenaseP;
}

void Sheepcote_back::setcurrent(int _current) { current = _current; }
void Sheepcote_back::setcapacity(int _capacity) { capacity = _capacity; }
void Sheepcote_back::setlevel(int _level) { level = _level; }
int Sheepcote_back::getcurrent() { return current; }
int Sheepcote_back::getcapacity() { return capacity; }
int Sheepcote_back::getlevel() { return level; }
int Sheepcote_back::getstart_day_of_upgrading() { return start_day_of_upgrading; }

int Sheepcote_back::addsheep(int num) {
	if ((capacity - current >= num) && !isfed && !havewool) {
		current += num;
		return 1;
	}
	return -1;
}

int Sheepcote_back::starting_upgrade() {
	if (/*getcoin()>=50 && getnail()>=3 && getlevel()>=7  && getshovel()>=1*/)
	{
		start_day_of_upgrading = /*getday()*/;
		return 1;
		//va tabe haii brai kam kardane in teadad az anbar
	}
	return -1;
}

void Sheepcote_back::upgrading() {
	if (/*getday()*/ -start_day_of_upgrading >= 9) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
	}
}

void Sheepcote_back::feeding() {
	if (!havewool)
		if ()//ye tabe dakhel anbar lazeme ke  tedad yonje mord nazara begire va age dasht kam kone az zarfite khodesh nadash -1 return kone(1*current)
		{
			start_day_of_get_food = /*getday()*/;
			isfed = true;
		}
}

void Sheepcote_back::woolready() {
	if (isfed && (/*getday()*/-start_day_of_get_food >= 10) && /*getcoin()*/ >= current) {
		havewool = true;
		isfed = false;
		start_day_of_get_food = -1;
		//tabe baraii kam kardane coin;
	}


}

void Sheepcote_back::removal() {
	if (havewool&&/*getmilk()>=current*/) {
		//setwool(current khodesh+current);
		havewool = false;
	}
}

void Sheepcote_back::Update_file() {

	struct temp {
		int current;
		int capacity;
		int level;
		int start_day_of_upgrading;
		int start_day_of_get_food;
		int shenaseP;
		bool isfed;
		bool havewool;
	}p;

	ofstream outfile;//for writing in new file.
	ifstream infile;//for reading.

	infile.open("Aviculture_back.txt", ios::in);
	if (infile.is_open()) {
		outfile.open("Aviculture_back-temp.txt", ios::out);//make file.
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
				p.start_day_of_get_food = start_day_of_get_food;
				p.isfed = isfed;
				p.havewool = havewool;
				p.shenaseP = shenaseP;
			}
			outfile.write((char*)&p, sizeof(p));
		}
		outfile.close();
		infile.close();
		remove("Aviculture_back.txt");
		rename("Aviculture_back-temp.txt", "Aviculture_back.txt");
	}
}