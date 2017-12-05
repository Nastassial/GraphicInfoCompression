#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "Matrix.h"
#include "Functions.h"
#include <math.h>


using namespace std;
using namespace cv;

int main() {
	setlocale(LC_ALL, "");

	Mat img = imread("flowers.jpg");

	int n, m, p;
	double e;
	double Eq = 0, E = 0;
	double alphaY = 0, alphaX = 0;

	cout << "¬ведите n:" << endl;
	cin >> n;
	cout << "¬ведите m:" << endl;
	cin >> m;

	int numberOfSegments = (img.rows * img.cols) / (n*m);		 //L
	int vectorSize = n*m * 3;									 //N

	while (true)
	{
		cout << "¬ведите p (от 0 до " << vectorSize * 2 << "):" << endl;
		cin >> p;
		if (p <= vectorSize * 2) break;
	}
	
	cout << "¬ведите e " << endl;
	cin >> e;
	
	Matrix vectorsX(numberOfSegments, vectorSize);
	Matrix W(vectorSize, p);
	Matrix Wt(p, vectorSize);
	Matrix Xt(1, vectorSize);
	Matrix vecDeltaX(1, vectorSize);
	Matrix deltaX(numberOfSegments, vectorSize);
	Matrix vecX(1, vectorSize);
	Matrix vecY(1, p);
	Matrix Y(numberOfSegments, p);
	Matrix Wi(vectorSize, p);
	Matrix Wti(p, vectorSize);
	Matrix vecDX(1,vectorSize);
	Matrix temp(1,p);

	vectorsX = createXVectors(img, n, m);
	W = createW(vectorSize, p);
	//vectorsX.show();
	//cout << endl << "---- W" << endl << endl;
	//W.show();
	Wt = W.transponation();
	//cout << endl << "---- Wt" << endl << endl;
	//Wt.show();

	//for (int op = 0; op < 200 ; op++)
	int op = 0;
	do
	{
		op++;
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

			alphaY = 1 / vecY.transform();
			Wt = Wt - alphaY*vecY.transponation()*vecDeltaX;
		
			alphaX = 1 / vecX.transform();
			temp = vecDeltaX*Wt.transponation();
			W = W - alphaX*vecX.transponation()*temp;
			//W = W - alphaX*vecX.transponation()*vecDeltaX*Wt.transponation();
			
		}
		for (int i = 0; i < numberOfSegments; i++)
		{
			for (int j = 0; j < vectorSize; j++)
			{
				vecX[0][j] = vectorsX[i][j];
			}
			vecY = vecX * W;
			Xt = vecY * Wt;
			vecDeltaX = Xt - vecX;

			E += vecDeltaX.transform();
		}

		cout << "------------E "<<op<<"  " << E <<endl;
		//cout << "-----------e" << "   " << e << endl;
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
			vectorsX[i][j] = round(255 * (Xt[0][j] + 1) / 2);
		}
	}
	cout << "----------------W" << endl;
	//W.show();
	cout << "----------------------" << endl;
	//vectorsX.show();

	int numberOFSegmentInRow = img.cols / m;
	int k = 0;
	int u = 0;
	for (int i = 0; i < img.rows; i++) {
		if (i%n == 0 && i != 0) {
			k++;
			u = 0;
		}
		else if (k != 0) {
			k -= numberOFSegmentInRow - 1;
		}
		for (int j = 0; j < img.cols; j++) {
			if (j%m == 0 && j != 0) {
				k++;
				u -= 3 * m;
			}
			img.at<Vec3b>(i, j)[0] = vectorsX[k][u++];
			img.at<Vec3b>(i, j)[1] = vectorsX[k][u++];
			img.at<Vec3b>(i, j)[2] = vectorsX[k][u++];
		}
	}


	imwrite("new_flowers_200.jpg", img);

	int compressionIndex = (vectorSize * numberOfSegments) / ((vectorSize + numberOfSegments)*p + 2);

	system("pause");
	return 0;
}