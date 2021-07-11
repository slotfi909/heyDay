#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Sheepcote_back
{
	int current;
	int capacity;
	int level;
	bool isfed;
	bool havewool;
	int start_day_of_upgrading;
	int start_day_of_get_food;
	int shenaseP;
public:
	Sheepcote_back(int);

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	int getcurrent();
	int getcapacity();
	int getlevel();
	int getstart_day_of_upgrading();

	int addsheep(int);
	int starting_upgrade();
	void upgrading();
	void feeding();
	void woolready();
	void removal();
	void Update_file();
};