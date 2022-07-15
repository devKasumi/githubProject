#include "General.h"

General::General()
{
	language = "Empty";
	timezone = "Empty";
}

General::~General()
{
}

void General::nhap()
{
    getLanguageData();
    cout << "--- SELECT LANGUAGE DATA ---\n";
    for (int i = 0; i < this->ds_lan.size(); i++) {
        cout << i + 1 << ": " << this->ds_language[i] << endl;
    }
    cout << "You selection: ";
    checkLanguageInput();
    set_language_withindex();


    system("cls");
    getTimezoneData();
    cout << "--- SELECT TIMEZONE DATA ---\n";
    for (int i = 0; i < this->ds_tz.size(); i++) {
        cout << i + 1 << ": " << this->ds_timezone[i] << endl;
    }
    cout << "Your selection: ";
    checkTimeZoneInput();
    set_timezone_withindex();
}

void General::xuat()
{
    cout << setw(20) << "General: " << setw(15) << "Timezone" << setw(30) << "Language" << endl;
    cout << setw(20) << "         " << setw(15) << this->timezone << setw(30) << this->language << endl;
}

void General::outputDataToFile(ostream& os)
{
    os << "General: " << this->index_timezone << "," << this->index_language << ";";
}

void General::set_indextimezone(int data)
{
    this->index_timezone = data;
}

void General::set_indexlanguage(int data)
{
    this->index_language = data;
}

string General::get_timezone()
{
    return this->timezone;
}

string General::get_language()
{
    return this->language;
}

void General::set_timezone_withindex()
{
    int pos = this->ds_timezone[this->index_timezone - 1].find(" ");
    this->timezone = this->ds_timezone[this->index_timezone - 1].substr(0, pos);
}

void General::set_language_withindex()
{
    this->language = this->ds_language[this->index_language - 1];
}

void General::set_default_timezone(string data)
{
    this->timezone = data;
}

void General::set_default_language(string data)
{
    this->language = data;
}

bool General::checkRegex(string data, regex validData)
{
    if (regex_match(data, validData)) {
        return true;
    }
    else {
        return false;
    }
}

void General::checkLanguageInput()
{
    regex validInput{ ("([1-9]|[12][0-9]|3[0])") };
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
            this->index_language = stoi(data);
            check = true;
        }
    } while (check == false);
}

void General::checkTimeZoneInput()
{
    regex validInput{ ("([1-9]|[12][0-9]|3[0-2])") };
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
            this->index_timezone = stoi(data);
            check = true;
        }
    } while (check == false);
}

void General::getTimezoneData()
{
    ifstream in_timezone;
    string data_tz;
    in_timezone.open("timezones.txt");
    try {
        if (in_timezone.is_open()) {
            while (!in_timezone.eof()) {
                getline(in_timezone, data_tz);
                this->ds_tz.push_back(data_tz);
            }
        }
        else {
            throw exception();
        }
    }
    catch (const exception) {
        cerr << "Can't open timezones.txt file!\n";
    }
    in_timezone.close();
    for (int i = 0; i < ds_tz.size(); i++) {
        this->ds_timezone[i] = this->ds_tz[i];
    }
}

void General::getLanguageData()
{
    ifstream in;
    string data;
    in.open("languages.txt", std::ios::in);
    try {
        if (in.is_open()) {
            while (!in.eof()) {
                getline(in, data);
                this->ds_lan.push_back(data);
            }
        }
        else {
            throw exception();
        }
    }
    catch (const exception) {
        cerr << "Can't open languages.txt file!\n";
    }

    in.close();
    for (int i = 0; i < this->ds_lan.size(); i++) {
        this->ds_language[i] = this->ds_lan[i];
    }
    sort(this->ds_language, this->ds_language + 30);
}
