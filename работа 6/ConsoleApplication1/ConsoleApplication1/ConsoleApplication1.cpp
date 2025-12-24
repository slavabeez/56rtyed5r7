#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;


class AverageCalculator {
private:
    vector<double> nums;
public:
    void addNumber(double num) {
        nums.push_back(num);
        cout << "добавлено число " << num << endl;
    }
    void getAverage() {
        double sum = accumulate(nums.begin(), nums.end(), 0.0);
        double a = nums.size();

        sum /= a;
        cout << "среднее арифметическое чисел = " << sum << endl;
    }
    void getGeometricMean() {
        double a = nums.size();
        double product = 1.0;
        for (double num : nums) {
            product *= num;
        }
        double geometricMean = pow(product, 1.0 / a);
        cout << "среднее геометрическое чисел = " << geometricMean << endl;
    }
    void reset() {
            nums.clear();
            cout << "очищены все числа" << endl;
    }
};

int main()
{
    setlocale(0, "");
    AverageCalculator homo;
    int R;
    double a;
    while(true)
    {
        cout << "1 добавить число" << endl <<
                "2 вычислить среднее арифметическое" << endl <<
                "3 вычислить среднее геометрическое" << endl <<
                "4 очистить все числа" << endl<<
                "5 выход" << endl;
        cout << "выберите вариант действия: ";
        cin >> R;
        switch (R) {
        case 1:
            cout << "введите число ";
            cin >> a;
            homo.addNumber(a);
            break;
        case 2:
            homo.getAverage();
            break;
        case 3:
            homo.getGeometricMean();
            break;
        case 4:
            homo.reset();
            break;
        case 5:
            cout << "Завершение работы." << endl;
            return 0;
        default:
            cout << "не верное число"<<endl<<endl;
        }
    }
}
