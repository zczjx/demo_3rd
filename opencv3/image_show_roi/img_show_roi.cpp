#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#define MIN(x, y) ((x < y)? x : y)


using namespace cv;
using namespace std;


int main( int argc, char** argv )
{
	Mat img1 = imread(argv[1], 1);
	Mat img2 = imread(argv[2], 1);
	int x_res = MIN(img1.size().width, img2.size().width);
	int y_res = MIN(img1.size().height, img2.size().height);

	
	Mat roi1(img1, Rect(0, 0, x_res-1, y_res-1));
	Mat roi2(img2, Rect(0, 0, x_res-1, y_res-1));
	
	addWeighted(roi1, 0.5, roi2, 0.5, -100, roi1);
	namedWindow("roi", 1);
	imshow("roi", roi1);
	waitKey(0);
	destroyWindow("roi");
	return 0; 
}

