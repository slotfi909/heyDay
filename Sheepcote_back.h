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
	bool havecrop;
	int start_day_of_upgrading;
	int start_day_of_produce;
	int shenaseP;
	bool dastresi;

public:
	Sheepcote_back(int);
	~Sheepcote_back();

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	int getcurrent();
	int getcapacity();
	int getlevel();

	int addsheep(int);
	int removesheep(int);
	int starting_upgrade();
	void upgrading();
	int feeding();
	void cropready();
	int removal();
	void Update_file();
};