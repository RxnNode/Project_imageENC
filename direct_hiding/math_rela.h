//
// Created by Yung-An Jen on 2019-05-16.
//

#ifndef ENC_MATH_H
#define ENC_MATH_H

#endif //ENC_MATH_H

#include <stdio.h>
#include <math.h>

long double psnr(const char *dimg, const char *srcimg){

    FILE *dis = nullptr;    //sample image file
    FILE *src = nullptr;    //source image file
    int disp = 0, srcp = 0;
    int limit = 0;
    long double PSNR = 0, MSE = 0, sum = 0;

    //Read sample image file
    dis = fopen(dimg,"rb");
    if (dis == nullptr) {
        printf("Can't not image file.\n");
        return -1;
    }
    //Read source image file
    src = fopen(srcimg,"rb");
    if (src == nullptr) {
        printf("Can't not simage file.\n");
        return -1;
    }
    //calculate square error
    while ((disp = (unsigned int)fgetc(dis)) != EOF){
        if((srcp = (unsigned int)fgetc(src)) != EOF) sum += (srcp - disp)*(srcp - disp);
        if (limit  == 512*512) break; else limit++;
    }
    MSE = (sum/(512*512*4));
    PSNR = 20*log(((2^32-1)/MSE));
    fclose(dis);
    fclose(src);

    return PSNR;
}