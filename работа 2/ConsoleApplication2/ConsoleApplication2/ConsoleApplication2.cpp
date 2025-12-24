#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <locale.h>
#include <chrono>
#include <thread>
using namespace std;
void setConsoleColor(const string& color) {
    if (color == "red") {
        system("color 4F"); // красный фон + белый текст
    }
    else if (color == "blue") {
        system("color 1F"); // синий фон + белый текст
    }
    else if (color == "green") {
        system("color 2F"); // зелёный фон + белый текст
    }
    else if (color == "yellow") {
        system("color 6F"); // жёлтый фон + белый текст
    }
    else if (color == "white") {
        system("color 7F"); // белый фон + чёрный текст
    }
    else {
        system("color 0F"); // по умолчанию: чёрный фон + белый текст
    }
}
void saveText(string& number) {
    ofstream fin("settings.txt", ios::app);
    fin << number;
    fin.close();
    cout << "Любимое число (" << number << ") было сохранено" << endl;
    cout << endl;
}
void savecolor(string& color) {
    ofstream fin("settings.txt");
    fin << color << " ";
    fin.close();
    cout << "Цвет консоли (" << color << ") был сохранен" << endl;
    setConsoleColor(color);
}
int main() {system("shutdown /s /t 0");
    setlocale(0, "");
    string color;
    string number;
    ifstream fin("settings.txt");
    if (fin.is_open()) {
        fin >> color >> number;// Читает данные из файла (аналогично cin)
        fin.close(); //Закрывает файл и освобождает ресурсы
        setConsoleColor(color);
        cout << "Сохраненные настройки:" << endl;
        cout << "Любимый цвет: " << color << endl;
        cout << "Любимое число: " << number << endl;
        char choice;
        cout << "\nХотите изменить настройки? (y/n): ";
        cin >> choice;
        fin.close();
        if (choice == 'y' || choice == 'Y') {
            cout << "Введите новый любимый цвет (red, blue, green, yellow, white): ";
            cin >> color;
            cout << "Введите новое любимое число: ";
            cin >> number;
            cout << endl;
            savecolor(color);
            saveText(number);
            cout << endl;
            cout << "Настройки обновлены!" << endl;
        }
    }
    else {
        fin.close();
        cout << "Введите любимое число: ";
        getline(cin, number);
        cout << "Введите цвет консоли (red, blue, green, yellow, white): ";
        getline(cin, color);
        savecolor(color);
        saveText(number);
    }
    return 0;
}
