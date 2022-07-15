#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <regex>

using namespace std;


class Sound
{
public:
	Sound();
	~Sound();
	void nhap();
	void xuat();
	void outputDataToFile(ostream& os);

	void set_media_level(int data);		// set media level data
	void set_call_level(int data);		// set call level data
	void set_noti_level(int data);		// set notification level data
	void set_navi_level(int data);		// set navigation level data

	int get_media_level();				// get media level data
	int get_call_level();				// get call level data
	int get_navi_level();				// get navigation level data
	int get_noti_level();				// get notification level data

	bool checkRegex(string data, regex validData);		// validate input data with regex
	int checkDataInput();								// get valid input data

private:
	int media_level;
	int call_level;
	int navigation_level;
	int notification_level;
};

