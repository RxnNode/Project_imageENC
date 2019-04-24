#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#define INT_BIT 2
#define buffersize 8


unsigned int offset = 0;

int main() {

    cv::Mat imgin = cv::imread("../images/image.jpg",-1);
    cv::Mat imgbmp;
    imgbmp.convertTo(imgbmp, CV_32SC4);
    cv::imwrite("imageout.bmp", imgbmp);
    //cv::imshow("hi",imgin);
    //cv::waitKey(0);


    return 0;

}