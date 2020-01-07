#include<iostream>
#include<math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
using namespace cv;
using namespace std;
Mat img=imread("rubik.jpg",0);
Mat img2(img.rows,img.cols,CV_8UC1,Scalar(0));
int main()
{
	int th=0;
	
	Canny(img,img2,50,100,3,0);
	namedWindow("win",WINDOW_NORMAL);	
	imshow("win",img2);
	waitKey(0);
	return 0;
}
