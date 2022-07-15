#include <iostream>
#include "CarSetting.h"
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"
#include "Node.h"
#include "BST.h"
#include <sstream>
#include <vector>

using namespace std;

BST* btree;                             // BST chua duoc cap phat bo nho
int carCount = 0;
string personal_key_data[100];          // mang chua mscn
string owner_name_data[100];            // mang chua ten chu xe
vector<string> dataFromSettingFile;
vector<string> rawData;
vector<string> rawDataFromFile;

void Objswap(CarSetting* ptr_x, CarSetting* ptr_y);

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_Display();
void XuatThongTinCaiDat_General();
void XuatTatCaThongTinCaiDat();
void XuatThongTinRaFile();

void OptionMenu();
void OptionMenu2();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_Display();
void NhapThongTinCaiDat_General();

bool checkRegex(string data, regex validData);
int checkDataInputForMenu(regex validInput);
string checkYNSelection();
void checkCarArray();
bool checkEmptyFile(ifstream& inFile);

int validatePersonalKeyInput(int data);
string validateOwnerNameInput(string data);

void downloadDataFromFileSetting();
void countNumberOfCarsFromFile();

void OwnerNameSorting();

void UpdateData();

void deleteDataFromBST();

int main()
{
    downloadDataFromFileSetting();
    countNumberOfCarsFromFile();

    int select = 0;
    do {
        regex validInput{ ("[1-3]{1}") };
        system("cls");
        cout << "--- SELECT MENU ---\n";
        cout << "1. Input Setting Information\n";
        cout << "2. Print Setting Information\n";
        cout << "3. Exit\n";
        cout << "You Selection: ";
        select = checkDataInputForMenu(validInput);
        switch (select)
        {
        case 1: {
            system("cls");
            NhapThongTinCaiDat();
            break;
        }
        case 2: {
            system("cls");
            XuatThongTinCaiDat();
            break;
        }
        case 3:
            system("cls");
            XuatThongTinRaFile();
            cout << "Tam Biet!\n";
            exit(0);
            break;
        default:
            break;
        }
    } while (select != 3);


    return 0;
}



void NhapThongTinCaiDat()
{
    int select;
    do {
        regex validInput{ ("[1-4]{1}") };
        system("cls");
        cout << "--- SELECT MENU ---\n";
        cout << "1. Display Setting\n";
        cout << "2. Sound Setting\n";
        cout << "3. General Setting\n";
        cout << "4. Exit\n";
        cout << "Your Selection: ";
        select = checkDataInputForMenu(validInput);
        switch (select)
        {
        case 1: {
            system("cls");
            cout << "--- ban nhap thong tin display ---\n";
            NhapThongTinCaiDat_Display();
            break;
        }
        case 2: {
            system("cls");
            cout << "--- ban nhap thong tin sound ---\n";
            NhapThongTinCaiDat_Sound();
            break;
        }
        case 3: {
            system("cls");
            cout << "--- ban nhap thong tin general ---\n";
            NhapThongTinCaiDat_General();
            break;
        }
        case 4:
            break;
        default:
            break;
        }
    } while (select != 4);
}

void XuatThongTinCaiDat()
{
    int select;
    do {
        regex validInput{ ("[1-5]{1}") };
        system("cls");
        cout << "--- SELECT MENU ---\n";
        cout << "1. Print Display Setting Information\n";
        cout << "2. Print Sound Setting Information\n";
        cout << "3. Print General Setting Information\n";
        cout << "4. Print All Setting Information\n";
        cout << "5. Exit\n";
        cout << "Your Selection: ";
        select = checkDataInputForMenu(validInput);
        switch (select)
        {
        case 1: {
            system("cls");
            XuatThongTinCaiDat_Display();
            cout << endl;
            break;
        }
        case 2: {
            system("cls");
            XuatThongTinCaiDat_Sound();
            cout << endl;
            break;
        }
        case 3: {
            system("cls");
            XuatThongTinCaiDat_General();
            cout << endl;
            break;
        }
        case 4: {
            system("cls");
            XuatTatCaThongTinCaiDat();
            cout << endl;
            break;
        }
        case 5:
            break;
        default:
            break;
        }
    } while (select != 5);
}

