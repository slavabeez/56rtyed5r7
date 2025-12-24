#include <iostream>
#include <cmath>
#include <iomanip>

const double M_PI = 3.14159265358979323846;

/// <summary>
/// Вычисляет площадь треугольника по формуле Герона
/// </summary>
/// <param name="a">Длина первой стороны треугольника</param>
/// <param name="b">Длина второй стороны треугольника</param>
/// <param name="c">Длина третьей стороны треугольника</param>
/// <returns>Площадь треугольника</returns>
/// <remarks>Если треугольник не существует, возвращает -1</remarks>
double plosh(double& a) {

    if (a < 0) {
        std::cout << "ошибка радиус не может быть отрицательным" << std::endl;
        return 0;
    }
    int S;
    S = M_PI * pow(a, 2);
    return S;
}


int main()
{
    setlocale(0, "");
    double r, rr;
    std::cout << "введите радиус круга: ";
    std::cin >> r;
    rr = plosh(r);
    if (rr != 0) {
        std::cout << "радиус круга равен = " << std::fixed << std::setprecision(10) << rr;
    }

}
