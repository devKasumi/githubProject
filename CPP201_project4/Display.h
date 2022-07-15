#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;


class Display
{
public:
	Display();
	~Display();
	void nhap();
	void xuat();
	void outputDataToFile(ostream& os);
	void set_light_level(int data);			// set gia tri light level
	void set_screen_light_level(int data);	// set gia tri screen light level
	void set_taplo_light_level(int data);	// set gia tri taplo light level
	int get_light_level();					// lay ra gia tri light level
	int get_screen_light_level();			// lay ra gia tri screen light level
	int get_taplo_light_level();			// lay ra gia tri taplo light level

	bool checkRegex(string data, regex validData);	// validate input data with regex
	int checkDataInput();							// lay ra valid input data
private:
	int light_level;
	int screen_light_level;
	int taplo_light_level;
};

