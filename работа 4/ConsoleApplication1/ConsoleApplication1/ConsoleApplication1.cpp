#include <windows.h>
#include <shlobj.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <windows.h>
#include <shlobj.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
using namespace std;

void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 4");
    }
    else if (color == "blue") {
        system("color 1");
    }
    else if (color == "green") {
        system("color 2");
    }
    else if (color == "yellow") {
        system("color 6");
    }
    else if (color == "white") {
        system("color 7");
    }
    else if (color == "black") {
        system("color 0");
    }
    else {
        system("color 0");
    }
}

string getCurrentTime() {
    time_t now = time(0);
    char buffer[26];
    ctime_s(buffer, sizeof(buffer), &now);
    string timeStr(buffer);
    timeStr.pop_back();
    return timeStr;
}

string getDesktopPath() {
    char path[MAX_PATH];
    if (SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, path) == S_OK) {
        return string(path) + "\\";
    }
    return "";
}

bool loadSettings(string& color, string& city, string& lastChangeTime) {
    string settingsPath = getDesktopPath() + "settings.txt";
    ifstream fin(settingsPath);

    if (!fin.is_open()) {
        return false;
    }

    if (fin.peek() == EOF) {
        fin.close();
        return false;
    }

    string line, lastLine;
    while (getline(fin, line)) {
        if (!line.empty()) {
            lastLine = line;
        }
    }
    fin.close();

    if (lastLine.empty()) {
        return false;
    }

    size_t firstSpace = lastLine.find(' ');
    if (firstSpace == string::npos) {
        return false;
    }

    color = lastLine.substr(0, firstSpace);

    size_t secondSpace = lastLine.find(' ', firstSpace + 1);
    if (secondSpace == string::npos) {
        city = lastLine.substr(firstSpace + 1);
        lastChangeTime = "";
    }
    else {
        city = lastLine.substr(firstSpace + 1, secondSpace - firstSpace - 1);
        lastChangeTime = lastLine.substr(secondSpace + 1);
    }

    return true;
}

void saveSettings(const string& color, const string& city) {
    setlocale(0, "");
    string settingsPath = getDesktopPath() + "settings.txt";
    string timeStr = getCurrentTime();

    ofstream fout(settingsPath, ios::app);

    if (fout.is_open()) {
        fout << color << " " << city << " " << timeStr << endl;
        fout.close();
        cout << "Настройки сохранены!" << endl;
    }
    else {
        cout << "Ошибка сохранения!" << endl;
    }
}

void showCurrentSettings(const string& color, const string& city, const string& timeStr = "") {
    cout << "\nТекущие настройки:" << endl;
    cout << "Цвет текста: " << color << endl;
    cout << "Любимый город: " << city << endl;
    if (!timeStr.empty()) {
        cout << "Последнее изменение: " << timeStr << endl;
    }
}

void changeSettings(string& color, string& city) {
    setlocale(0, "");
    cout << "\nВведите цвет текста (red, blue, green, yellow, white, black): ";
    cin >> color;
    cout << "Введите любимый город: ";
    cin.ignore();
    getline(cin, city);

    saveSettings(color, city);
}

int main() {
    setlocale(0, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string color = "white";
    string city = "Москва";
    string lastChangeTime;

    string settingsPath = getDesktopPath() + "settings.txt";

    if (loadSettings(color, city, lastChangeTime)) {
        setConsoleColor(color);

        showCurrentSettings(color, city, lastChangeTime);

        char choice;
        cout << "\nИзменить настройки? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            changeSettings(color, city);

            setConsoleColor(color);

            loadSettings(color, city, lastChangeTime);
            showCurrentSettings(color, city, lastChangeTime);
        }
    }
    else {
        cout << "Настроек нет. Введите новые:\n";
        cout << "Введите цвет текста (red, blue, green, yellow, white, black): ";
        cin >> color;
        cout << "Введите любимый город: ";
        cin.ignore();
        getline(cin, city);

        saveSettings(color, city);

        setConsoleColor(color);

        showCurrentSettings(color, city, getCurrentTime());
    }

    while (true) {
        cout << "\n=== Меню ===" << endl;
        cout << "1. Изменить настройки" << endl;
        cout << "2. Показать настройки" << endl;
        cout << "3. Применить цвет" << endl;
        cout << "4. Выйти" << endl;
        cout << "Выберите: ";

        int menuChoice;
        cin >> menuChoice;

        switch (menuChoice) {
        case 1:
            changeSettings(color, city);
            loadSettings(color, city, lastChangeTime);
            break;
        case 2:
            showCurrentSettings(color, city, lastChangeTime);
            break;
        case 3:
            setConsoleColor(color);
            cout << "Цвет применен!" << endl;
            break;
        case 4:
            cout << "Выход..." << endl;
            return 0;
        default:
            cout << "Неверный выбор!" << endl;
            break;
        }
    }

    return 0;
}