#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("fcgoa.jpg",1);
Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
void updatefunc1(int r,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[2]<r)					
				img2.at<Vec3b>(i,j)[2]=0;
			else
				img2.at<Vec3b>(i,j)[2]=255;
			
		}
	}
	imshow("win",img2);
}
void updatefunc2(int g,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[1]<g)					
				img2.at<Vec3b>(i,j)[1]=0;
			else
				img2.at<Vec3b>(i,j)[1]=255;
			
		}
	}
	imshow("win",img2);
}
void updatefunc3(int b,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[0]<b)					
				img2.at<Vec3b>(i,j)[0]=0;
			else
				img2.at<Vec3b>(i,j)[0]=255;
			
		}
	}
	imshow("win",img2);
}
int main()
{
	int th1=0,th2=0,th3=0;
	namedWindow("win",WINDOW_NORMAL);	
	createTrackbar("r","win",&th1,255,updatefunc1);
	createTrackbar("g","win",&th2,255,updatefunc2);
	createTrackbar("b","win",&th3,255,updatefunc3);
	waitKey(0);
	return 0;
}	
