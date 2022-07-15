#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include<string.h>
#include <regex>

using namespace std;

class Setting
{
public:
    Setting();
    ~Setting();
    virtual void nhap();
    virtual void xuat();
    void outputDataToFile(ostream& os);
    void setCarName(string data);
    void setPersonalKey(string data);
    void setEmail(string data);
    void setODO(int data);
    void setRemindService(int data);

    string getCarName();            // lay ra owner name input data
    string getPersonalKey();        // lay ra mscn input data
    string getEmail();              // lay ra email input data
    int getODO();                   // lay ra odo number input data
    int getRemindService();         // lay ra quang duong can den 

    bool checkRegex(string data, regex validData);      // validate input data with regex
    void checkPersonalKeyInput();                       // lay ra valid mscn input data
    void checkEmailInput();                             // lay ra valid email input data
    int checkDataInput();                               // tra ve valid input data
private:
    string car_name;
    string email;
    string personal_key;
    int odo;
    int remind_service;
};

