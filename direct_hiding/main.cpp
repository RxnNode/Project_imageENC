#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <math.h>
#include "img_convert.h"





long double psnr(const char *dimg, const char *srcimg){

    FILE *dis = nullptr;
    FILE *src = nullptr;
    int disp = 0, srcp = 0;
    int limit = 0;
    long double PSNR = 0, MSE = 0, sum = 0;

    dis = fopen(dimg,"rb");     //Read text file
    if (dis == nullptr) {
        printf("Can't not image file.\n");
        return -1;
    }
    src = fopen(srcimg,"rb");     //Read text file
    if (src == nullptr) {
        printf("Can't not simage file.\n");
        return -1;
    }

    while ((disp = (unsigned int)fgetc(dis)) != EOF){

        if((srcp = (unsigned int)fgetc(src)) != EOF){

            sum += (srcp - disp)*(srcp - disp);
        }

        if (limit  == 512*512) break; else limit++;
    }


    printf("Sum: %Lf\n",sum);
    MSE = (sum/(512*512*4));
    printf("MSE: %Lf\n",MSE);
    PSNR = 20*log(((2^32-1)/MSE));

    fclose(dis);
    fclose(src);

    return PSNR;
}
int main() {

    convertoBMP("../images/lena.png","../images/imgl.bmp");

    enc("../images/imgl.bmp","../text_source/secret");
    for (int i = 0; i < 8; ++i) {
        char filename[32];
        long double p = 0.0;
        sprintf(filename,"../out/out_%d.bmp",i);
        p = psnr(filename, "../images/imgl.bmp");
        printf("%d bits hiding psnr : %Lf\n",i+1,p);
    }
    //double p = 0.0;
    /*p = psnr("../out/out_0.bmp", "../images/imgb.bmp");
    printf("1 bits hiding psnr : %8f\n",p);
    p = psnr("../out/out_4.bmp", "../images/imgb.bmp");
    printf("5 bits hiding psnr : %8f\n",p);*/
    //makemultpic(20);


    /*printf("%d ", 0b00000011<<0);
    printf("%d ", 0b00000011<<6);
    printf("%d ", 0b00000011<<4);
    printf("%d ", 0b00000011<<2);*/



    return 0;

}
