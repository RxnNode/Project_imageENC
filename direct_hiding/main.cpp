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
    FILE *imgr = nullptr;
    FILE *enct = nullptr;
    FILE *fout = nullptr;
    FILE *log = nullptr;
    char logc[64];

    log = fopen("../log.txt","w");

    /*
     *  image
     */

    imgr = fopen(img,"rb+");    //Read image file
    if (imgr == nullptr){
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
    enct = fopen(enc,"rb");     //Read text file
    if (enct == nullptr){
        printf("Can't not read text file.\n");
        return -1;
    } else{
        unsigned int tchar = 0b11111110, imgchar;
        unsigned int maskl[8] = { 0b11111110,
                                 0b11111100,
                                 0b11111000,
                                 0b11110000,
                                 0b11100000,
                                 0b11000000,
                                 0b10000000,
                                 0b00000000 },
                     mask[8] = { 0b11111110,
                                 0b11111101,
                                 0b11111011,
                                 0b11110111,
                                 0b11101111,
                                 0b11011111,
                                 0b10111111,
                                 0b01111111 },
                     shift[8] = { 0b00000001,
                                  0b00000011,
                                  0b00000111,
                                  0b00001111,
                                  0b00011111,
                                  0b00111111,
                                  0b01111111,
                                  0b11111111};  //magic



        //1 to 8 bits hiding
        for (int j = 0; j < 8; ++j) {

            //fseek(imgr, offset, SEEK_SET);  // reset source image to offset
            fseek(enct, 0, SEEK_SET);   // reset text file to start

            // check folder
            struct stat st = {0};
            if (stat("../out",&st) == -1){
                mkdir("../out",0777);
            } else{
                printf("Out is already there!!\n");
            }

            // Create multiple files
            char filename[32];
            sprintf(filename,"../out/out_%d.bmp",j);
            fout = fopen(filename,"wb+");
            if (fout == nullptr){
                printf("Can't create output file.\n");
                return -1;
            } else{
                fseek(imgr, 0, SEEK_SET);
                fread(&header, sizeof(char), offset, imgr);     //Read header
                fwrite(header, sizeof(unsigned char), offset, fout);    // Write header into Output file.
                printf("%d Bmp header writing...\n",j);
            }
            int rbits=0, i = 0;
            bool readtext = true, control = true;
            // start hiding
            while (readtext){

                if (control) (tchar = (unsigned int)fgetc(enct));

                if (tchar != EOF){
                    for (i = 0; i < 8 ; i++) {
                        sprintf(logc,"i = %d\n",i);
                        fwrite(logc, sizeof(char),10,log);

                        if ((imgchar = (unsigned int)fgetc(imgr)) != EOF){
                            for (int k = 0; k <= j ; ++k) {
                                if (j != 0 && k != 0)i++;
                                if (i > 7){
                                    i = 0 ;
                                    tchar = (unsigned int)fgetc(enct);
                                    control = false;
                                } else{
                                    control = true;
                                }
                                imgchar = ((imgchar & mask[k])|((tchar & (1 << i)) >> i));
                                sprintf(logc,"i*= %d\n",i);
                                fwrite(logc, sizeof(char),10,log);

                            }

                            fputc(imgchar,fout);
                            rbits++;
                        } else{
                            printf("This file is too small too hide all text file.");
                            return -1;
                        }
                    }
                } else{
                    readtext = false;
                }


            }
            sprintf(logc,"%dbits done.\n",j);
            fwrite(logc, sizeof(char),20,log);
            printf("\n");
            printf("%d bits written.\n",rbits);
            // Add rest of pixels
            while ((imgchar = (unsigned)fgetc(imgr)) != EOF){
                fputc(imgchar,fout);
            }
            fclose(fout);
        }


    }
    fclose(imgr);
    fclose(enct);
    fclose(log);

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

    //onvertoBMP("../images/image.jpg","../images/imgb.bmp");

    enc("../images/img.bmp","../text_source/short");

    //makemultpic(20);


    printf("%d ", 0b00000011<<0);
    printf("%d ", 0b00000011<<6);
    printf("%d ", 0b00000011<<4);
    printf("%d ", 0b00000011<<2);



    return 0;

}
