#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int main()
{
	Mat img=imread("fcgoa.jpg",1);
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	//Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
	//Mat img4(img.rows,img.cols,CV_8UC1,Scalar(0));
	
	cout<<"Enter 1-4\n";
	int n;
	cin>>n;
	switch(n)
	{
		case 1: for(int i=0;i<img.rows;i++)
			{
				for(int j=0;j<img.cols;j++)
				{
					int temp;
					temp=img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2];
					temp=temp/3;
										
					img2.at<uchar>(i,j)=temp;
				}
			}
			namedWindow("win",WINDOW_NORMAL);
			imshow("win",img2);	
			waitKey(0);
			break;
		case 2: for(int i=0;i<img.rows;i++)
			{
				for(int j=0;j<img.cols;j++)
				{
					float temp;
					temp=0.07*img.at<Vec3b>(i,j)[0]+0.72*img.at<Vec3b>(i,j)[1]+0.21*img.at<Vec3b>(i,j)[2];
					img2.at<uchar>(i,j)=temp;
				}
			}
			namedWindow("win",WINDOW_NORMAL);
			imshow("win",img2);	
			waitKey(0);
			break;
		case 3: for(int i=0;i<img.rows;i++)
			{
				for(int j=0;j<img.cols;j++)
				{
					int temp=max(img.at<Vec3b>(i,j)[0],max(img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]));
					int temp2=min(img.at<Vec3b>(i,j)[0],min(img.at<Vec3b>(i,j)[1],img.at<Vec3b>(i,j)[2]));
					temp=temp+temp2;
					img2.at<uchar>(i,j)=temp;
				}
				
			}
			namedWindow("win",WINDOW_NORMAL);
			imshow("win",img2);	
			waitKey(0);
			break;
		case 4: for(int i=0;i<img.rows;i++)
			{
				for(int j=0;j<img.cols;j++)
				{
					int temp;
					temp=img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2];
					temp=temp/3;
										
					if(temp<125)					
					img2.at<uchar>(i,j)=0;
					else
					img2.at<uchar>(i,j)=255;
				}
			}
			namedWindow("win",WINDOW_NORMAL);
			imshow("win",img2);	
			waitKey(0);
			break;
		default: break;
	}
	return 0;
}		
			
			

