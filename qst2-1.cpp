// Question 1-2


#include <opencv2\opencv.hpp>
#include<stdio.h>
#include<iostream>
#include<stdint.h>
#include<cstdlib>
#include<cmath>
#include<math.h>
using namespace std;
using namespace cv;

int main(int agrv, char**argc)

{
	Mat original =imread("test.jpg", 0); //load an image from the folder of the project, 0 indicate that it will be imported in grayscaling, this is the original picture

	Mat image = imread("test.jpg", 0); //load the same image from the folder of the project, 0 indicate that it will be imported in grayscaling, this will be the modified picture

		for (int i = 1; i< image.rows - 1; i++)
		{
			for (int j = 1; j <image.cols - 1; j++)
			{
			float  moy;
				moy = (image.at<uchar>(i, j + 1) + image.at<uchar>(i, j - 1) + image.at<uchar>(i + 1, j) + image.at<uchar>(i - 1, j)) / 4; //the average of of the 4 pixels surrounding the tested pixel
					if ((image.at<uchar>(i, j) - moy>10)||(moy - image.at<uchar>(i, j)>10))                                                      //the test if there is a noise or not
						image.at<uchar>(i, j) = moy;                                                                                       // we replace the pixel that it has noise
			}
		}



	namedWindow("original", CV_WINDOW_FREERATIO);                                //we give a name to the window of image and we set it to free ratio so we can control it's limit(change the size without changing the pixels)
		imshow("original", original);                                            //displaying the original image

		namedWindow("image", CV_WINDOW_FREERATIO);
	   imshow("image", image);                                                   //  displaying the modified image


	waitKey();

	return 0;



}
