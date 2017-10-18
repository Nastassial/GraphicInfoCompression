#include "Matrix.h"
void Matrix::show() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << mass[i][j] << " ";
		cout << endl;
	}
}
Matrix::Matrix(int a_n, int a_m) {
	n = a_n;
	m = a_m;
	mass = new int*[n];
	for (int i = 0; i < n; i++)
		mass[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = 0;
}
Matrix::Matrix() {
	n = 0;
	m = 0;
	mass = NULL;
}
Matrix::~Matrix() {
	delete[]mass;
}
Matrix Matrix::operator=(const Matrix& obj) {
	if (this == &obj)
		return obj; //a=a; //a.operator=(a); 
	delete[]mass;	//a=b
	n = obj.n;
	m = obj.m;
	mass = new int*[n];
	for (int i = 0; i < n; i++)
		mass[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = obj.mass[i][j];
	return *this;
}
Matrix::Matrix(const Matrix& obj) {
	n = obj.n;
	m = obj.m;
	mass = new int*[n];
	for (int i = 0; i < n; i++)
		mass[i] = new int[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = obj.mass[i][j];
}
Matrix Matrix::operator+(Matrix b) {
	if (n == b.n&&m == b.m) {
		Matrix result(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				result.mass[i][j] = mass[i][j] + b.mass[i][j];
		return result;
	}
	else {
		Matrix result;
		return result;
	}
}
Matrix Matrix::operator+=(Matrix b) {
	if (n == b.n && m == b.m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				mass[i][j] = mass[i][j] + b.mass[i][j];
			}
		return *this;
	}
	else {
		Matrix result;
		return result;
	}
}
Matrix Matrix::operator+=(int b) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = mass[i][j] + b;
	return *this;
}
Matrix Matrix::operator-(Matrix b) {
	if (n == b.n&&m == b.m) {
		Matrix result(n, m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				result.mass[i][j] = mass[i][j] - b.mass[i][j];
		return result;
	}
	else {
		Matrix result;
		return result;
	}
}
Matrix& Matrix::operator+(int k) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = mass[i][j] + k;
	return *this;
}
Matrix& Matrix::operator-(int k) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = mass[i][j] - k;
	return *this;
}
Matrix operator*(int x, Matrix b) {
	Matrix result(b.n, b.m);
	for (int i = 0; i < b.n; i++)
		for (int j = 0; j < b.m; j++)
			result.mass[i][j] = x*b.mass[i][j];
	return result;
}

void Matrix::operator*=(int b) {
	*this = *this * b;
}

Matrix Matrix::operator*(int k) {
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result.mass[i][j] = mass[i][j] * k;
	return result;
}
Matrix Matrix::operator/(int k) {
	Matrix result(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			result.mass[i][j] = mass[i][j] / k;
	return result;
}
void Matrix::Input(std::istream& is) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			is >> mass[i][j];
}
int Matrix::define_of_matrix(int n_1) const
{
	int result = 0;
	switch (n_1)
	{
	case 1: result = mass[0][0]; break;
	case 2: result = mass[0][0] * mass[1][1] - mass[0][1] * mass[1][0]; break;
	case 3: result = (mass[0][0] * mass[1][1] * mass[2][2] + mass[0][1] * mass[1][2] * mass[2][0] + mass[1][0] * mass[2][1] * mass[0][2]) - (mass[2][0] * mass[1][1] * mass[0][2] + mass[1][0] * mass[0][1] * mass[2][2] + mass[2][1] * mass[1][2] * mass[0][0]); break;
	}
	return result;
}
std::istream& operator>>(std::istream& is, Matrix& obj) {
	for (int i = 0; i < obj.n; i++)
		for (int j = 0; j < obj.m; j++)
			is >> obj.mass[i][j];
	return is;
}
std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
	for (int i = 0; i < obj.n; i++) {
		for (int j = 0; j < obj.m; j++)
			cout << obj.mass[i][j] << " ";
		cout << endl;
	}
	return os;
}

Matrix Matrix::operator*(const Matrix& obj) {
	Matrix result(n, m);
	if (m != obj.n)
		return result;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < obj.m; j++)
			for (int k = 0; k < m; k++)
				result[i][j] += mass[i][k] * obj.mass[k][j];
	return result;
}
Matrix Matrix::pow_object(const Matrix& a, int c) {
	Matrix result(n, m);
	result = a;
	for (int i = 1; i < c; i++)
		result = result*a;
	return result;
}
int* Matrix::operator[](int index)
{
	return mass[index];
}