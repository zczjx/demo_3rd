#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	Mat src = imread(argv[1], IMREAD_COLOR);
	char *opr = argv[2];
	int i ,scale = atoi(argv[3]);
	float f_scale = 0;
	Mat resize_line, resize_cubic, py_resize;
	int up_flag = 0;
	Size out_size;

	if(argc < 3)
	{
		cout << "enter img_resize [up/down] [2/3/4...]" << endl;
		return -1;
	}
	if(0 == strcmp(opr, "up"))
	{
		up_flag = 1;
		f_scale = scale;
	}
	else
	{
		up_flag = 0;
		f_scale = 1 / ((float) scale);
	}

	out_size= Size(src.cols * f_scale, src.rows * f_scale);
	cout << "f_scale: " << f_scale << endl;
	namedWindow("src", WINDOW_AUTOSIZE);
	namedWindow("resize_linear", WINDOW_AUTOSIZE);
	namedWindow("resize_cubic", WINDOW_AUTOSIZE);
	namedWindow("py_resize", WINDOW_AUTOSIZE);

	resize(src, resize_line,out_size, INTER_LINEAR);
	resize(src, resize_cubic,out_size, INTER_CUBIC);
	if(up_flag)
	{
		py_resize = src;
		for(i = 1; i < scale; i++)
			pyrUp(py_resize, py_resize);
	}
	else
	{
		py_resize = src;
		for(i = 1; i < scale; i++)
			pyrDown(py_resize, py_resize);
	}
	GaussianBlur(src, src, Size(5,5), 8, 8);
	GaussianBlur(src, src, Size(5,5), 8, 8);
	rectangle(src, Rect(270, 40, 60, 60), Scalar(255, 0, 0), LINE_4);
	imshow("src", src);
	imshow("resize_linear", resize_line);
	imshow("resize_cubic", resize_cubic);
	imshow("py_resize", py_resize);

	
	waitKey(0);
	destroyWindow("src");
	destroyWindow("resize_linear");
	destroyWindow("resize_cubic");
	destroyWindow("py_resize");
	return 0; 
}

