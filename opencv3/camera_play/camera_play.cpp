#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv)
{
	
	Mat vframe;
	VideoCapture vcap;
	
	vcap.open(0);
	if(!vcap.isOpened())
	{
		cerr << "cannot open camera!!" << endl;
		return -1;
	}
	
	namedWindow("window3", WINDOW_AUTOSIZE);
	while(1)
	{
	
		vcap >> vframe;
		if(vframe.empty())
			break;
		imshow("window3", vframe);
			
		if(waitKey(27) >= 0)
			break;    
	}
	vcap.release();
	destroyWindow("window3");
	return 0; 
}