void XuatThongTinCaiDat_Sound()
{
    int select = 0;
    do {
        regex validInput{ ("[1-4]{1}") };
        OptionMenu();
        select = checkDataInputForMenu(validInput);
        system("cls");
        switch (select)
        {
        case 1: {
            do {
                regex ValidInput2{ ("[1-3]{1}") };
                OptionMenu2();
                select = checkDataInputForMenu(ValidInput2);
                system("cls");
                switch (select)
                {
                case 1: {
                    cout << "--- Sound Setting ---\n";
                    btree->inOrderSoundSetting();
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 2: {
                    btree->BTreeData();
                    OwnerNameSorting();
                    cout << "--- Sound Setting ---\n";
                    for (int i = 0; i < btree->CarData.size(); i++) {
                        btree->CarData[i]->xuat();
                        btree->CarData[i]->getSound()->xuat();
                    }
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 3: 
                    break;
                default:
                    break;
                }
            } while (select != 3);
            break;
        }
        case 2: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                int inputVal = 0;
                system("cls");
                inputVal = validatePersonalKeyInput(inputVal);
                system("cls");
                cout << "--- Sound Information ---\n";
                btree->SearchPersonalKey(to_string(inputVal))->Car->xuat();
                btree->SearchPersonalKey(to_string(inputVal))->Car->getSound()->xuat();
            }
            UpdateData();
            break;
        }
        case 3: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                system("cls");
                string ownerName = "";
                ownerName = validateOwnerNameInput(ownerName);
                system("cls");
                btree->SearchOwnerNameData(ownerName);
                cout << "--- Sound Information ---\n";
                for (int i = 0; i < btree->OwnerNameData.size(); i++) {
                    btree->OwnerNameData[i]->Car->xuat();
                    btree->OwnerNameData[i]->Car->getSound()->xuat();
                }
            }
            UpdateData();
            break;
        }
        case 4: 
            break; 
        default:
            break;
        }
    } while (select != 4);
}

void XuatThongTinCaiDat_Display()
{
    int select = 0;
    do {
        regex validInput{ ("[1-4]{1}") };
        OptionMenu();
        select = checkDataInputForMenu(validInput);
        system("cls");
        switch (select)
        {
        case 1: {
            do {
                regex ValidInput2{ ("[1-3]{1}") };
                OptionMenu2();
                select = checkDataInputForMenu(ValidInput2);
                system("cls");
                switch (select)
                {
                case 1: {
                    cout << "--- Display Setting ---\n";
                    btree->inOrderDisplaySetting();
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 2: {
                    btree->BTreeData();
                    OwnerNameSorting();
                    cout << "--- Display Setting ---\n";
                    for (int i = 0; i < btree->CarData.size(); i++) {
                        btree->CarData[i]->xuat();
                        btree->CarData[i]->getDisplay()->xuat();
                    }
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 3: 
                    break;  
                default:
                    break;
                }
            } while (select != 3);
            break;
        }
        case 2: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                regex validPersonalKey{ ("[0-9]{8}") };
                int inputVal = 0;
                system("cls");
                inputVal = validatePersonalKeyInput(inputVal);
                system("cls");
                cout << "--- Display Information ---\n";
                btree->SearchPersonalKey(to_string(inputVal))->Car->xuat();
                btree->SearchPersonalKey(to_string(inputVal))->Car->getDisplay()->xuat();
            }
            UpdateData();
            break;
        }
        case 3: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                system("cls");
                string ownerName = "";
                ownerName = validateOwnerNameInput(ownerName);
                system("cls");
                btree->SearchOwnerNameData(ownerName);
                cout << "--- Display Information ---\n";
                for (int i = 0; i < btree->OwnerNameData.size(); i++) {
                    btree->OwnerNameData[i]->Car->xuat();
                    btree->OwnerNameData[i]->Car->getDisplay()->xuat();
                }
                
            }
            UpdateData();
            break;
        }
        case 4:
            break;
        default:
            break;
        }
    } while (select != 4);
}

