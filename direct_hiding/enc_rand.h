//
// Created by RxnNode on 2019-05-21.
//

#ifndef ENC_ENC_RAND_H
#define ENC_ENC_RAND_H

#endif //ENC_ENC_RAND_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int enc_rand(const char *img, const char *enc){


    unsigned int offset = 0;
    unsigned char header[offset];
    FILE *imgr = nullptr;   //image source
    FILE *fout = nullptr;

    srand(time(NULL));

    /*
     *  Debug log
     *
        FILE *log = nullptr;
        char logc[64];
        log = fopen("../log.txt","w");
    */


        // check folder
        struct stat st = {0};
        if (stat("../RandOut",&st) == -1){
            mkdir("../RandOut",0777);
        } else{
            printf("Out is already there!!\n");
        }

    /*
     *  source image
     */
        imgr = fopen(img,"rb+");    //Read image file
        if (imgr == nullptr){
            printf("Failed to read image file.");
            return -1;
        } else{
            fseek(imgr, 10, SEEK_SET);  //Set offset
            fread(&offset, sizeof(int), 1, imgr);   //Get offset
        }

    unsigned int rchar, imgchar;
    unsigned int mask[8] = { 0b11111110,
                             0b11111101,
                             0b11111011,
                             0b11110111,
                             0b11101111,
                             0b11011111,
                             0b10111111,
                             0b01111111 };  //magic
    //1 to 8 bits hiding
        for (int j = 0; j < 8; ++j) {

            // Create multiple files
            char filename[32];

            sprintf(filename, "../RandOut/RandOut_%d.bmp", j);
            fout = fopen(filename, "wb+");

            if (fout == nullptr) {
                printf("Can't create output file.\n");
                return -1;
            } else {
                fseek(imgr, 0, SEEK_SET);
                fread(&header, sizeof(char), offset, imgr);     //Read header
                fwrite(header, sizeof(unsigned char), offset, fout);    // Write header into Output file.
                printf("%d Bmp header writing...\n", j);
            }

            // start hiding
                while ((imgchar = (unsigned int)fgetc(imgr)) != EOF){
                    rchar =rand() % 2 + 1;
                    for (int l = 0; l <=j; l++) {
                        imgchar =((imgchar & mask[l])|(rchar << l));
                    }
                    fputc(imgchar,fout);
                }

        }
    fclose(imgr);
    fclose(fout);
    return 0;

}