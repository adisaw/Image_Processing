#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("fruitbasket.jpg",1);
Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
void updatefunc1(int rupper,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[2]>rupper)					
				img2.at<Vec3b>(i,j)[2]=0;
			else
				img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];
		
			
		}
	}
	imshow("win",img2);
}
void updatefunc2(int gupper,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[1]>gupper)					
				img2.at<Vec3b>(i,j)[1]=0;
			else
				img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];

			
		}
	}
	imshow("win",img2);
}
void updatefunc3(int bupper,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[0]>bupper)					
				img2.at<Vec3b>(i,j)[0]=0;
			else
				img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
			
		}
	}
	imshow("win",img2);
}
void updatefunc4(int rlower,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[2]<rlower)					
				img2.at<Vec3b>(i,j)[2]=0;
			else
				img2.at<Vec3b>(i,j)[2]=img.at<Vec3b>(i,j)[2];

			
		}
	}
	imshow("win",img2);
}
void updatefunc5(int glower,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[1]<glower)					
				img2.at<Vec3b>(i,j)[1]=0;
			else
				img2.at<Vec3b>(i,j)[1]=img.at<Vec3b>(i,j)[1];

			
		}
	}
	imshow("win",img2);
}
void updatefunc6(int blower,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[0]<blower)					
				img2.at<Vec3b>(i,j)[0]=0;
			else
				img2.at<Vec3b>(i,j)[0]=img.at<Vec3b>(i,j)[0];
			
		}
	}
	imshow("win",img2);
}
int main()
{
	int th1=0,th2=0,th3=0,th4=0,th5=0,th6=0;
	namedWindow("win",WINDOW_NORMAL);	
	
	createTrackbar("ru","win",&th1,255,updatefunc1);
	createTrackbar("gu","win",&th2,255,updatefunc2);
	createTrackbar("bu","win",&th3,255,updatefunc3);
	createTrackbar("rl","win",&th4,255,updatefunc4);
	createTrackbar("gl","win",&th5,255,updatefunc5);
	createTrackbar("bl","win",&th6,255,updatefunc6);
	waitKey(0);
	return 0;
}