void XuatThongTinCaiDat_General()
{
    int select = 0;
    do {
        regex validInput{ ("[1-4]{1}") };
        OptionMenu();
        select = checkDataInputForMenu(validInput);
        system("cls");
        switch (select)
        {
        case 1: {
            do {
                regex ValidInput2{ ("[1-3]{1}") };
                OptionMenu2();
                select = checkDataInputForMenu(ValidInput2);
                system("cls");
                switch (select)
                {
                case 1: {
                    cout << "--- General Setting ---\n";
                    btree->inOrderGeneralSetting();
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 2: {
                    btree->BTreeData();
                    OwnerNameSorting();
                    cout << "--- General Setting ---\n";
                    for (int i = 0; i < btree->CarData.size(); i++) {
                        btree->CarData[i]->xuat();
                        btree->CarData[i]->getGeneral()->xuat();
                    }
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 3: 
                    break;
                default:
                    break;
                }
            } while (select != 3);
            break;
        }
        case 2: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                int inputVal = 0;
                system("cls");
                inputVal = validatePersonalKeyInput(inputVal);
                system("cls");
                cout << "--- Sound Information ---\n";
                btree->SearchPersonalKey(to_string(inputVal))->Car->xuat();
                btree->SearchPersonalKey(to_string(inputVal))->Car->getGeneral()->xuat();
            }
            UpdateData();
            break;
        }
        case 3: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                system("cls");
                string ownerName = "";
                ownerName = validateOwnerNameInput(ownerName);
                system("cls");
                btree->SearchOwnerNameData(ownerName);
                cout << "--- General Information ---\n";
                for (int i = 0; i < btree->OwnerNameData.size(); i++) {
                    btree->OwnerNameData[i]->Car->xuat();
                    btree->OwnerNameData[i]->Car->getGeneral()->xuat();
                }
            }
            UpdateData();
            break;
        }
        case 4:
            break;
        default:
            break;
        }
    } while (select != 4);
}

void XuatTatCaThongTinCaiDat()
{
    int select = 0;
    do {
        regex validInput{ ("[1-4]{1}") };
        OptionMenu();
        select = checkDataInputForMenu(validInput);
        system("cls");
        switch (select)
        {
        case 1: {
            do {
                regex ValidInput2{ ("[1-3]{1}") };
                OptionMenu2();
                select = checkDataInputForMenu(ValidInput2);
                system("cls");
                switch (select)
                {
                case 1: {
                    cout << "--- All Setting ---\n";
                    btree->inOrderAllSetting();
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 2: {
                    btree->BTreeData();
                    OwnerNameSorting();
                    cout << "--- All Setting ---\n";
                    for (int i = 0; i < btree->CarData.size(); i++) {
                        btree->CarData[i]->xuat();
                        btree->CarData[i]->getDisplay()->xuat();
                        btree->CarData[i]->getSound()->xuat();
                        btree->CarData[i]->getGeneral()->xuat();
                    }
                    cout << endl;
                    UpdateData();
                    break;
                }
                case 3:
                    break;
                default:
                    break;
                }
            } while (select != 3);
            break;
        }
        case 2: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                int inputVal = 0;
                system("cls");
                inputVal = validatePersonalKeyInput(inputVal);
                system("cls");
                cout << "--- All Information ---\n";
                btree->SearchPersonalKey(to_string(inputVal))->Car->xuat();
                btree->SearchPersonalKey(to_string(inputVal))->Car->getDisplay()->xuat();
                btree->SearchPersonalKey(to_string(inputVal))->Car->getSound()->xuat();
                btree->SearchPersonalKey(to_string(inputVal))->Car->getGeneral()->xuat();
            }
            UpdateData();
            break;
        }
        case 3: {
            if (carCount == 0) {
                cout << "We don't have any data yet!\n";
                cout << "Please enter information before using print menu!\n\n";
            }
            else {
                system("cls");
                string ownerName = "";
                ownerName = validateOwnerNameInput(ownerName);
                system("cls");
                btree->SearchOwnerNameData(ownerName);
                cout << "--- All Information ---\n";
                for (int i = 0; i < btree->OwnerNameData.size(); i++) {
                    btree->OwnerNameData[i]->Car->xuat();
                    btree->OwnerNameData[i]->Car->getDisplay()->xuat();
                    btree->OwnerNameData[i]->Car->getSound()->xuat();
                    btree->OwnerNameData[i]->Car->getGeneral()->xuat();
                }
            }
            UpdateData();
            break;
        }
        case 4:
            break;
        default:
            break;
        }
    } while (select != 4);
}

