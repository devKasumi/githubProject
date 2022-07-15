#include "Display.h"

Display::Display()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display()
{
}

void Display::nhap()
{
	cout << "Enter Light Level: ";
	this->light_level = checkDataInput();
	cout << "Enter Screen Light Level: ";
	this->screen_light_level = checkDataInput();
	cout << "Enter Taplo Light Level: ";
	this->taplo_light_level = checkDataInput();
}

void Display::xuat()
{
	cout << setw(20) << "Display: " << setw(10) << "Light" << setw(20) << "Screen light" << setw(20) << "Taplo light" << endl;
	cout << setw(20) << "         " << setw(10) << this->light_level << setw(20) << this->screen_light_level << setw(20) << this->taplo_light_level << endl;
}

void Display::outputDataToFile(ostream& os)
{
	os << "Display: " << this->light_level << "," << this->screen_light_level << "," << this->taplo_light_level << ";";
}

void Display::set_light_level(int data)
{
	this->light_level = data;
}

void Display::set_screen_light_level(int data)
{
	this->screen_light_level = data;
}

void Display::set_taplo_light_level(int data)
{
	this->taplo_light_level = data;
}

int Display::get_light_level()
{
	return this->light_level;
}

int Display::get_screen_light_level()
{
	return this->screen_light_level;
}

int Display::get_taplo_light_level()
{
	return this->taplo_light_level;
}

bool Display::checkRegex(string data, regex validData)
{
	if (regex_match(data, validData)) {
		return true;
	}
	else {
		return false;
	}
}

int Display::checkDataInput()
{
	regex validInput{ ("^[0-9][1-9]?$|^100$") };
	string data = "";
	bool check = true;
	do {
		try {
			getline(cin >> ws, data);
			if (!checkRegex(data, validInput)) {
				cout << "Invalid Input, please check and try again!\n";
				check = false;
			}
			else {
				throw 909;
			}
		}
		catch (...) {
			return stoi(data);
			check = true;
		}
	} while (check == false);
}
