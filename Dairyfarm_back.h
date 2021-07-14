#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Dairyfarm_back
{
	int current;
	int capacity;
	int level;
	int start_day_of_upgrading;
	int start_day_of_produce;
	int shenaseP;
	bool isfed;
	bool havecrop;
	bool dastresi;

public:

	Dairyfarm_back(int);
	~Dairyfarm_back();
	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	int getcurrent();
	int getcapacity();
	int getlevel();


	int addcow(int);
	int removecow(int);
	int starting_upgrade();
	void upgrading();
	int feeding();
	void cropready();
	int removal();
	void Update_file();

};

