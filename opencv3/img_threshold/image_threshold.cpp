#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	Mat src_gry = imread(argv[1], IMREAD_GRAYSCALE);
	int thld_val = atoi(argv[2]);
	Mat thld_img, thld_adj;
	
	namedWindow("SRC_GRY", WINDOW_AUTOSIZE);
	namedWindow("THLD", WINDOW_AUTOSIZE);
	namedWindow("THLD_ADJ", WINDOW_AUTOSIZE);

	threshold(src_gry, thld_img, thld_val, (thld_val + 30) % 200, THRESH_BINARY);
	adaptiveThreshold(src_gry, thld_adj, (thld_val + 30) % 200, 
					ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 0);

	imshow("SRC_GRY", src_gry);
	imshow("THLD", thld_img);
	imshow("THLD_ADJ", thld_adj);

	
	waitKey(0);
	destroyWindow("SRC_GRY");
	destroyWindow("THLD");
	destroyWindow("THLD_ADJ");
	return 0; 
}

