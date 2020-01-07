#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
int main()
{
	Mat img(100,100,CV_8UC3,Scalar(0,255,255));
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100-i;j++)
		{
			
				img.at<Vec3b>(i,j)={0,0,255};
			
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);	
	waitKey(0);
	return 0;

}
