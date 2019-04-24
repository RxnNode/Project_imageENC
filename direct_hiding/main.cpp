#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

#define INT_BIT 2
#define buffersize 8


unsigned int offset = 0;

int fileinfo(const char *picname){

    FILE *fdir = NULL;
    FILE *fout = NULL;
    FILE *fenc = NULL;

    char bmp[2] = {};
    int size = 0;

    int infosize = 0;
    int bits = 0;

    fdir = fopen(picname,"rb+");

    //print image information
    if (fdir) {
        printf("===============Image Information============\n");
        fread(bmp, sizeof(char), 2, fdir);
        printf("File Type: %s\n", bmp);

        fread(&size, sizeof(int), 1, fdir);
        printf("File Size: %d byte\n", size);

        fseek(fdir, 10, SEEK_SET);
        fread(&offset, sizeof(int), 1, fdir);
        printf("Pixel start from: %d\n", offset);

        fread(&infosize, sizeof(int), 1, fdir);
        printf("Info Size: %d\n", infosize);

        fseek(fdir, 10, SEEK_CUR);
        fread(&bits, 2, 1, fdir);
        printf("Bits per pixel: %d\n", bits);
        printf("============================================\n");
    } else{
        printf("Can't read file.\n");
        fclose(fdir);
        fclose(fenc);
        fclose(fout);
        return -1;
    }
    fclose(fdir);
    fclose(fenc);
    fclose(fout);
}

int main() {
    fileinfo("../images/image.bmp");
    fileinfo("../images/imageout.bmp");

    cv::Mat imgin = cv::imread("../images/image.jpg");
    cv::Mat imgbmp32b;
    cv::Mat imgbmp32bc4;

    imgin.convertTo(imgbmp32b, CV_16UC3);
    cv::cvtColor(imgbmp32b, imgbmp32bc4, cv::COLOR_BGR2BGRA, 0);

    cv::imwrite("imageout.bmp", imgbmp32bc4);


    //cv::imshow("hi",imgin);
    //cv::waitKey(0);


    return 0;

}