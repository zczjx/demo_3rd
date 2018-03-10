#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	Mat my_img = imread(argv[1], -1);
	namedWindow("window1", WINDOW_AUTOSIZE);
	imshow("window1", my_img);
	waitKey(0);
	destroyWindow("window1");
	return 0; 
}

