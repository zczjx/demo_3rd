#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int slide_pos = 0;
VideoCapture vcap;
int run_cmd = 1, go_done = 0;

void onTrackbarSlide( int pos, void *in_fps) 
{  
	int *fps = (int *) in_fps;

	cout << "onTrackbarSlide fps: " << *fps << endl;
	vcap.set(CAP_PROP_POS_FRAMES, pos);

	if(0 != go_done)
		run_cmd = 1;
	
	go_done = 0;
}

int main( int argc, char** argv)
{
	
	Mat vframe;
	int f_width, f_height, total_frames, fps = 0;
	int current_pos;
	
	
	namedWindow("window3", WINDOW_AUTOSIZE);
	vcap.open(string(argv[1]));
	f_width = vcap.get(CAP_PROP_FRAME_WIDTH);
	f_height = vcap.get(CAP_PROP_FRAME_HEIGHT);
	total_frames = vcap.get(CAP_PROP_FRAME_COUNT);
	fps = vcap.get(CAP_PROP_FPS);
	cout << "Video has " << total_frames << " frames of dimensions("<< f_width 
		<< ", " << f_height << ")." << endl;
	createTrackbar("vpos", "window3", &slide_pos, total_frames, onTrackbarSlide, &fps);
	while(1)
	{
		if(0 != run_cmd){
			vcap >> vframe;
			if(vframe.empty())
				break;
			current_pos = vcap.get(CAP_PROP_POS_FRAMES);
			setTrackbarPos("vpos", "window3", current_pos);
			imshow("window3", vframe);
			run_cmd -= 1;
		}

		 char c = (char) cv::waitKey(10);    
		if( c == 's' ) 
		{ // single step      
		 	run_cmd = 1;
			go_done = 1;
			cout << "Single step, run = " << run_cmd << endl;    
		}   
		if( c == 'r' ) 
		{ // run mode     
			run_cmd = -1;   
			go_done = 0;
		 	cout << "Run mode, run = " << run_cmd <<endl;
		}    
		if( c == 27 ) 
			break;
		
	}
	vcap.release();
	destroyWindow("window3");
	return 0; 
}

