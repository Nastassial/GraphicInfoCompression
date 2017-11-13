#ifndef Matrix_H
#define Matrix_H
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
class Matrix {
private:
	int n;
	int m;
	double **mass;
public:
	Matrix();
	Matrix(int, int);
	Matrix(const Matrix&);
	Matrix operator=(const Matrix&);
	~Matrix();
	void show();
	int define_of_matrix(int) const;
	Matrix& operator-(int k);
	Matrix& operator+(int k);
	Matrix operator/(int k);
	Matrix operator+(Matrix b);
	Matrix operator+=(Matrix b);
	Matrix operator+=(int b);
	Matrix operator-(Matrix b);
	Matrix operator*(int k);
	void operator*=(int b);
	double* operator[](int);
	Matrix pow(int n);
	Matrix Matrix::operator*(const Matrix& obj);
	friend Matrix operator*(int n, Matrix b);
	//	friend Matrix operator*(Matrix a, Matrix  b);
	void Input(std::istream&);
	friend std::istream& operator>>(std::istream&, Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
};
#endif
