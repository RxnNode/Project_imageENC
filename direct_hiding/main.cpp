#include <stdio.h>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include "img_convert.h"


int enc(const char *img, const char *enc){


    unsigned int offset = 0;
    unsigned char header[offset];
    FILE *imgr = NULL;
    FILE *enct = NULL;
    FILE *fout[8];

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
     *

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
    */

    /*
     *  Read text file and write output file
     */
    enct = fopen("../text_source/secret","rb");     //Read text file
    if (enct == NULL){
        printf("Can't not read text file.\n");
        return -1;
    } else{
        fseek(enct, offset, SEEK_SET);
        unsigned int c, enc;
        unsigned int mask[8] = { 0b11111110,
                                 0b11111100,
                                 0b11111000,
                                 0b11110000,
                                 0b11100000,
                                 0b11000000,
                                 0b10000000,
                                 0b00000000 };  //magic
        //1 to 8 bits hiding
        for (int j = 0; j < 8; ++j) {

            char filename[32];
            sprintf(filename,"../out/out_%d.bmp",j);
            fout[j] = fopen(filename,"wb+");
            if (fout[j] == NULL){
                printf("Can't create output file.\n");
                return -1;
            } else{
                fseek(imgr, 0, SEEK_SET);
                fread(&header, sizeof(char), offset, imgr);     //Read header
                fwrite(header, sizeof(unsigned char), offset, fout[j]);    // Write header into Output file.
                printf("Bmp header writing...\n");
            }

            while ((enc = (unsigned)fgetc(enct)) != EOF){
                for (int i = 7; i >= 0; i--) {
                    if ((c = (unsigned) fgetc(imgr)) != EOF) {
                        c = (c & mask[j]) | ((enc & (1 << i)) >> i);
                        fputc(c, fout);
                    } else {
                        printf("This file is too small too hide all text file.\n");
                        return 1;
                    }
                }
            }
        }

        printf("Writing ...\n");
        // Add rest of pixels
        while ((c = (unsigned)fgetc(imgr)) != EOF){
            fputc(c,fout);
        }
    }
    fclose(imgr);
    fclose(enct);
    fclose(fout);

}

int dec(const char *srcenc){


}

void makemultpic(int n){
    FILE *test[n];
    struct stat st = {0};
    if (stat("../out",&st) == -1){
        mkdir("../out",0777);
    } else{
        printf("Out is already there!!");
    }
    for (int i = 0; i < n; i++) {
        char filename[32];
        sprintf(filename,"../out/out_%d.bmp",i);
        test[i] = fopen(filename,"wb");

    }
}
int main() {

    //convertoBMP("../images/image.jpg","../images/img.bmp");

    //enc("../images/img.bmp","text_source/secret");

    makemultpic(20);







    return 0;

}
