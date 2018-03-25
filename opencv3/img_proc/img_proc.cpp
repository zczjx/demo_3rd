#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	Mat src = imread(argv[1], IMREAD_COLOR);
	Mat simple, med, gauss, bilat;
	
	namedWindow("src", WINDOW_AUTOSIZE);
	namedWindow("simple_blur", WINDOW_AUTOSIZE);
	namedWindow("median_blur", WINDOW_AUTOSIZE);
	namedWindow("gauss_blur", WINDOW_AUTOSIZE);
	namedWindow("bilat_blur", WINDOW_AUTOSIZE);
	// blur(src, simple, Size(5,5));
	boxFilter(src, simple, -1, Size(5,5));
	medianBlur(src, med, 5);
	GaussianBlur(src, gauss, Size(5,5), 0, 0);
	bilateralFilter(src, bilat, 25, 50, 12.5);


	imshow("src", src);
	imshow("simple_blur", simple);
	imshow("median_blur", med);
	imshow("gauss_blur", gauss);
	imshow("bilat_blur", bilat);

	
	waitKey(0);
	destroyWindow("SRC_GRY");
	destroyWindow("THLD");
	destroyWindow("THLD_ADJ");
	return 0; 
}

