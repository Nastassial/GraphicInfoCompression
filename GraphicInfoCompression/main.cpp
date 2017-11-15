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

	int numberOfSegments = (img.rows * img.cols) / (n*m);		 //L
	int vectorSize = n*m * 3;									 //N

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
	Matrix W(vectorSize, p);
	Matrix Wt(p, vectorSize);
	Matrix Xt(1, vectorSize);
	Matrix vecDeltaX(1, vectorSize);
	Matrix deltaX(numberOfSegments, vectorSize);
	Matrix vecX(1, vectorSize);
	Matrix vecY(1, p);
	Matrix Y(numberOfSegments, p);

	vectorsX = createXVectors(img, n, m);
	W = createW(vectorSize, p);
	vectorsX.show();
	cout << endl << "---- W" << endl << endl;
	W.show();
	Wt = W.transponation();
	cout << endl << "---- Wt" << endl << endl;
	Wt.show();
		
	do
	{
		E = 0;
		for (int i = 0; i < numberOfSegments; i++)
		{
			for (int j = 0; j < vectorSize; j++)
			{
				vecX[0][j] = vectorsX[i][j];
			}
			vecY = vecX * W;
			Xt = vecY * Wt;
			vecDeltaX = Xt - vecX;

			double alphaY = 1 / vecY.transform();
			cout << endl << "---- alphaY" << endl << endl;
			cout << alphaY << endl;
			Wt = Wt - alphaY*vecY.transponation()*vecDeltaX;
			double alphaX = 1 / vecX.transform();
			W = W - alphaX*vecX.transponation()*vecDeltaX*Wt.transponation();
			cout << "---------" << endl;
			vecDeltaX.show();
			cout << "---------" << endl;
			double t = vecDeltaX.transform();
			cout << t << endl;
			cout << "Eq:  	" << vecDeltaX.transform() << endl;
			E += vecDeltaX.transform();
			cout << "E:		" << E << endl;
			system("pause");
		}
	} while (E > e);

	for (int i = 0; i < numberOfSegments; i++)
	{
		for (int j = 0; j < vectorSize; j++)
		{
			vecX[0][j] = vectorsX[i][j];
		}
		vecY = vecX * W;
		Xt = vecY * Wt;
		for (int j = 0; j < vectorSize; j++)
		{
			vectorsX[i][j] = 255 * (Xt[i][j] + 1) / 2;
		}
	}
	cout << "----------------------" << endl;
	vectorsX.show();

	int compressionIndex = (vectorSize * numberOfSegments) / ((vectorSize + numberOfSegments)*p + 2);

	system("pause");
	return 0;
}