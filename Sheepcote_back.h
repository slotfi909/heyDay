#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Sheepcote_back
{
	int current;
	int capacity;
	int level;
	int start_day_of_upgrading;
	int start_day_of_produce;
	int shenaseP;
	bool isfed;
	bool havecrop;
	bool upgrading;


public:

	Sheepcote_back(int);
	~Sheepcote_back();

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	void set_start_day_of_upgrading(int _start_day_of_upgrading);
	void set_start_day_of_produce(int _start_day_of_produce);
	void setshenaseP(int _shenaseP);
	void setisfed(bool _isfed);
	void sethavecrop(bool _havecrop);
	void setupgrading(bool _upgrading);

	int getcurrent();
	int getcapacity();
	int getlevel();
	int get_start_day_of_upgrading();
	int get_start_day_of_produce();
	int getshenaseP();
	bool getisfed();
	bool gethavecrop();
	bool getupgrading();

	int isfull();
	int addsheep(int);
	int removesheep(int);
	//int starting_upgrade();
	//void upgrading();
	//int feeding();
	//void cropready();
	//int removal();
	void Update_file();
};