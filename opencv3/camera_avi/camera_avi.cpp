#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv)
{
	VideoCapture vcap;
	int fps;
	VideoWriter v_writer;
	Mat raw_frame;
	
	
	vcap.open(0);
	if(!vcap.isOpened())
	{
		cerr << "cannot open camera!!" << endl;
		return -1;
	}
	
	fps = vcap.get(CAP_PROP_FPS);
	
	Size res((int) vcap.get(CAP_PROP_FRAME_WIDTH), 
			 (int) vcap.get(CAP_PROP_FRAME_HEIGHT));

	v_writer.open(argv[1], CV_FOURCC('M','J','P','G'), fps, res);
	namedWindow("window3", WINDOW_AUTOSIZE);
	while(1)
	{
	
		vcap >> raw_frame;
		if(raw_frame.empty())
			break;
		imshow("window3", raw_frame);
		v_writer << raw_frame;
		char c = waitKey(10);
			
		if(27 == c)
			break;    
	}
	vcap.release();
	v_writer.release();
	destroyWindow("window3");
	return 0; 
}

