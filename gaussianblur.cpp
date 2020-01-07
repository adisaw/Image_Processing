#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("fcgoa.jpg",1);
	Mat img2(img.rows,img.cols,CV_8UC3,Scalar(0,0,0));
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
int main()
{
	
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
						r=r+0.25*img.at<Vec3b>(k,l)[2];
						g=g+0.25*img.at<Vec3b>(k,l)[1];
						b=b+0.25*img.at<Vec3b>(k,l)[0];
					}
					if(isvalid(k,l)&& ((k==i-1&& l==j-1)||(k==i+1&&l==j+1)||(k==i-1&& l==j+1)||(k==i+1 && l==j+1)))
					{
						count=count+0.0625;						
						r=r+0.0625*img.at<Vec3b>(k,l)[2];
						g=g+0.0625*img.at<Vec3b>(k,l)[1];
						b=b+0.0625*img.at<Vec3b>(k,l)[0];	
					}
					if(isvalid(k,l)&&((k==i &&(l==j-1 || l==j+1))||(l==j &&(k==i-1 || k==i+1))))
					{
						count=count+0.125;						
						r=r+0.125*img.at<Vec3b>(k,l)[2];
						g=g+0.125*img.at<Vec3b>(k,l)[1];
						b=b+0.125*img.at<Vec3b>(k,l)[0];
					}
				}
				
			
			}
			r=r/count;
			g=g/count;
			b=b/count;
			img2.at<Vec3b>(i,j)[2]=r;
			img2.at<Vec3b>(i,j)[1]=g;
			img2.at<Vec3b>(i,j)[0]=b;
		}
	}	
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img2);
	waitKey(0);
	return 0;
						
			
}
