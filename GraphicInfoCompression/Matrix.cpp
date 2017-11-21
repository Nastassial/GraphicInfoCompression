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
	mass = new double*[n];
	for (int i = 0; i < n; i++)
		mass[i] = new double[m];
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
	mass = new double*[n];
	for (int i = 0; i < n; i++)
		mass[i] = new double[m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = obj.mass[i][j];
	return *this;
}
Matrix::Matrix(const Matrix& obj) {
	n = obj.n;
	m = obj.m;
	mass = new double*[n];
	for (int i = 0; i < n; i++)
		mass[i] = new double[m];
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

Matrix operator*(double x, Matrix b) {
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
	Matrix result(n, obj.m);
	if (m != obj.n)
		return result;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < obj.m; j++)
			for (int k = 0; k < m; k++)
				result[i][j] += mass[i][k] * obj.mass[k][j];
	return result;
}

Matrix Matrix::transponation() {
	Matrix result(m, n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			result[i][j] = mass[j][i];
	return result;
}

Matrix Matrix::pow(int c) {
	Matrix result(n, m);
	result = *this;
	for (int i = 1; i < c; i++)
		result = result*(*this);
	return result;
}

double Matrix::transform() {
	double denominator = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			denominator += mass[i][j] * mass[i][j];
	return denominator;
}

double* Matrix::operator[](int index)
{
	return mass[index];
}
