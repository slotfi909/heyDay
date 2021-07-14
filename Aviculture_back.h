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
	int start_day_of_produce;
	int shenaseP;
	bool isfed;
	bool havecrop;
	bool dastresi;

public:

	Aviculture_back(int);
	~Aviculture_back();

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	int getcurrent();
	int getcapacity();
	int getlevel();

	int addchicken(int num);
	int removechicken(int num);
	int starting_upgrade();
	void upgrading();//zamani
	int feeding();
	void cropready();//zamani
	int removal();
	void Update_file();
};
