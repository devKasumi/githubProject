#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <regex>
#include <stdexcept>

using namespace std;


class General
{
public:
	General();
	~General();
	void nhap();
	void xuat();
	void outputDataToFile(ostream& os);

	void set_indextimezone(int data);		// set gia tri timezone
	void set_indexlanguage(int data);		// set gia tri language

	string get_timezone();				// lay ra gia tri timezone
	string get_language();				// lay ra gia tri language
	void set_timezone_withindex();
	void set_language_withindex();

	void set_default_timezone(string data);
	void set_default_language(string data);

	bool checkRegex(string data, regex validData);		// validate input data with regex
	void checkLanguageInput();							// lay ra valid language data
	void checkTimeZoneInput();							// lay ra valid timezone data

	void getTimezoneData();
	void getLanguageData();
private:
	string ds_language[30];
	string ds_timezone[32];
	string timezone;
	string language;
	int index_language = 0;
	int index_timezone = 0;
	vector<string> ds_lan;
	vector<string> ds_tz;
};