void XuatThongTinRaFile()
{
    ofstream outf;
    outf.open("Setting.txt", std::ios::out | std::ios::trunc);
    for (int i = 0; i < carCount; i++) {
        btree->SearchPersonalKey(personal_key_data[i])->Car->outputDataToFile(outf);
        btree->SearchPersonalKey(personal_key_data[i])->Car->getDisplay()->outputDataToFile(outf);
        btree->SearchPersonalKey(personal_key_data[i])->Car->getSound()->outputDataToFile(outf);
        btree->SearchPersonalKey(personal_key_data[i])->Car->getGeneral()->outputDataToFile(outf);
        outf << endl;
    }
    outf.close();
}

void OptionMenu()
{
    cout << "--- SELECT MENU ---\n";
    cout << "1. Print Information\n";
    cout << "2. Searching Information By Entering Your Personal Key\n";
    cout << "3. Searching Information By Entering Your Name\n";
    cout << "4. Exit\n";
    cout << "Your Selection: ";
}

void OptionMenu2()
{
    cout << "--- SELECT MENU ---\n";
    cout << "1. Personal Key Order\n";
    cout << "2. Owner Name Order\n";
    cout << "3. Exit\n";
    cout << "Your Selection: ";
}

void NhapThongTinCaiDat_Sound()
{
    UpdateData();
    countNumberOfCarsFromFile();        // dem so xe co trong file Setting.txt

    string continues = "n";

    do {
        system("cls");
        CarSetting* Car = new CarSetting();
        cout << " ENTER SOUND INFORMATION, CAR NUMBER " << carCount + 1 << endl;
        Car->nhap();        // nhap vao commoninfomation
        int pos = -1;
        for (int i = 0; i < carCount; i++) {
            if (personal_key_data[i] == Car->getPersonalKey()) {
                pos = i;
                break;
            }
        
        }

        if (pos == -1) {
            cout << "     " << "-> " << "This is car, data will be appended to your list\n";
            Car->getSound()->nhap();        // nhap vao sound information
            btree->Insert(Car);
            personal_key_data[carCount] = Car->getPersonalKey();
            owner_name_data[carCount] = Car->getCarName();
            carCount++;

        }
        else if (pos != -1 && pos == carCount) {
            cout << "     " << "-> " << "This Car already existed, data will be overwritten\n";
            Sound* newSound = new Sound();  // tao ra mot con tro moi khi nhap xe moi
            newSound->nhap();               // nhap vao sound information
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setCarName(Car->getCarName());
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setSound(newSound);
            personal_key_data[pos] = Car->getPersonalKey();
            owner_name_data[pos] = Car->getCarName();
            carCount++;
        }
        else {
            cout << "     " << "-> " << "This Car already existed, data will be overwritten\n";
            Sound* newSound = new Sound();  // tao ra mot con tro moi khi nhap xe moi
            newSound->nhap();               // nhap vao sound information
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setCarName(Car->getCarName());
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setSound(newSound);
            personal_key_data[pos] = Car->getPersonalKey();
            owner_name_data[pos] = Car->getCarName();
        }


        cout << "CONTINUNE CAR NUMBER " << carCount + 1 << " ? (y/n): ";
        continues = checkYNSelection();
        cout << endl;
    } while (continues == "y");

    XuatThongTinRaFile();
}

