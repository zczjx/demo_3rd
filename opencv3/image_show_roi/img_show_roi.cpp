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
	Mat out_img;
	int x_from = atoi(argv[3]);
	int y_from = atoi(argv[4]);
	int x_to = atoi(argv[5]);
	int y_to = atoi(argv[6]);
	int x_res = MIN(img1.size().width, img2.size().width);
	int y_res = MIN(img1.size().height, img2.size().height);
	

	x_to = MIN(x_to, x_res);
	y_to = MIN(y_to, y_res);
	
	
	Mat roi1(img1, Rect(x_from, y_from, x_to-1, y_to-1));
	Mat roi2(img2, Rect(x_from, y_from, x_to-1, y_to-1));
	addWeighted(roi1, 0.5, roi2, 0.5, 0.0, roi1);
	namedWindow("roi", 1);
	imshow("roi", roi1);
	waitKey(0);
	destroyWindow("roi");
	return 0; 
}

