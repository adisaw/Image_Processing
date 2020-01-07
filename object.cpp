#include<iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
//#include <opencv2\opencv.hpp>
	
using namespace cv;
using namespace std;
#include <unistd.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <termios.h>

int fd;
void settings(const char *abc)
{
      fd = open(abc,O_RDWR | O_NOCTTY); /* ttyUSB0 is the FT232 based USB2SERIAL Converter   */
      usleep(3500000);
                                    /* O_RDWR Read/Write access to serial port           */
                                    /* O_NOCTTY - No terminal will control the process   */
                                    /* O_NDELAY -Non Blocking Mode,Does not care about-  */
                                    /* -the status of DCD line,Open() returns immediatly */                                       
                                   
            if(fd == -1)                        /* Error Checking */
                   printf("\n  Error! in Opening ttyUSB0  ");
            else
                   printf("\n  ttyUSB0 Opened Successfully ");
       struct termios toptions;         /* get current serial port settings */
       tcgetattr(fd, &toptions);        /* set 9600 baud both ways */
       cfsetispeed(&toptions, B9600);
       cfsetospeed(&toptions, B9600);   /* 8 bits, no parity, no stop bits */
       toptions.c_cflag &= ~PARENB;
       toptions.c_cflag &= ~CSTOPB;
       toptions.c_cflag &= ~CSIZE;
       toptions.c_cflag |= CS8;         /* Canonical mode */
       toptions.c_lflag |= ICANON;       /* commit the serial port settings */
       tcsetattr(fd, TCSANOW, &toptions);
}
void sendCommand(const char *abc)
{
   write(fd, abc, 1);
}


int main()
{
	char abc[9];
	settings(abc);
	VideoCapture cap(0);
	Mat frame;
	
	while(1)
	{
		cap>>frame;
		cv::Rect bounding_rect;
		Mat img2(frame.rows,frame.cols,CV_8UC3,Scalar(0,0,0));
		//cout<<" "<<frame.rows<<" "<<frame.cols;
		Mat lower(frame.rows,frame.cols,CV_8UC1,Scalar(0));
		Mat upper(frame.rows,frame.cols,CV_8UC1,Scalar(0));
		Mat img5(frame.rows,frame.cols,CV_8UC1,Scalar(0));
		Mat temp(frame.rows,frame.cols,CV_8UC1,Scalar(0));
		Mat finalimg(frame.rows,frame.cols,CV_8UC3,Scalar(0,0,0));
		cv::cvtColor(frame,img2,cv::COLOR_BGR2HSV);
		inRange(img2, cv::Scalar(0, 100, 100), cv::Scalar(10, 255, 255),lower);
		inRange(img2, Scalar(160, 100, 100), Scalar(180,255,255),upper);
		addWeighted(lower,1.0,upper,1.0,0.0,img5);		
		//Canny(frame,img2,50,100,3,0);
		GaussianBlur(img5,img5,cv::Size(9,9),2,2);
		//dilate(img4,img5,3);
		Canny(img5,img5,50,100,3,0);
		// Mat canny_output;
  		vector<vector<Point> > contours;
  		vector<Vec4i> hierarchy;
		  vector<Rect> boundRect( contours.size() );
		namedWindow("win2",WINDOW_NORMAL);
		//findContours(img5,contours,CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE);
		float maxarea=0,area;
		int k;
		findContours( img5, contours, hierarchy,CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE ); // Find the contours in the image
		
     		for( int i = 0; i< contours.size(); i++ ) // iterate through each contour. 
      		{
       			double a=contourArea( contours[i],false);  //  Find the area of contour
       			if(a>maxarea){
       				maxarea=a;
      				 k=i;                //Store the index of largest contour
       				//bounding_rect=boundingRect(contours[i]); // Find the bounding rectangle for biggest contour
      			 }

    		  }
		//cout<<maxarea<<"\n";
		if(contours.size()!=0)
		{
			bounding_rect=boundingRect(contours[k]);
		
 			Scalar color( 255,255,255);
			rectangle(finalimg,bounding_rect.tl(),bounding_rect.br(),color,2);
 		//drawContours( finalimg, contours,k, color, CV_FILLED, 8, hierarchy ); // Draw the largest contour using previously stored index.
	
 	//rectangle(finalimg, bounding_rect, color,1, 8,0);  
		/*if(contours.size()!=0)
		{
			for( int i = 0; i< contours.size(); i++ )
    		 	{
       			
				area=contourArea( contours, 0 );
				cout<<area<<"\n";
				if(area>maxarea)
				{

					 k=i;
		      			 maxarea=area;
				}	
			
     			}*/
		//drawContours( img5, contours, -1, (255,255, 0), 3);
			
		//}*/
		Mat bandw(frame.rows,frame.cols,CV_8UC1,Scalar(0));
		for(int i=0;i<frame.rows;i++)
		{
			for(int j=0;j<frame.cols;j++)
			{
				bandw.at<uchar>(i,j)=finalimg.at<Vec3b>(i,j)[0];
			}
		}
		Moments m= moments(bandw,true);
		int center=m.m10/m.m00;
		float ans;
		float h=-254.0/164000.0;
		float b=maxarea-6000.0;
		if(maxarea>=6000.0 && maxarea<=170000.0)
		{
			
			cout<<h<<"\n";
						 
			ans=(h)*(b)+127.0;
		}
		else if(maxarea<6000.0)
		{
			 ans=127.0;
		}	
		else if(maxarea>170000.0)
		{
			 ans=-127.0;
		}
		int x=(int)ans;
		std::string first = to_string(x);
		if(center>=100.0 && center<=540.0)
		{
			 ans=(254.0/440.0)*(center-100.0)-127.0;
		}
		else if(center<100.0)
		{
			 ans=-127.0;
		}	
		else
		{
			 ans=127.0;
		}
		int y=(int)ans;
		std::string second = to_string(y);
		if(x>0)
		{
			abc[1]=first[0];
			abc[2]=first[1];
			abc[3]=first[2];
		}
		else
		{
			abc[0]=first[0];
			abc[1]=first[1];
			abc[2]=first[2];
			abc[3]=first[3];
		}
		abc[4]=' ';
		if(y>0)
		{
			abc[6]=second[0];
			abc[7]=second[1];
			abc[8]=second[2];
		}
		else
		{
			abc[5]=second[0];
			abc[6]=second[1];
			abc[7]=second[2];
			abc[8]=second[3];
		}
		cout<<"AREA"<<maxarea<<"\n";
		cout<<"Center"<<center<<"\n";
		cout<<"x="<<x<<"\n";
		cout<<"y="<<y<<"\n";
		imshow("win2",finalimg);
		sendCommand(abc);
		}
		/*namedWindow("win",WINDOW_NORMAL);
		imshow("win",frame);	*/
		waitKey(50);	
	}
	return 0;
}
