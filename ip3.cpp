#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("fcgoa.jpg",1);
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols/2;j++)
		{
			img.at<Vec3b>(i,j)=img.at<Vec3b>(i,img.cols-j-1);
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);	
	waitKey(0);
	return 0;

}
