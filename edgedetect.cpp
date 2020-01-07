#include<iostream>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("rubik.jpg",0);

int isvalid(int i,int j)
{
	if(i>=0 && i<img.rows && j>=0 &&j<img.cols)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void updatefunc(int t,void *)
{
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img4(img.rows,img.cols,CV_8UC1,Scalar(0));
	Mat img5(img.rows,img.cols,CV_8UC1,Scalar(0));
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			float r=0,g=0,b=0,count=0;			
			for(int k=i-1;k<=i+1;k++)
			{
				for(int l=j-1;l<=j+1;l++)
				{
					if(isvalid(k,l)&& k==i&& l==j)
					{
					
						count=count+0.25;						
						r=r+0.25*img.at<uchar>(k,l);
						
					}
					if(isvalid(k,l)&& ((k==i-1&& l==j-1)||(k==i+1&&l==j+1)||(k==i-1&& l==j+1)||(k==i+1 && l==j+1)))
					{
						count=count+0.0625;						
						r=r+0.0625*img.at<uchar>(k,l);
						
					}
					if(isvalid(k,l)&&((k==i &&(l==j-1 || l==j+1))||(l==j &&(k==i-1 || k==i+1))))
					{
						count=count+0.125;						
						r=r+0.125*img.at<uchar>(k,l);
					}
				}
				
			
			}
			r=r/count;
			img2.at<uchar>(i,j)=r;
		
		}
	}
	
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			float gx=0,gy=0;			
			
			gx=gx-img2.at<uchar>(i-1,j-1);
			gx=gx-img2.at<uchar>(i+1,j-1);
			gx=gx-2*img2.at<uchar>(i,j-1);						
			gx=gx+2*img2.at<uchar>(i,j+1);
			gx=gx+img2.at<uchar>(i+1,j+1);		
			gx=gx+img2.at<uchar>(i-1,j+1);				
			gy=gy-img2.at<uchar>(i-1,j-1);
			gy=gy-img2.at<uchar>(i-1,j+1);
			gy=gy-2*img2.at<uchar>(i-1,j);
			gy=gy+img2.at<uchar>(i+1,j-1);
			gy=gy+img2.at<uchar>(i+1,j+1);
			gy=gy+2*img2.at<uchar>(i+1,j);
					gx=gx/8;
					gy=gy/8;
					float ans=gx*gx+gy*gy;
					ans=sqrt(ans);
					if(ans>t)
					{
						img3.at<uchar>(i,j)=255;
					}
				
				
			
			
		
		}
	}
	
	
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			for(int k=i-1;k<i+2;k++)
			{
				for(int l=j-1;l<j+2;l++)
				{
					if(img3.at<uchar>(k,l)==255)
						img4.at<uchar>(i,j)=255;
				}
			}
		}
	}
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			img5.at<uchar>(i,j)=img4.at<uchar>(i,j);
		}
	}
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			for(int k=i-1;k<i+2;k++)
			{
				for(int l=j-1;l<j+2;l++)
				{
					if(img4.at<uchar>(k,l)==0)
						img5.at<uchar>(i,j)=0;
				}
			}
		}
	}
	imshow("win",img3);
	
	imshow("dilate",img4);
	imshow("erode",img5);
}	
int main()
{
	int th=0;
	namedWindow("win",WINDOW_NORMAL);
	namedWindow("dilate",WINDOW_NORMAL);
	namedWindow("erode",WINDOW_NORMAL);	
	createTrackbar("ok","win",&th,11,updatefunc);
	waitKey(0);
	return 0;
}
	
