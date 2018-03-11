#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	Mat in_img = imread(argv[1], -1);
	Mat out_img ,img_gry, img_cny;
	namedWindow("img-in", WINDOW_AUTOSIZE);
	namedWindow("img-gry", WINDOW_AUTOSIZE);
	namedWindow("img-cny", WINDOW_AUTOSIZE);

	// imshow("img-in", in_img);
	pyrDown(in_img, out_img);
	pyrDown(out_img, out_img);
	cvtColor(out_img, img_gry, COLOR_BGR2GRAY);
	imshow("img-gry", img_gry);
	Canny(img_gry, img_cny, 10, 200, 3, true );
	imshow("img-cny", img_cny);
	waitKey(0);
	destroyWindow("img-in");
	destroyWindow("img-gry");
	destroyWindow("img-cny");
	return 0; 
}

