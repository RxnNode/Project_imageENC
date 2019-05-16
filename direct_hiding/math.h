//
// Created by Yung-An Jen on 2019-05-16.
//

#ifndef ENC_MATH_H
#define ENC_MATH_H

#endif //ENC_MATH_H

#include <stdio.h>
#include <math.h>

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