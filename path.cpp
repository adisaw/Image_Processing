#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

Mat img=imread("66.jpg",0);
Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
Mat temp(img.rows,img.cols,CV_8UC1,Scalar(0));
int main()
{
	Canny(img,img2,50,100,3,0);
	temp=img2;
	for(int i=0;i<200;i++)
	{
		erode( temp, img2, 3 );	
		temp=img2;
	}
	namedWindow("win",WINDOW_NORMAL);	
	imshow("win",temp);
	
	waitKey(0);
	return 0;
}
