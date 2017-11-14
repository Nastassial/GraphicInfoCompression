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
	double e;
	double Eq = 0, E = 0;
	cout << "¬ведите n:" << endl;
	cin >> n;
	cout << "¬ведите m:" << endl;
	cin >> m;
	int numberOfSegments = (img.rows * img.cols) / (n*m); //L
	int vectorSize = n*m * 3;
	int numberOFSegmentInRow = img.cols / m;
	while (true)
	{
		cout << "¬ведите p (не больше числа " << vectorSize * 2 << "):" << endl;
		cin >> p;
		if (p <= vectorSize * 2) break;
	}
	while (true)
	{
		cout << "¬ведите e (от 0 до " << 0.1*p << "):" << endl;
		cin >> e;
		if (e <= 0.1*p && e > 0) break;
	}
	Matrix vectorsX(numberOfSegments, vectorSize);
	vectorsX = createXVectors(img, n, m);
	Matrix W(vectorSize, p);
	W = createW(vectorSize, p);
	vectorsX.show();
	cout << endl << "---- W" << endl << endl;
	W.show();
	Matrix Wt(p,vectorSize);
	Wt = W.transponation();
	cout << endl << "---- Wt" << endl << endl;
	Wt.show();
	Matrix Y(numberOfSegments,p);
	do															//»—ѕ–ј¬»“№
	{
		Y = vectorsX * W;
		cout << endl << "---- Y" << endl << endl;
		Y.show();
		Matrix Xt(numberOfSegments, vectorSize);
		Xt = Y * Wt;
		cout << endl << "---- Xt" << endl << endl;
		Xt.show();
		Matrix deltaX(numberOfSegments, vectorSize);
		deltaX = Xt - vectorsX;
		cout << endl << "---- deltaX" << endl << endl;
		deltaX.show();
		for (int count = 1; count <= numberOfSegments; count++)
		{
			double alphaY = 1 / Y.transform();
			cout << endl << "---- alphaY" << endl << endl;
			cout << alphaY << endl;
			Matrix WtCorrection(p, vectorSize);
			WtCorrection = Wt - alphaY*Y.transponation()*deltaX;
			cout << endl << "---- WtCorrection" << endl << endl;
			WtCorrection.show();
			double alphaX = 1 / vectorsX.transform();
			cout << endl << "---- alphaX" << endl << endl;
			cout << alphaX << endl;
			Matrix Weducation(vectorSize, p);
			Weducation = W - alphaX*vectorsX.transponation()*deltaX*W;
			cout << endl << "---- Weducation" << endl << endl;
			Weducation.show();
			/*for (int q = 1; q <= numberOfSegments; q++)
			{
				for (int i = 1; i <= vectorSize; i++)
				{

				}
			}*/
		}
	} while (E > e);
	int compressionIndex = (vectorSize * numberOfSegments) / ((vectorSize + numberOfSegments)*p + 2);
	system("pause");
	return 0;
}