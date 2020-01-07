#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("lena.jpg",0);
	//Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	int size=img.rows*img.cols;
	
	//Mat img3(1000,5*255,CV_8UC1,Scalar(255));
	/*for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			int temp;
			temp=img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2];
			temp=temp/3;
										
			img2.at<uchar>(i,j)=temp;
		}
	}*/
	int max=0;
	int arr[256];
	for(int j=0;j<=255;j++)
	{
		arr[j]=0;
	}
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			arr[img.at<uchar>(i,j)]++;
			
		}
	}
	for(int j=0;j<=255;j++)
	{
		if(arr[j]>max)
		{
			max=arr[j];
		}
	}
	//cout<<max;
	Mat img3(max+1,255,CV_8UC1,Scalar(255));
	for(int j=0;j<=255;j++)
	{
		int i=max;
		while(arr[j]!=0 && i>=0)
		{
			//for(int h=0;h<199;h++)
			//{	
				img3.at<uchar>(i,j)=0;
			//}
			arr[j]--; i--;
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img3);
	waitKey(0);
	return 0;
}	
			
