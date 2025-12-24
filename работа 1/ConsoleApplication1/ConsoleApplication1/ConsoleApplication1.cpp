#include <iostream>
using namespace std;

int main()
{
    setlocale(0, "");
    int a, b, c;
    cout << "введите а и b для сложения:" << endl;
    cin >> a >> b;
    c = a + b;
    cout << "результат: " << c;
}
