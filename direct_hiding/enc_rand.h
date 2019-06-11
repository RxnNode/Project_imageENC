//
// Created by RxnNode on 2019-05-21.
//

#ifndef ENC_ENC_RAND_H
#define ENC_ENC_RAND_H

#endif //ENC_ENC_RAND_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int enc_rand(const char *img, const char *enc){


    unsigned int offset = 0;
    unsigned char header[offset];
    FILE *imgr = nullptr;   //image source
    FILE *fout = nullptr;

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

    unsigned int tchar = 0b11111110, imgchar;
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


            int rbits = 0, i = 0;
            bool readtext = true, control = true;
            // start hiding
            for (int k = 0; k < 8 ; ++k) {
                while ((imgchar = (unsigned int)fgetc(imgr)) != EOF){

                }
            }
        }

    return 0;

}