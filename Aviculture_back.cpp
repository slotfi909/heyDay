#include "Aviculture_back.h"
#pragma warning(disable: 4996)

Aviculture_back::Aviculture_back(int _shenaseP)
{
	current = 0;
	capacity = 2;
	level = 1;
	start_day_of_upgrading = -2;
	start_day_of_laying = -2;
	shenaseP = -1;
	isfed = false;
	haveegg = false;
	shenaseP = _shenaseP;
}

void Aviculture_back::setcurrent(int _current) { current = _current; }
void Aviculture_back::setcapacity(int _capacity) { capacity = _capacity; }
void Aviculture_back::setlevel(int _level) { level = _level; }
int Aviculture_back::getcurrent() { return current; }
int Aviculture_back::getcapacity() { return capacity; }
int Aviculture_back::getlevel() { return level; }
int Aviculture_back::getstart_day_of_upgrading() { return start_day_of_upgrading; }

int Aviculture_back::starting_upgrade()
{
	if (/*getcoin()>=10 && getnail()>=1 && getlevel()>=3*/) //dota tabe ke tedad chizaii ke mikhaiima begire va age dasht kam kone az zarfite khodesh nadash -1 return kone
	{
		start_day_of_upgrading = /*getday()*/;
		return 1;
		//va tabe haii brai kam kardane in teadad az anbar

	}
	return -1;
}

int Aviculture_back::addchicken(int num)
{
	if ((capacity - current >= num) && !isfed && !haveegg) {
		current += num;
		return 1;
	}
	return -1;
}

void Aviculture_back::upgrading() {
	if (/*getday()*/ -start_day_of_upgrading >= 3) {
		capacity *= 2;
		start_day_of_upgrading = -1;
		level++;
	}
}

void Aviculture_back::feeding() {
	if (!haveegg)
		if ()//ye tabe dakhel silo lazeme ke  tedad gandom mord nazara begire va age dasht kam kone az zarfite khodesh nadash -1 return kone
		{
			start_day_of_laying = /*getday()*/;
			isfed = true;
		}
}

void Aviculture_back::eggready() {
	if (isfed && (/*getday()*/-start_day_of_laying >= 2)) {
		haveegg = true;
		isfed = false;
		start_day_of_laying = -1;
	}
}

void Aviculture_back::removal() {
	if (haveegg&&/*getwheat()>=current*/) {
		//setwheat(current khodesh+current);
		haveegg = false;
	}
}

void Aviculture_back::Update_file() {

	struct temp {
		int current;
		int capacity;
		int level;
		int start_day_of_upgrading;
		int start_day_of_laying;
		int shenaseP;
		bool isfed;
		bool haveegg;
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
				p.start_day_of_laying = start_day_of_laying;
				p.isfed = isfed;
				p.haveegg = haveegg;
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