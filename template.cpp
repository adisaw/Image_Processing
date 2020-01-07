#include<iostream>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("coins.jpg",1);
Mat img2=imread("coins (1).jpg",1);

int main()
{
	Mat img3(img.rows-img2.rows+1,img.cols-img2.cols+1,CV_32FC1,Scalar(0));	
	matchTemplate(img, img2,img3,5);

	
	namedWindow("win",WINDOW_NORMAL);	
	imshow("win",img);
	namedWindow("win1",WINDOW_NORMAL);	
	imshow("win1",img2);
	namedWindow("win2",WINDOW_NORMAL);	
	imshow("win2",img3);
	waitKey(0);
	return 0;
}
