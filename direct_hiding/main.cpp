#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "img_convert.h"


#define INT_BIT 2
#define buffersize 8


int main() {

    convertoBMP("../images/image.bmp","outimage.bmp");



    //cv::imshow("hi",imgin);
    //cv::waitKey(0);


    return 0;

}