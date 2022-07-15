#include "Sound.h"

Sound::Sound()
{
	media_level = 0;
	call_level = 0;
	notification_level = 0;
	navigation_level = 0;
}

Sound::~Sound()
{
}

void Sound::nhap()
{
	cout << "Enter media level: ";
	this->media_level = checkDataInput();
	cout << "Enter call level: ";
	this->call_level = checkDataInput();
	cout << "Enter navigation level: ";
	this->navigation_level = checkDataInput();
	cout << "Enter notification level: ";
	this->notification_level = checkDataInput();
}

void Sound::xuat()
{
	cout << setw(20) << "Sound: " << setw(10) << "Media" << setw(20) << "Call" << setw(20) << "Navigation" << setw(20) << "Notification" << endl;
	cout << setw(20) << "       " << setw(10) << this->media_level << setw(20) << this->call_level << setw(20) << this->navigation_level << setw(20) << this->notification_level << endl;
}

void Sound::outputDataToFile(ostream& os)
{
	os << "Sound: " << this->media_level << "," << this->call_level << "," << this->navigation_level << "," << this->notification_level << ";";
}

void Sound::set_media_level(int data)
{
	this->media_level = data;
}

void Sound::set_call_level(int data)
{
	this->call_level = data;
}

void Sound::set_noti_level(int data)
{
	this->notification_level = data;
}

void Sound::set_navi_level(int data)
{
	this->navigation_level = data;
}

int Sound::get_media_level()
{
	return this->media_level;
}

int Sound::get_call_level()
{
	return this->call_level;
}

int Sound::get_navi_level()
{
	return this->navigation_level;
}

int Sound::get_noti_level()
{
	return this->notification_level;
}

bool Sound::checkRegex(string data, regex validData)
{
	if (regex_match(data, validData)) {
		return true;
	}
	else {
		return false;
	}
}

int Sound::checkDataInput()
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
