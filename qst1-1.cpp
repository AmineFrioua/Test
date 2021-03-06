// Question 1-1


#include <opencv2\opencv.hpp>
#include<stdio.h>
#include<iostream>
#include<stdint.h>
#include<cstdlib>
#include<cmath>

using namespace std;
using namespace cv;

int main(int agrv, char**argc)

{
	long int r, c;
	cout << "insert the lenth of the image lenth: \n";
	cin >> r;
	cout << "insert the width of the image width: \n";
	cin >> c;
	// we control the size of the image by precising the menth and the width of the image 
	Mat image = Mat(r, c, CV_8UC3);
	randu(image, Scalar::all(0), Scalar::all(255));  // creation of a random image that we will work on ( no need to import an image )

													 // we will be going through the image pixel by pixel to color it (change the values of pixels depending on the qst1-1 choice 
													 // we assume that 1mm = 3pixels so the granting would be 1 mm black and 1mm white


	for (int i = 0; i < image.rows; i++)
	{
		int k = 0;
		for (int j = 0; j < image.cols; j++)
		{

			if (k < 3)
			{
				image.at<Vec3b>(i, j)[0] = 0;    //here we are using the RBG representation of the image (red blue green) so for the black color it's a vector of 3 0 and for the white it's a vector of 3 255
				image.at<Vec3b>(i, j)[1] = 0;
				image.at<Vec3b>(i, j)[2] = 0;
			}
			else if ((k <= 6) &(k >= 3))
			{
				image.at<Vec3b>(i, j)[0] = 255;
				image.at<Vec3b>(i, j)[1] = 255;
				image.at<Vec3b>(i, j)[2] = 255;
			}
			k = k + 1;
			if (k == 6)
				k = 0;
		}


	}


	namedWindow("image", CV_WINDOW_FREERATIO);                                    //preparing the window for the image 
	imshow("image", image);                                                       //displaying the image 
	cout << "pixels Value of the Image are  = " << endl << image << endl << endl; // printing out the values of the pixels    
	waitKey();                                                                    

	return 0;


}
