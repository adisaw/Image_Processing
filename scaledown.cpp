#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("fcgoa.jpg",0);
	cout<<img.rows<<" ";
	cout<<img.cols;
	
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	int frow=img.rows/2;
	int fcol=img.cols/2;
	int arr[img.rows][img.cols];
	int j=0,k=0;
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			arr[i][j]=0;
		}
	}
	for(int i=0;i<img.rows;i++)
	{
		
		for(int j=0;j<img.cols;j++)
		{
			arr[i/2][j/2]=arr[i/2][j/2]+img.at<uchar>(i,j);			
							
		}
		
	}
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			img2.at<uchar>(i,j)=arr[i][j]/4;
		}
	}
	namedWindow("win",WINDOW_AUTOSIZE);
	namedWindow("win2",WINDOW_AUTOSIZE);
	imshow("win",img);
	imshow("win2",img2);
	waitKey(0);
	return 0; 
}
