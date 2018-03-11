#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	Mat orig_img = imread(argv[1], -1);
	Mat smooth_img;
	namedWindow("origin", WINDOW_AUTOSIZE);
	namedWindow("smooth", WINDOW_AUTOSIZE);
	imshow("origin", orig_img);
	GaussianBlur(orig_img, smooth_img, Size(5,5), 8, 8);
	GaussianBlur(smooth_img, smooth_img, Size(5,5), 8, 8);
	imshow("smooth", smooth_img);
	waitKey(0);
	destroyWindow("origin");
	destroyWindow("smooth");
	return 0; 
}

