#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("fcgoa.jpg",1);
Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));

void updatefunc(int t,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			int temp;
			temp=img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2];
			temp=temp/3;
										
			if(temp<t)					
			img2.at<uchar>(i,j)=0;
			else
			img2.at<uchar>(i,j)=255;
		}
	}
	
	imshow("win",img2);
}	
int main()
{
	int th=0;
	namedWindow("win",WINDOW_NORMAL);	
	createTrackbar("ok","win",&th,255,updatefunc);
	waitKey(0);
	return 0;
}
