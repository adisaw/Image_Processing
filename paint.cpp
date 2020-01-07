#include<iostream>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<stdlib.h>

using namespace std;
using namespace cv;
Mat img=imread("shapes.jpg",0);
struct queue
{
    int i,j;
    struct queue* next;
}*front ,*rear;
int isValid(int i,int j)
{
	if(i>=0 && i<img.rows && j>=0 &&j<img.cols && img.at<uchar>(i,j)==255)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(int x,int y)
{
     queue* temp=new  queue;
    temp->next=NULL;
        temp->i=x;
	temp->j=y;
    if(rear==NULL)
    {
        front=temp;
        rear=temp;


    }
    else
    {
        rear->next=temp;
        rear=temp;
    }
}
void dequeue(int *x,int *y )
{
     queue* temp;
    temp=front;
    *x=temp->i;
    *y=temp->j;
    if(front==rear)
    {
        front=NULL;
        rear=NULL;
    }
    else
    {
        front=front->next;
    }
    free(temp);
	
    
}
void onMouse(int event,int y,int x,int flag,void *)
{
	front=NULL;
    	rear=NULL;
	int i=x,j=y;	
	//cout<<img.rows<<" "<<img.cols;
	int count=0;
	enqueue(i,j);
				/*if(count==1)
	
				cout<<front->i<<" "<<front->j;*/
	if(event==1)
	{	
	while(front!=NULL)
    	{
		queue* u=new queue;
		int x,y;				 
		dequeue(&x,&y);
   				
				/*if(count==1)
						cout<<x<<" "<<y<<"\n";*/
						
		if(isValid(x-1,y))
		{                			
				if(img.at<uchar>(x+1,y)==255 )
                		{
                 			img.at<uchar>(x-1,y)=125;
                    			enqueue(x-1,y);
                		}
		}
		if(isValid(x+1,y))
		{                			
					
			if(img.at<uchar>(x+1,y)==255 )
	                {
		                img.at<uchar>(x+1,y)=125;
                   		enqueue(x+1,y);
			}
              	}
		if(isValid(x,y-1))
		{                			
					
			if(img.at<uchar>(x,y-1)==255)
               		{
                   		img.at<uchar>(x,y-1)=125;
                   		enqueue(x,y-1);
               		}
		}
		if(isValid(x,y+1))
		{
			if(img.at<uchar>(x,y+1)==255)
               		{
                    		img.at<uchar>(x,y+1)=125;
                   		enqueue(x,y+1);
               		}
		}
		if(isValid(x-1,y-1))
		{                			
			if( img.at<uchar>(x-1,y-1)==255 )
                	{
                    		img.at<uchar>(x-1,y-1)=125;
                   		enqueue(x-1,y-1);
               		}
		}
		if(isValid(x-1,y+1))
		{                			
			if(img.at<uchar>(x-1,y+1)==255 )
                	{
                    		img.at<uchar>(x-1,y+1)=125;
                   		enqueue(x-1,y+1);
               		}
		}
		if(isValid(x+1,y-1))
		{                			
					
			if( img.at<uchar>(x+1,y-1)==255)
                	{
                    		img.at<uchar>(x+1,y-1)=125;
                    		enqueue(x+1,y-1);
                	}
		}
		if(isValid(x+1,y+1))
		{                			
					
			if(img.at<uchar>(x+1,y+1)==255)
                	{
                    		img.at<uchar>(x+1,y+1)=125;
                    		enqueue(x+1,y+1);
                	}
		}
		
	}
	}
    	imshow("win",img);
	
	
}
int main()
{
	Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
	namedWindow("win",WINDOW_NORMAL);    	
	setMouseCallback("win",onMouse,0);
	
    	waitKey(0);
	/*namedWindow("win",WINDOW_NORMAL);
	imshow("win",img2);	
	waitKey(0);*/
	return 0;
    	
}
