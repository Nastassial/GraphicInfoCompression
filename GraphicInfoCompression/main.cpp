#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;
int main() {
	{
		//	ifstream fin("input.txt");
		setlocale(LC_ALL, "");
		Matrix a(3, 3), t(3, 3), b(3, 3);
		cin >> b;
		cout << endl;
		a = a.pow_object(b, 2);
		cout << a << endl;
		cout << a + b << endl;
		cout << b - a << endl;
		cout << 2 * b << endl;
		cout << b.define_of_matrix(3) << endl;
		//cout << endl << t;
		system("pause");
	}
	return 0;
}