void NhapThongTinCaiDat_Display()
{
    UpdateData();
    countNumberOfCarsFromFile();        // dem so xe co trong file Setting.txt
    string continues = "n";

    do {
        system("cls");
        CarSetting* Car = new CarSetting();
        cout << " ENTER DISPLAY INFORMATION, CAR NUMBER " << carCount + 1 << endl;
        Car->nhap();                    // nhap vao conmmoninformation
        int pos = -1;
        for (int i = 0; i < carCount; i++) {
            if (personal_key_data[i] == Car->getPersonalKey()) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "     " << "-> " << "This is car, data will be appended to your list\n";
            Car->getDisplay()->nhap();  // nhap vao display information
            btree->Insert(Car);
            personal_key_data[carCount] = Car->getPersonalKey();
            owner_name_data[carCount] = Car->getCarName();
            carCount++;
        }
        else if (pos != -1 && pos == carCount) {
            cout << "     " << "-> " << "This Car already existed, data will be overwritten\n";
            Display* newDisp = new Display();   // tao ra mot con tro moi khi nhap xe moi
            newDisp->nhap();                    // nhap vao display information
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setCarName(Car->getCarName());
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setDisplay(newDisp);
            personal_key_data[pos] = Car->getPersonalKey();
            owner_name_data[pos] = Car->getCarName();
            carCount++;
        }
        else {
            cout << "     " << "-> " << "This Car already existed, data will be overwritten\n";
            Display* newDisp = new Display();   // tao ra mot con tro moi khi nhap xe moi
            newDisp->nhap();                    // nhap vao display information
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setCarName(Car->getCarName());
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setDisplay(newDisp);
            personal_key_data[pos] = Car->getPersonalKey();
            owner_name_data[pos] = Car->getCarName();
        }


        cout << "CONTINUE CAR NUMBER " << carCount + 1 << " ? (y/n): ";
        continues = checkYNSelection();
        cout << endl;
    } while (continues == "y");

    XuatThongTinRaFile();
}

void NhapThongTinCaiDat_General()
{
    UpdateData();
    countNumberOfCarsFromFile();        // dem so xe co trong file Setting.txt

    string continues = "n";

    do {
        system("cls");
        CarSetting* Car = new CarSetting();
        cout << " ENTER GENERAL INFORMATION, CAR NUMBER " << carCount + 1 << endl;
        Car->nhap();                            // nhap vao commoninformation
        int pos = -1;
        for (int i = 0; i < carCount; i++) {
            if (personal_key_data[i] == Car->getPersonalKey()) {
                pos = i;
                break;
            }
        }

        if (pos == -1) {
            cout << "     " << "-> " << "This is car, data will be appended to your list\n";
            Car->getGeneral()->nhap();          // nhap vao general information
            btree->Insert(Car);
            personal_key_data[carCount] = Car->getPersonalKey();
            owner_name_data[carCount] = Car->getCarName();
            carCount++;
        }
        else if (pos != -1 && pos == carCount) {
            cout << "     " << "-> " << "This Car already existed, data will be overwritten\n";
            General* newGeneral = new General();    // tao ra mot con tro moi khi nhap xe moi
            newGeneral->nhap();                     // nhap vao general information
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setCarName(Car->getCarName());
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setGeneral(newGeneral);
            personal_key_data[pos] = Car->getPersonalKey();
            owner_name_data[pos] = Car->getCarName();
            carCount++;
        }
        else {
            cout << "     " << "-> " << "This Car already existed, data will be overwritten\n";
            General* newGeneral = new General();    // tao ra mot con tro moi khi nhap xe moi
            newGeneral->nhap();                     // nhap vao general information 
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setCarName(Car->getCarName());
            btree->SearchPersonalKey(Car->getPersonalKey())->Car->setGeneral(newGeneral);
            personal_key_data[pos] = Car->getPersonalKey();
            owner_name_data[pos] = Car->getCarName();
        }

        cout << "CONTINUE CAR NUMBER " << carCount + 1 << " ? (y/n): ";
        continues = checkYNSelection();
        cout << endl;
    } while (continues == "y");

    XuatThongTinRaFile();
}

