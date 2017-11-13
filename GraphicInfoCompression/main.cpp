//#include <iostream>
#include <fstream>
//#include <opencv2/opencv.hpp>
#include "Matrix.h"
#include "Functions.h"

using namespace std;
using namespace cv;

int main() {
	setlocale(LC_ALL, "");

	Mat img = imread("lena.jpg");
	int n, m, p;
	cout << "¬ведите n:" << endl;
	cin >> n;
	cout << "¬ведите m:" << endl;
	cin >> m;
	cout << "¬ведите p:" << endl;
	cin >> p;
	int numberOfSegments = (img.rows * img.cols) / (n*m);
	int vectorSize = n*m * 3;
	int numberOFSegmentInRow = img.cols / m;
	Matrix vectorsX(numberOfSegments, vectorSize);
	vectorsX = createXVectors(img, n, m);
	Matrix W(vectorSize, p);
	W = createW(vectorSize, p);
	vectorsX.show();
	cout << "----" << endl;
	W.show();
	system("pause");
	return 0;
}