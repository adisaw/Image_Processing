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
	
	Mat img2(3*img.rows,3*img.cols,CV_8UC1,Scalar(0));
	int l=0,k=0;
	for(int i=0;i<2*img.rows;i++)
	{
		for(int j=0;j<2*img.cols;j++)
		{
			
			img2.at<uchar>(i,j)=img.at<uchar>(i/2,j/2);
		}
		
	}
	namedWindow("win",WINDOW_AUTOSIZE);
	namedWindow("win2",WINDOW_AUTOSIZE);
	imshow("win",img);
	imshow("win2",img2);
	waitKey(0);
	return 0; 
}
