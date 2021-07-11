#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Aviculture_back
{
	int current;
	int capacity;
	int level;
	int start_day_of_upgrading;
	int start_day_of_laying;
	int shenaseP;
	bool isfed;
	bool haveegg;
public:

	Aviculture_back(int);

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	int getcurrent();
	int getcapacity();
	int getlevel();
	int getstart_day_of_upgrading();

	int addchicken(int num);
	int starting_upgrade();
	void upgrading();
	void feeding();
	void eggready();
	void removal();
	void Update_file();
};
