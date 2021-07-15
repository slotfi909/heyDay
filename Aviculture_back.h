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
	

public:

	Aviculture_back(int);
	~Aviculture_back();

	void setcurrent(int _current);
	void setcapacity(int _capacity);
	void setlevel(int _level);
	void set_start_day_of_upgrading(int _start_day_of_upgrading);
	void set_start_day_of_produce(int _start_day_of_produce);
	void setshenaseP(int _shenaseP);
	void setisfed(bool _isfed);
	void sethavecrop(bool _havecrop);

	int getcurrent();
	int getcapacity();
	int getlevel();
	int get_start_day_of_upgrading();
	int get_start_day_of_produce();
	int getshenaseP();
	bool getisfed();
	bool gethavecrop();

	int isfull();
	int addchicken(int num);
	int removechicken(int num);
	int starting_upgrade();
	void upgrading();//zamani
	int feeding();
	void cropready();//zamani
	int removal();
	void Update_file();//distructor
};
