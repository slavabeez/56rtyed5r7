#include <iostream>
using namespace std;

void da(int &a) {
	cout << a + 1 << endl;
	if (a == 9) {
		return;
	}
	da(++a);
}

int main()
{
	
	int a = 0;
	setlocale(0, "");
	for (int i = 0; i < 10; i++){
			cout << i + 1 << endl;
	}
	cout << endl;
	da(a);
}
