#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

static Scalar colors[] = {
	Scalar(0, 0, 255),
 	Scalar(0, 128, 255),
	Scalar(0, 255, 255),
	Scalar(0, 255, 0)
};
static double scale = 0.8;

int main( int argc, char** argv )
{
	Mat img = imread(argv[1], IMREAD_COLOR);
	vector<cv::Rect> regions;
	int i;
	Mat gray_img(img.size(), CV_8UC1);
    Mat small_img(Size(cvRound(img.cols / scale), cvRound(img.rows / scale)), CV_8UC1);
	CascadeClassifier classifier("./model/haarcascade_frontalface_alt2.xml");
	namedWindow("img", WINDOW_AUTOSIZE);
	cvtColor(img, gray_img, COLOR_BGR2GRAY);
	resize(gray_img, small_img, small_img.size(), 0.0, 0.0, INTER_CUBIC);
	equalizeHist(small_img, small_img);
	classifier.detectMultiScale(small_img, regions, 
		1.1, 3, CV_HAAR_DO_CANNY_PRUNING, Size(30, 30));

	for(vector<cv::Rect>::iterator reg = regions.begin();
		reg != regions.end(); reg++, ++i)
	{
		Rect tmp = (*reg);
		tmp.x *= scale;
		tmp.y *= scale;
		tmp.width *= scale;
		tmp.height *= scale;
		rectangle(img, tmp, colors[i % 4], LINE_4);
	}

	imshow("img", img);

	waitKey(0);
	destroyWindow("img");
	
	return 0; 
}

