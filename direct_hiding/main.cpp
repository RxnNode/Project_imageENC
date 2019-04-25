#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "img_convert.h"


int enc(const char *img, const char *enc){


    unsigned int offset = 0;
    unsigned char header[offset];
    FILE *imgr = NULL;
    FILE *enct = NULL;
    FILE *fout = NULL;

    /*
     *  image
     */

    imgr = fopen(img,"rb+");    //Read image file
    if (imgr == NULL){
        printf("Failed to read image file.");
        return -1;
    } else{
        fseek(imgr, 10, SEEK_SET);  //Get offset
        fread(&offset, sizeof(int), 1, imgr);
        printf("Offset: %d\n",offset);
    }

    /*
     *  Output file
     */
    fout = fopen("../images/enc.bmp","wb+");
    if (fout == NULL){
        printf("Can't create output file.\n");
        return -1;
    } else{
        fseek(imgr, 0, SEEK_SET);
        fread(&header, sizeof(char), offset, imgr);     //Read header
        fwrite(header, sizeof(unsigned char), offset, fout);    // Write header into Output file.
        printf("Bmp header writing...\n");
    }

    /*
     *  text file
     */
    enct = fopen("../text_source/secret","rb");     //Read text file
    if (enct == NULL){
        printf("Can't not read text file.\n");
        return -1;
    } else{
        fseek(enct, offset, SEEK_SET);
        unsigned int c, enc, mask = 0b11111110;

        while ((enc = (unsigned)fgetc(enct)) != EOF){
            for (int i = 7; i >= 0; i--) {
                if ((c = (unsigned) fgetc(imgr)) != EOF) {
                    c = (c & mask) | ((enc & (1 << i)) >> i);
                    fputc(c, fout);
                } else {
                    printf("This file is too small too hide all text file.\n");
                    return 1;
                }
            }
        }
        printf("Writing ...\n");
        // Add rest of pixels
        while ((c = (unsigned)fgetc(imgr)) != EOF){
            fputc(c,fout);
        }
    }

}

int dec(const char *srcenc){


}


int main() {

    convertoBMP("../images/image.jpg","../images/img.bmp");

    enc("../images/img.bmp","text_source/secret");








    return 0;

}
