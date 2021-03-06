// Question 2-2


#include <opencv2\opencv.hpp>
#include<stdio.h>
#include<iostream>
#include<stdint.h>
#include<cstdlib>
#include<cmath>

using namespace std;
using namespace cv;

// first we'll establish a sorting function, we'll use this function later 

void sort(int* tabl, int longueur)
{
	int i, _i,mem;
	for (_i = 0; _i<longueur; ++_i)
	{
		for (i = 0; i<longueur - 1; i++)
		{
			if (tabl[i] > tabl[i + 1])
			{
				mem = tabl[i];
				tabl[i] = tabl[i + 1];
				tabl[i + 1] = mem;

				
			}
		}
	}
}

int main(int agrv, char**argc)

{
	
Mat original = imread("test.jpg", 0);//load an image from the folder of the project , 0 indicate that it will be imported in grayscaling, this is the original picture 

Mat image = imread("test.jpg", 0);//load an image from the folder of the project , 0 indicate that it will be imported in grayscaling, this will be the modified picture

//double for function to go through the image pixel by pixel 

for (int i = 1; i < image.rows-1; i++)
{
	for (int j = 1; j <image.cols-1 ; j++)
	{
	
		float moy;
		moy = (image.at<uchar>(i, j + 1) + image.at<uchar>(i, j - 1) + image.at<uchar>(i + 1, j) + image.at<uchar>(i - 1, j) + image.at<uchar>(i - 1, j - 1) + image.at<uchar>(i - 1, j + 1) + image.at<uchar>(i + 1, j - 1) + image.at<uchar>(i + 1, j + 1) + image.at<uchar>(i, j)) / 9; //the average of of the 9 pixels surrounding the tested pixel
		if ((image.at<uchar>(i, j) - moy > 10) || (moy - image.at<uchar>(i, j) > 10))  //the test if there is a noise or not
		{
			//in this structure we will be creating an array containing all the pixels surrounding our main pixel that we will be testing for this i,j and with the sorting funtion we will order our pixels from the brightest to the darkest

			int pixels[9] = { image.at<uchar>(i, j + 1),image.at<uchar>(i, j - 1),image.at<uchar>(i + 1, j), image.at<uchar>(i - 1, j),image.at<uchar>(i - 1, j - 1),image.at<uchar>(i - 1, j + 1),image.at<uchar>(i + 1, j - 1),image.at<uchar>(i + 1, j + 1),image.at<uchar>(i, j) };
			sort(pixels, 9);

			//here we'll be affecting the new average of the 5 pixels remaining into our main pixel 
			image.at<uchar>(i, j) = (pixels[2] + pixels[3] + pixels[4] + pixels[5] + pixels[6]) / 5;

		}
	}
}



    namedWindow("original", CV_WINDOW_FREERATIO);                                  //we give a name to the window of image and we set it to free ratio so we can control it's limit(change the size without changing the pixels)
    imshow("original", original);                                                     //displaying the original image  

	namedWindow("image", CV_WINDOW_FREERATIO);                                    
	imshow("image", image);                                                       //displaying the modified image 
	

	waitKey();

	return 0;


}
