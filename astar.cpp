#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<stdlib.h>

using namespace std;
using namespace cv;
Mat img=imread("dfs_path.jpg",0);
int isnotblack(int i,int j)
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
	
}
int isValid(int i,int j)
{
	if(i-1>=0 && i+1<img.rows &&j-1>=0 && j+1<img.cols)
	{
		if(isnotblack(i,j))
		{
			return 1;
		}
	}
	else
		return 0;
}
int main()
{
	int visited[1000][1000];
	int i=0,j=0;
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	namedWindow("win",WINDOW_NORMAL);
	img.at<uchar>(2,2)=125;
	img.at<uchar>(2,1)=125;
	img.at<uchar>(2,3)=125;
	img.at<uchar>(1,1)=125;
	img.at<uchar>(1,2)=125;
	img.at<uchar>(1,3)=125;
	img.at<uchar>(3,1)=125;
	img.at<uchar>(3,2)=125;
	img.at<uchar>(3,3)=125;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			visited[i][j]=1;
			
		}
	}
	i=2;j=2;
	while(visited[img.rows-3][img.cols-3]==0)
	{
		int num=-1;		
		float min=100000000;
		imshow("win",img);
		waitKey(100);
		if(isValid(i+5,j) && visited[i+5][j]==0)
		{
			float dist=(img.rows-3-i-5)*(img.rows-3-i-5)+(img.cols-3-j)*(img.cols-3-j);
			dist=sqrt(dist);
			if(dist<min)
			{	
				min=dist;
				num=3;
			}
		}
		if(isValid(i-5,j)&& visited[i-5][j]==0 )
		{
			float dist=(img.rows-3-i+5)*(img.rows-3-i+5)+(img.cols-3-j)*(img.cols-3-j);
			dist=sqrt(dist);
			if(dist<min)
			{	
				min=dist;
				num=2;
			}
		}
		if(isValid(i,j+5) && visited[i][j+5]==0)
		{
			float dist=(img.rows-3-i)*(img.rows-3-i)+(img.cols-3-j-5)*(img.cols-3-j-5);
			dist=sqrt(dist);
			if(dist<min)
			{	
				min=dist;
				num=1;
			}
		} 
		if(isValid(i,j-5) && visited[i][j-5]==0)
		{
			float dist=(img.rows-3-i)*(img.rows-3-i)+(img.cols-3-j+5)*(img.cols-3-j+5);
			dist=sqrt(dist);
			if(dist<min)
			{	
				min=dist;
				num=0;
			}
		} 
		if(isValid(i+5,j) && visited[i+5][j]==0 && num==3)
		{	
					
						
			for(int k=i+2;k<i+7;k++)
			{
				for(int l=j-1;l<j+2;l++)
				{
					img.at<uchar>(k,l)=125;
				}
			}		
			for(int k=i+3;k<i+8;k++)
			{
				for(int l=j-2;l<j+3;l++)
				{
					visited[k][l]=1;
				}
			}
			i=i+5;		
		}
		
	
	
	/*do
	{
		num=rand()%4;
	}while(num==3);*/
	
		if(isValid(i-5,j)&& visited[i-5][j]==0 && num==2)
		{
				
					
			for(int k=i-6;k<i-1;k++)
			{
				for(int l=j-1;l<j+2;l++)
				{
					img.at<uchar>(k,l)=125;
				}
			}			
			for(int k=i-7;k<i-2;k++)
			{
				for(int l=j-2;l<j+3;l++)
				{
					visited[k][l]=1;
				}
			}		
			i=i-5;	
		}
	
		
		if(isValid(i,j+5) && visited[i][j+5]==0 && num==1)
		{	
						
			for(int k=i-1;k<i+2;k++)
			{
				for(int l=j+2;l<j+7;l++)
				{
					img.at<uchar>(k,l)=125;
				}
			}
			for(int k=i-2;k<i+3;k++)
			{
				for(int l=j+3;l<j+8;l++)
				{
					visited[k][l]=1;
				}
			}		
			j=j+5;
		}

	
		if(isValid(i,j-5) && visited[i][j-5]==0 && num==0)
		{
					
			for(int k=i-1;k<i+2;k++)
			{
				for(int l=j-6;l<j-1;l++)
				{
					img.at<uchar>(k,l)=125;
				}
			}		
			for(int k=i-2;k<i+3;k++)
			{
				for(int l=j-7;l<j-2;l++)
				{
					visited[k][l]=1;
				}
			}
			j=j-5;	
		}
		

	}
	waitKey(0);
	return 0;
}

