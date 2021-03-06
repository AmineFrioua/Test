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


int sizeimage(long int r, long int c)
{       
        // we control the size of the image by precising the menth and the width of the image
     
	cout << "insert the lenth of the image lenth: \n";
	cin >> r;
	cout << "insert the width of the image width: \n";
	cin >> c;
       
       //if r or c are pairs we add one pixel to them so in the compilation we avoid adding a gratting on the border not controlled (compiler problem ) in the matlab i didn't have this problem
       
       if (c%2==0) 
       c=c+1;
       if( r%2==0)
       r=r+1;




int main(int agrv, char**argc)

{
	long int  r, c;
	sizeimage(r,c);
	Mat image = Mat(r, c, CV_8UC3);
	randu(image, Scalar::all(0), Scalar::all(255));  // creation of a random image that we will work on ( no need to import an image )
	Mat image2;

	cvtColor(image, image2, CV_BGR2GRAY);             //conversion of the image into a grayscale (we'll work on the brightness on this model)
	float scale;                                      //a scale that we'll help us see the brightness in function of cos (from 0 to 1)
	scale = 3.14 / (2 * (image2.cols + image2.rows));


	// filling the borders 
	for (int i = 0; i < image2.rows; i++)
	{
		image2.at < uchar >(i, 0) = cos((i)*scale) * 255;
		image2.at < uchar >(i, image2.cols - 1) = cos((i + image2.cols - 1)*scale) * 255;

	}
	for (int i = 0; i < image2.cols; i++)
	{
		image2.at < uchar >(0, i) = cos((i)*scale) * 255;
		image2.at < uchar >(image2.rows - 1, i) = cos((i + image2.rows - 1)*scale) * 255;

	}


	//filling the matrix 

	for (int i = 1; i<image2.rows - 1; i++)
	{
		for (int j = 1; j<image2.cols - 1; j++)
		{
			image2.at < uchar >(i, j) = cos((i + j)*scale) * 255;

			if ((i % 2 == 1) && (j % 2 == 1))
				image2.at < uchar >(i, j) = 255;

		}
	}




	namedWindow("image", CV_WINDOW_FREERATIO);
	imshow("image", image2);                                                       //displaying the image 
	cout << "pixels Value of the Image are  = " << endl << image << endl << endl; // printing out the values of the pixels 

	waitKey();

	return 0;


}
