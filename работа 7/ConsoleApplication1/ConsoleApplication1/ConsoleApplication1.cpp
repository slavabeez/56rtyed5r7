#include <iostream>
#include <vector>
#include <cmath> 
#include <numeric>
#include <numbers>
using namespace std;

const double PI = 3.14159265358979323846;

struct working {
public:
    static double triangleArea(double& a, double& h) {
        double S;
        if (a <= 0 || h <= 0) {
            throw invalid_argument("Основание и высота должны быть положительными");
        }
        S = 2 / (a * h);
        cout << "площадь триугольника = " << S << endl;
        return S;
    }
    static double rectangleArea(double& a, double& b) {
        double S;
        if (a <= 0 || b <= 0) {
            throw invalid_argument("Длина и ширина должны быть положительными");
        }
        S = a * b;
        cout << "площадь прямоугольника = " << S << endl;
        return S;
    }
    static double circleArea(double& r) {
        double S;
        if (r <= 0) {
            throw invalid_argument("Радиус должен быть положительным");
        }
        S = pow(r, 2) * PI;
        cout << "площадь круга = " << S << endl;
        return S;
    }
    static double trapezoidArea(double& a, double& b, double& h) {
        double S;
        if (a <= 0 || b <= 0 || h <= 0) {
            throw invalid_argument("Основания и высота должны быть положительными");
        }
        S = ((a + b) * h) / 2;
        cout << "площадь трапеции = " << S << endl;
        return S;
    }
};

int main() {
    setlocale(0, "");
    working праркеар;
    int R;
    double a = 1, b = 1, h = 1;
    while (true)
    {
        cout << "1 площадь триугольника " << endl <<
            "2 площадь прямоугольника " << endl <<
            "3 площадь круга " << endl <<
            "4 площадь трапеции " << endl <<
            "5 выход " << endl;
        cout << "выберите вариант действия: ";
        cin >> R;
        try
        {
            switch (R) {
            case 1:
                cout << "введите число a,h ";
                cin >> a >> h;
                праркеар.triangleArea(a, h);
                break;
            case 2:
                cout << "введите число a,b ";
                cin >> a >> b;
                праркеар.rectangleArea(a, b);
                break;
            case 3:
                cout << "введите число a ";
                cin >> a;
                праркеар.circleArea(a);
                break;
            case 4:
                cout << "введите число a,b,h ";
                cin >> a >> b >> h;
                праркеар.trapezoidArea(a, b, h);
                break;
            case 5:
                cout << "Завершение работы." << endl;
                return 0;
            default:
                cout << "не верное число" << endl << endl;
            }
        }
        catch (const invalid_argument& e) {
            cout << "Ошибка: " << e.what() << endl;
        }

    }
}