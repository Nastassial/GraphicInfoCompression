#include "Functions.h"

double round_value(double value) {
	value = ((int)(value * 10 + (value >= 0 ? 0.5 : -0.5)) / 10.0);
	return value;
}

Matrix createXVectors(Mat img ,int n, int m) {
	int numberOfSegments = (img.rows * img.cols) / (n*m);
	int vectorSize = n*m * 3;
	int numberOFSegmentInRow = img.cols / m;
	Matrix vectorsX(numberOfSegments, vectorSize);
	int k = 0;
	int u = 0;
	double value;
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
			value = (double)2 * img.at<Vec3b>(i, j)[0] / 255 - 1;
			vectorsX[k][u++] = round_value(value);
			value = (double)2 * img.at<Vec3b>(i, j)[1] / 255 - 1;
			vectorsX[k][u++] = round_value(value);
			value = (double)2 * img.at<Vec3b>(i, j)[2] / 255 - 1;
			vectorsX[k][u++] = round_value(value);
			/*value = img.at<Vec3b>(i, j)[0];
			vectorsX[k][u++] = value;
			value = img.at<Vec3b>(i, j)[1];
			vectorsX[k][u++] = value;
			value = img.at<Vec3b>(i, j)[2];
			vectorsX[k][u++] = value;*/
		}
	}
	return vectorsX;
}

Matrix createW(int vectorSize, int p) {
	Matrix W(vectorSize, p);
	for (int i = 0; i < vectorSize ; i++)
		for (int j = 0; j < p; j++) {
			W[i][j] = random(-1.0, 1.0);
		}
	return W;
}

double random(double min, double max) {
	return round_value((double)(rand()) / RAND_MAX*(max - min) + min);
}
