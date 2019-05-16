#include <stdio.h>
#include <stdlib.h>
#include "img_convert.h"
#include "math_rela.h"
#include "enc_file.h"






int main() {

    convertoBMP("../images/lena.png","../images/imgl.bmp");

    enc_file("../images/imgl.bmp","../text_source/secret");
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
