

#ifndef ENC_IMG_CONVERT_H
#define ENC_IMG_CONVERT_H

#endif //ENC_IMG_CONVERT_H

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


int fileinfo(const char *picname){

    unsigned int offset = 0;

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
    return 0;
}

int convertoBMP4C(const char *srcname, const char *disname){
    cv::Mat imgin = cv::imread(srcname);
    cv::Mat imgbmp32b;
    cv::Mat imgbmp32bc4;
    imgin.convertTo(imgbmp32b, CV_32FC4);
    cv::cvtColor(imgbmp32b, imgbmp32bc4, cv::COLOR_BGR2BGRA, 0);
    cv::imwrite(disname, imgbmp32bc4);
    return 0;
}
int convertoBMP3C(const char *srcname, const char *disname) {
    cv::Mat imgin = cv::imread(srcname);
    cv::Mat imgbmp32b;
    imgin.convertTo(imgbmp32b, CV_32FC3);
    cv::imwrite(disname, imgbmp32b);
    return 0;
}