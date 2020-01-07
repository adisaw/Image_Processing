#include<iostream>
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
void DFS_visit(int visited[1000][1000],int i,int j)
{
	/*img.at<uchar>(i,j)=125;
	img.at<uchar>(i,j-1)=125;
	img.at<uchar>(i,j+1)=125;
	img.at<uchar>(i-1,j-1)=125;
	img.at<uchar>(i-1,j)=125;
	img.at<uchar>(i-1,j+1)=125;
	img.at<uchar>(i+1,j-1)=125;
	img.at<uchar>(i+1,j)=125;
	img.at<uchar>(i+1,j+1)=125;*/
	imshow("win",img);	
	waitKey(10);
	int count=0;
	while(count!=4)
	{
	int num=rand()%4;
	if(isValid(i+5,j) && visited[i+5][j]==0 && num==3)
	{	
		count++;		
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
		DFS_visit(visited,i+5,j);
		
	}
	else if(num==3)
		count++;
	/*do
	{
		num=rand()%4;
	}while(num==3);*/
	
	if(isValid(i-5,j)&& visited[i-5][j]==0 && num==2)
	{
		count++;		
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
		DFS_visit(visited,i-5,j);
	}
	else if(num==2)
		count++;
	/*do
	{
		num=rand()%4;
	}while(num==3 || num==2);*/	
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
		DFS_visit(visited,i,j+5);
	}
	else if(num==1)
		count++;
	/*do
	{
		num=rand()%4;
	}while(num==3 || num==2 || num==1);*/
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
		DFS_visit(visited,i,j-5);
	}
	else if(num==0)
		count++;	
	if(visited[img.rows-3][img.cols-3]==1)
	{
		return;
	}
	}
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
	
	DFS_visit(visited,2,2);
	
	
	return 0;	
		
}
