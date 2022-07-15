#include "Setting.h"

Setting::Setting()
{
	car_name = "Empty";
	email = "Empty";
	personal_key = "0";
	odo = 0;
	remind_service = 0;
}

Setting::~Setting()
{
}

void Setting::nhap()
{
	cout << "Enter Owner Name: ";
	getline(cin >> ws, this->car_name);
	cout << "Enter Personal Key: ";
	checkPersonalKeyInput();
	cout << "Enter Email: ";
	checkEmailInput();
	cout << "Enter ODO Number: ";
	this->odo = checkDataInput();
	cout << "Enter Remind Service: ";
	this->remind_service = checkDataInput();
}

void Setting::xuat()
{
	cout << setw(20) << "Owner name" << setw(10) << "Email" << setw(30) << "Key number" << setw(15) << "ODO number" << setw(25) << "Remind service (km)" << endl;
	cout << setw(20) << this->car_name << setw(25) << this->email << setw(13) << this->personal_key << setw(13) << this->odo << setw(20) << this->remind_service << endl;
}

void Setting::outputDataToFile(ostream& os)
{
	os << "Common: " << this->car_name << "," << this->personal_key << "," << this->email << "," << this->odo << "," << this->remind_service << ";";
}

void Setting::setCarName(string data)
{
	this->car_name = data;
}

void Setting::setPersonalKey(string data)
{
	this->personal_key = data;
}

void Setting::setEmail(string data)
{
	this->email = data;
}

void Setting::setODO(int data)
{
	this->odo = data;
}

void Setting::setRemindService(int data)
{
	this->remind_service = data;
}

string Setting::getCarName()
{
	return this->car_name;
}

string Setting::getPersonalKey()
{
	return this->personal_key;
}

string Setting::getEmail()
{
	return this->email;
}

int Setting::getODO()
{
	return this->odo;
}

int Setting::getRemindService()
{
	return this->remind_service;
}

bool Setting::checkRegex(string data, regex validData)
{
	if (regex_match(data, validData)) {
		return true;
	}
	else {
		return false;
	}
}

void Setting::checkPersonalKeyInput()
{
	regex validPersonalKey{ ("[0-9]{8}") };
	string personalKey = "";
	bool check = true;
	do {
		try {
			getline(cin >> ws, personalKey);
			if (!checkRegex(personalKey, validPersonalKey)) {
				cout << "Invalid Personal Key, please check and try again!\n";
				check = false;
			}
			else {
				throw 909;
			}
		}
		catch (...) {
			this->personal_key = personalKey;
			check = true;
		}
	} while (check == false);
}

void Setting::checkEmailInput()
{
	regex validEmail{ ("[a-zA-Z0-9_\.]+@([a-zA-Z]{3,5})+\.([a-zA-Z]{3,4})+(\.[a-zA-Z]+)*") };
	string email = "";
	bool check = true;
	do {
		try {
			getline(cin >> ws, email);
			if (!checkRegex(email, validEmail)) {
				cout << "Invalid Email, please check and try again!\n";
				check = false;
			}
			else {
				throw 909;
			}
		}
		catch (...) {
			this->email = email;
			check = true;
		}
	} while (check == false);
}

int Setting::checkDataInput()
{
	regex validInput{ ("[1-9]{1,6}") };
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