bool checkRegex(string data, regex validData)
{
    if (regex_match(data, validData)) {
        return true;
    }
    else {
        return false;
    }
}

int checkDataInputForMenu(regex validInput)
{
    bool check = true;
    do {
        string data;
        getline(cin >> ws, data);
        if (checkRegex(data, validInput)) {
            return stoi(data);
            check = true;
        }
        else {
            cout << "Invalid Input, please check and try again!\n";
            check = false;
        }
    } while (check == false);
}

string checkYNSelection()
{
    regex validInput{ ("(y|n){1}") };
    bool check = true;
    do {
        char ValidData[10];
        string data;
        getline(cin >> ws, data);
        if (checkRegex(data, validInput)) {
            return data;
            check = true;
        }
        else {
            cout << "Invalid Input, please check and try again!\n";
            check = false;
        }
    } while (check == false);
}

void checkCarArray()
{
    bool check = false;
    string continues = "n";
    do {
        if (carCount > 100) {
            cout << "You can not enter more car!\n";
            cout << "Do you want to exit the programm? (y/n): ";
            continues = checkYNSelection();
            if (continues == "y") {
                check = true;
                exit(0);
            }
            else {
                check = false;
            }
        }
        else {
            break;
        }
    } while (check == false);
}

bool checkEmptyFile(ifstream& inFile)
{
    if (inFile.peek() == ifstream::traits_type::eof())
    {
        return true;
    }
    else return false;
}

int validatePersonalKeyInput(int data)
{
    bool check = false;
    do {
        regex validPersonalKey{ ("[0-9]{8}") };
        cout << "Enter Personal Key: ";
        data = checkDataInputForMenu(validPersonalKey);
        for (int i = 0; i < carCount; i++) {
            if (to_string(data) == personal_key_data[i]) {
                check = true;
                return data;
                break;
            }
            else {
                system("cls");
                cout << "Personal Key not found, Please try again!\n";
                check = false;
            }
        }
    } while (check == false);
}

string validateOwnerNameInput(string data)
{
    bool check = false;
    do {
        cout << "Enter Full Name: ";
        getline(cin >> ws, data);
        for (int i = 0; i < carCount; i++) {
            if (data == owner_name_data[i]) {
                check = true;
                return data;
                break;
            }
            else {
                system("cls");
                cout << "Name not found, Please try again!\n";
                check = false;
            }
        }
    } while (check == false);
}

