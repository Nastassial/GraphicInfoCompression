#pragma once
#include <opencv2/opencv.hpp>
#include "Matrix.h"

using namespace cv;

double round_value(double value);
Matrix createXVectors(Mat img, int n, int m);
Matrix createW(int vectorSize, int p);
double random(double min, double max);