#include <iostream>
#include <fstream>
#include "Matrix.h"
using namespace std;
int main() {
	{
		setlocale(LC_ALL, "");
		Matrix a(3, 3), t(3, 3), b(3, 3);
		Matrix v(1,3);
		Matrix k(3,4);
		cin >> v;
		cin >> k;
		/*a = v.transponation();
		cout << a << endl;
		cin >> b;
		cout << b*a << endl;*/
		
		cout << endl;
		cout << v*k << endl;
		/*a = b.pow(3);
		cout << a << endl;
		cout << b.transponation() << endl;
		cout << b << endl;
		cout << a + b << endl;
		cout << b - a << endl;
		cout << 2 * b << endl;
		cout << b.define_of_matrix(3) << endl;
		*/
		system("pause");
	}
	return 0;
}