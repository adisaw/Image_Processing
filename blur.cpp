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
			int r=0,g=0,b=0,count=0;			
			for(int k=i-1;k<=i+1;k++)
			{
				for(int l=j-1;l<=j+1;l++)
				{
					if(isvalid(k,l))
					{
						count++;
						r=r+img.at<Vec3b>(k,l)[2];
						g=g+img.at<Vec3b>(k,l)[1];
						b=b+img.at<Vec3b>(k,l)[0];
					}
					
				}
			}
			if(count!=0)			
			{			
				r=r/count;
				g=g/count;
				b=b/count;
			}
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
