#include "Dairyfarm_back.h"
Dairyfarm_back::Dairyfarm_back(int _shenaseP) {
	current = 0;
	capacity = 2;
	level = 1;
	start_day_of_upgrading = -1;
	isfed = false;
	havemilk = false;
	shenaseP = _shenaseP;
}

void Dairyfarm_back::setcurrent(int _current) { current = _current; }
void Dairyfarm_back::setcapacity(int _capacity) { capacity = _capacity; }
void Dairyfarm_back::setlevel(int _level) { level = _level; }
int Dairyfarm_back::getcurrent() { return current; }
int Dairyfarm_back::getcapacity() { return capacity; }
int Dairyfarm_back::getlevel() { return level; }
int Dairyfarm_back::getstart_day_of_upgrading() { return start_day_of_upgrading; }

int Dairyfarm_back::addcow(int num) {
	if ((capacity - current >= num) && !isfed && !havemilk) {
		current += num;
		return 1;
	}
	return -1;
}

int Dairyfarm_back::starting_upgrade() {
	if (/*getcoin()>=15 && getnail()>=2 && getlevel()>=5*/)
	{
		start_day_of_upgrading = /*getday()*/;
		return 1;
		//va tabe haii brai kam kardane in teadad az anbar

	}
	return -1;
}

void Dairyfarm_back::upgrading() {
	if (/*getday()*/ -start_day_of_upgrading >= 5) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
	}
}

void Dairyfarm_back::feeding() {
	if (!havemilk)
		if ()//ye tabe dakhel anbar lazeme ke  tedad yonje mord nazara begire va age dasht kam kone az zarfite khodesh nadash -1 return kone(2*current)
		{
			start_day_of_get_food = /*getday()*/;
			isfed = true;
		}
}

void Dairyfarm_back::milkready() {
	if (isfed && (/*getday()*/-start_day_of_get_food >= 3)) {
		havemilk = true;
		isfed = false;
		start_day_of_get_food = -1;
	}
}

void Dairyfarm_back::removal() {
	if (havemilk&&/*getmilk()>=current*/) {
		//setmilk(current khodesh+current);
		havemilk = false;
	}
}

void Dairyfarm_back::Update_file() {

	struct temp {
		int current;
		int capacity;
		int level;
		int start_day_of_upgrading;
		int start_day_of_get_food;
		int shenaseP;
		bool isfed;
		bool havemilk;
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
				p.havemilk = havemilk;
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