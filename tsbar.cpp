#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("fruitbasket.jpg",1);
Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
int ru,rl,gu,gl,bu,bl;
void updatefunc(int t,void *)
{
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			
			
										
			
			if(img.at<Vec3b>(i,j)[2]<ru && img.at<Vec3b>(i,j)[2]>rl && img.at<Vec3b>(i,j)[1]>gl &&img.at<Vec3b>(i,j)[1]<gu &&img.at<Vec3b>(i,j)[0]>bl&&img.at<Vec3b>(i,j)[0]<bu )					
				img2.at<Vec3b>(i,j)=img.at<Vec3b>(i,j);
			else
				img2.at<Vec3b>(i,j)={0,0,0};
	
			
		}
	}
	imshow("win",img2);
}
int main()
{
	int th1=0,th2=0,th3=0,th4=0,th5=0,th6=0;
	namedWindow("win",WINDOW_NORMAL);	
	
	createTrackbar("ru","win",&ru,255,updatefunc);
	createTrackbar("gu","win",&gu,255,updatefunc);
	createTrackbar("bu","win",&bu,255,updatefunc);
	createTrackbar("rl","win",&rl,255,updatefunc);
	createTrackbar("gl","win",&gl,255,updatefunc);
	createTrackbar("bl","win",&bl,255,updatefunc);
	waitKey(0);
	return 0;
}
