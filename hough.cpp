#include<math.h>
#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<stdlib.h>

using namespace std;
using namespace cv;

/*int isnotblack(int i,int j)
{
	for(int k=i-1;k<i+2;k++)
	{
		for(int l=j-1;j<l+2;j++)
		{
			if(img.at<uchar>(k,l)==0)
			{
				return 0;
			}
		}
	}
	return 1;
	
}*/
int main()
{	
	Mat img=imread("pentagon.png",0);
	//imshow("win",img);
	//waitKey(0);		
	//cout<<"HI";
	float max2=sqrt(img.rows*img.rows+img.cols*img.cols);
	int max=max2;	
	int ans[max+1][360];
	//cout<<cos(0.3);
	Mat img2(max+1,360,CV_8UC1,Scalar(0));
	for(int i=0;i<=max;i++)
	{
		cout<<i<<"\n";		
		for(int j=0;j<360;j++)
		{
			for(int k=0;k<img.rows;k++)
			{
				for(int l=0;l<img.cols;l++)
				{
					float r=i;
					float theta=j*3.14/180;
					float x=k;
					float y=l;
					float answer=x*cos(theta)+y*sin(theta);
					int a=(int)answer;
					if(a==r && img.at<uchar>(k,l)==255)
					{
						img2.at<uchar>(i,j)++;
						ans[i][j]++;
					}
				}
			}
		}
	}
	Mat img3(img.rows,img.cols,CV_8UC1,Scalar(0));
	//Mat img2(max+1,63,CV_8UC1,Scalar(0));
	for(int i=0;i<=max;i++)
	{
		cout<<i<<"\n";		
		for(int j=0;j<360;j++)
		{
			if(img2.at<uchar>(i,j)>20)			
			{
				for(int k=0;k<img.rows;k++)
				{
					for(int l=0;l<img.cols;l++)
					{
						float r=i;
						float theta=j*3.14/180;
						float x=k;
						float y=l;
						float answer=x*cos(theta)+y*sin(theta);
						int a=(int)answer;
						if(a==r )
						{
							img3.at<uchar>(k,l)=255;
				
						}
					}
				}
			}
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img3);
	waitKey(0);
	return 0;
	
}