void downloadDataFromFileSetting()
{
    btree = new BST;                // cap phat bo nho cho btree
    string line;
    ifstream inf;
    inf.open("Setting.txt");
    try {
        if (checkEmptyFile(inf)) {
            throw 909;
        }
        else if (inf.is_open()) {
            while (!inf.eof()) {
                getline(inf, line);
                dataFromSettingFile.push_back(line);
            }
            inf.close();
        }
    }
    catch (int) {
        cerr << "File Setting.txt is empty!" << endl;
    }
    catch (...)
    {
    }

    if (dataFromSettingFile.empty()) {
        cout << "We don't have any data yet!\n\n";
    }
    else {
        for (int i = 0; i < dataFromSettingFile.size(); i++) {
            string token;
            istringstream ss(dataFromSettingFile[i]);
            while (getline(ss, token, ';')) {
                rawData.push_back(token);
            }
        }

        for (int i = 0; i < rawData.size(); i++) {
            if (rawData[i][0] == 'C') {
                rawData[i].erase(0, 8);
            }
            else if (rawData[i][0] == 'D') {
                rawData[i].erase(0, 9);
            }
            else if (rawData[i][0] == 'G') {
                rawData[i].erase(0, 9);
            }
            else {
                rawData[i].erase(0, 7);
            }
        }
        for (int i = 0; i < rawData.size(); i++) {
            string token;
            istringstream ss(rawData[i]);
            while (getline(ss, token, ',')) {
                rawDataFromFile.push_back(token);
            }
        }

        ofstream out;
        out.open("rawdata.txt", std::ios::out | std::ios::trunc);
        for (int i = 0; i < rawDataFromFile.size(); i++) {
            out << rawDataFromFile[i] << endl;
        }
        out.close();

        ifstream in;
        in.open("rawdata.txt");
        int count = 0;
        try {
            if (checkEmptyFile(in)) {
                throw 909;
            }
            else if (in.is_open()) {
                while (!in.eof()) {
                    string carName, personalKey, email, odoNum, remindService, lightLevel, scrLightLevel,
                        taploLightLevel, mediaLevel, callLevel, naviLevel, notiLevel, language, timezone = "";
                    CarSetting* Car = new CarSetting();
                    getline(in, carName);
                    Car->setCarName(carName);
                    owner_name_data[count] = Car->getCarName();
                    getline(in, personalKey);
                    Car->setPersonalKey(personalKey);
                    personal_key_data[count] = Car->getPersonalKey();
                    getline(in, email);
                    Car->setEmail(email);
                    getline(in, odoNum);
                    Car->setODO(stoi(odoNum));
                    getline(in, remindService);
                    Car->setRemindService(stoi(remindService));
                    getline(in, lightLevel);
                    Car->getDisplay()->set_light_level(stoi(lightLevel));
                    getline(in, scrLightLevel);
                    Car->getDisplay()->set_screen_light_level(stoi(scrLightLevel));
                    getline(in, taploLightLevel);
                    Car->getDisplay()->set_taplo_light_level(stoi(taploLightLevel));
                    getline(in, mediaLevel);
                    Car->getSound()->set_media_level(stoi(mediaLevel));
                    getline(in, callLevel);
                    Car->getSound()->set_call_level(stoi(callLevel));
                    getline(in, naviLevel);
                    Car->getSound()->set_navi_level(stoi(naviLevel));
                    getline(in, notiLevel);
                    Car->getSound()->set_noti_level(stoi(notiLevel));
                    getline(in, timezone);
                    Car->getGeneral()->getTimezoneData();
                    if (timezone == "0") {
                        Car->getGeneral();
                    }
                    else {
                        Car->getGeneral()->set_indextimezone(stoi(timezone));
                        Car->getGeneral()->set_timezone_withindex();
                    }
                    getline(in, language);
                    Car->getGeneral()->getLanguageData();
                    if (language == "0") {
                        Car->getGeneral();
                    }
                    else {
                        Car->getGeneral()->set_indexlanguage(stoi(language));
                        Car->getGeneral()->set_language_withindex();
                    }
                    btree->Insert(Car);
                    count++;
                }
                in.close();
            }
        }
        catch (int) {
            cerr << "File is empty!" << endl;
        }
        catch (...) {}
    }
}

void countNumberOfCarsFromFile()            // ham dem so xe tu file
{
    if (dataFromSettingFile.size() == 0) {
        carCount = static_cast<int>(dataFromSettingFile.size());
    }
    else {
        carCount = static_cast<int>(dataFromSettingFile.size()) - 1;
    }
}

void OwnerNameSorting()                     // ham sap xep du lieu theo ten chu xe
{
    for (int i = 0; i < carCount; i++) {
        for (int j = i + 1; j < carCount; j++) {
            if (btree->CarData[i]->getCarName() > btree->CarData[j]->getCarName()) {
                Objswap(btree->CarData[i], btree->CarData[j]);
            }
        }
    }
}

void UpdateData()                           // ham update data moi khi co gi do thay doi
{
    btree->OwnerNameData.clear();
    btree->CarData.clear();
    dataFromSettingFile.clear();
    rawData.clear();
    rawDataFromFile.clear();
    deleteDataFromBST();
    downloadDataFromFileSetting();
}

void deleteDataFromBST()                    // ham xoa cac node trong btree
{
    for (int i = 0; i < carCount; i++) {
        btree->deleteNode(personal_key_data[i]);
    }
}

void Objswap(CarSetting* ptr_x, CarSetting* ptr_y)      
{
    CarSetting temp;
    temp = *ptr_x;
    *ptr_x = *ptr_y;
    *ptr_y = temp;
}
