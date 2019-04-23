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
    cv::VideoCapture cap(0);
    cv::Mat frame;
    while (1){
        cap >> frame;
        imshow("fdsf", frame);
        cv::waitKey(0);

    }


    return 0;

}