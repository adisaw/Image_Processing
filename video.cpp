#include<iostream>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap(0);
	Mat frame;
	
	while(1)
	{
		cap>>frame;
		Mat img2(frame.rows,frame.cols,CV_8UC1,Scalar(0));
		for(int i=0;i<frame.rows;i++)
		{
			for(int j=0;j<frame.cols/2;j++)
			{
				frame.at<Vec3b>(i,j)=frame.at<Vec3b>(i,frame.cols-j-1);
			}
		}
		Canny(frame,img2,50,100,3,0);
		namedWindow("win2",WINDOW_NORMAL);	
		imshow("win2",img2);
		namedWindow("win",WINDOW_NORMAL);
		imshow("win",frame);	
		waitKey(50);	
	}
	return 0;
}
