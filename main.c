#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <MacTypes.h>
#define INT_BIT 2
#define buffersize 8

void binaryn(int *ptr, int n){
    for (int i = sizeof(n)*INT_BIT - 1; i >= 0; --i) {
        *ptr++ = (n>>i) & 1;
    }
}

int main() {

/*
 */

    FILE *fdir = NULL;
    FILE *fout = NULL;
    FILE *fenc = NULL;
    FILE *enct = NULL;

    char bmp[2] = {};
    int size = 0;
    unsigned int offset = 0;
    int infosize = 0;
    int bits = 0;


    fdir = fopen("../images/image01.bmp","rb+");
    if (fdir){
        //print image information
        fread(bmp, sizeof(char), 2, fdir);
        printf("File Type: %s\n", bmp);

        fread(&size, sizeof(int), 1, fdir);
        printf("File Size: %d byte\n", size);

        fseek(fdir,10,SEEK_SET);
        fread(&offset, sizeof(int), 1, fdir);
        printf("Pixel start from: %d\n",offset);

        fread(&infosize, sizeof(int), 1, fdir);
        printf("Info Size: %d\n",infosize);

        fseek(fdir,10,SEEK_CUR);
        fread(&bits, 2, 1, fdir);
        printf("Bits per pixel: %d\n",bits);

        /*
         *
         *  Encryption start
         *  Output file : Out.bmp
         */
        // Read bmp header
        unsigned char header[offset];
        fseek(fdir, 0, SEEK_SET);
        fread(&header, sizeof(char), offset, fdir);

        // Create output bmp file
        fout = fopen("../out.bmp","wb+");
        //enct = fopen("../outt","wb+");
        if (fout == NULL){
            printf("Can't create Output file.");
            return -1;
        } else{
            // Write header into Output file.
            fwrite(header, sizeof(unsigned char), offset, fout);
        }
        //  Read enc text file
        fenc = fopen("../Enc/secret","rb");
        if (fenc == NULL){
            printf("Can't not read text file.");
            return -1;
        } else{
            fseek(fdir, offset, SEEK_SET);
            unsigned int c, enc, show = 0, show2 = 0;
            while ((enc = (unsigned)fgetc(fenc)) != EOF){
               if(show2 < 10) printf("Enc !!!: %d\n", enc);

                for (int i = 7; i >= 0; i--) {
                   
                    if ((c = (unsigned)fgetc(fdir)) != EOF){
                        //printf("Pixel: %d\n",c);
                        unsigned int k = (enc & (1 << i));

                        //printf("Enc 0110 0110: %d\n",k);
                        c = c | (k >> i);
                        if(show < 10) printf("Pixel enc: %d\n",c);
                        show++;
                        //c = c | ((enc & (1 << i)) >> i);
                        fputc(c,fout);

                    } else{
                        printf("This file is too small too hide all text file.");
                        return 1;
                    }
                }
                show2++;
            }
            // Add rest of pixels
            while ((c = (unsigned)fgetc(fdir)) != EOF){

                fputc(c,fout);
            }
        }
        fclose(fdir);
        fclose(fenc);
        fclose(fout);
    } else{
        printf("Can't read file.\n");
        perror("Error");
        return -1;
    }

   /*
    *  Decryption
    *  Output file : dec.text
    *
    */

    FILE *dec;

    fout = fopen("../out.bmp","rb+");
    if ( fout == NULL){
        printf("Can't find output file. Decryption terminated.");
        return -1;
    } else{

         dec = fopen("../dec.txt","wb+");
         if (dec == NULL){
            printf("Can't create decrypted file.");
             return -1;
         } else{
             unsigned int oc, dc = 0b00000000, show = 0;
             fseek(fout, offset, SEEK_SET);
             while((oc = (unsigned)fgetc(fout)) != EOF){
                    
                         //printf("OC: %d\n",oc);
                         oc = oc & 1;
                         //printf("OC & 1: %d\n",oc);
                         dc = dc | (oc << 7);
                          //printf("DC7: %d\n",dc);
                         for (int i = 6; i >= 0 ; i--) {
                            oc = (unsigned)fgetc(fout);
                            oc = oc & 1;
                            dc = dc | (oc << i);
                             //printf("DC%d: %d\n",i,dc);
                         }

                         //printf("DC000====: %d\n",dc);


                     fputc(dc, dec);
                     dc = 0b00000000;
                     oc = 0b00000000;

             }
         }

    }



/*
    FILE *dir, *dir2;
    FILE *out;
    FILE *outtest;
    int c,count=0, show=0;
    Boolean test = false;

    dir = fopen("../images/image.jpg","r+b");
    //dir = fopen("../images/parrots.jpeg","r+b");

    if (dir== NULL){
        printf("Can't read file.");
        perror("Error");
    } else{
        printf("Read image successfully.\n");
        out = fopen("../out.txt","wb+");
        if (out){
            while ((c=fgetc(dir))!=EOF) {
                if(show <= 16 )printf("%d ",c);
                show++;
                int binbuf[buffersize];
                binaryn(binbuf, c);
                //if (show != 10) {
                    for (int i = 0; i < buffersize; ++i) {
                        fputc(binbuf[i], out);
                        //printf("%d", binbuf[i]);
                    }
                    //show++;
                    //printf(" ");
                //}
                count++;
            }
            printf("\n%d byte read.\n",count);
            printf("Create a output file successfully.\n");
            test = true;
        } else{
            printf("Can't create a output file.\n");
            //perror("Error");
        }
        fclose(dir);
        fclose(out);
    }
*/

/*
    if (test){

        FILE *cmess;
        cmess = fopen("../Enc/Enc/secret","rb+");
        if (cmess){
            printf("Read message successfully.\n");

        } else{
            printf("Can't read message file.\n");
            //perror("Error");
        }

    } else{

    }
*/



/*
 *  output file check
 *  If it can be converted back to original jpg that binary algorithm is correct.
 *  Yes! It works!
 *
    FILE *outback;
    show = 0;
    outtest = fopen("../out.txt","rb");
    outback = fopen("../out.jpg","wb+");
    if (outtest == NULL){
        perror("Error");
    } else{
        printf("\nStart checking output file...\n");
        int obitc = 8, p = 0b00000000;
        int buf[obitc];
        while ((c=fgetc(outtest))!=EOF){

            buf[obitc-1] = c;

            //if (show <=31) printf("%d",c);
            //show++;

            if (obitc == 1){
                obitc = 8;
                for (int i = 0; i < 8; ++i) {

                    if (show <=31)printf("%d",buf[i]);
                    show++;

                    if (buf[i]!=0){
                        p = p | (1 << i);
                    }
                }
                //if (show <=16) printf("%d ",p);
                printf(" "),
                //show ++;
                fputc(p,outback);
                p = 0b00000000;

            } else{
                obitc--;
            }

        }

    }
    fclose(outback);
    fclose(outtest);
*/

/*
 *  binary convert test
 *
    int bin[buffersize], p=0b00000000;
    int inp =90;
    printf("\n");
    printf("Binary: ");
    char b[10]="0b00001001";
    binaryn(bin,inp);

    for (int i = 0; i < buffersize; ++i){
        printf("%d", bin[i]);
        if (bin[i]!=0){
            p = p | (1 << (7-i));
        }
    }

    printf("\nString: %s\n",b);
    printf("pa: %p\n",&p);
    printf("pv: %d\n",p);
*/


/*
 *  << test
 *
    printf("\n%d",1<<0);
    printf("%d",1<<1);
    printf("%d",1<<2);
    printf("%d",1<<3);
    printf("\nSP : %d",(12 & (1<<0)));
    printf("\nSP : %d",(12 & (1<<1)));
    printf("\nSP : %d",(12 & (1<<2)));
    printf("\nSP : %d",(12 & (1<<3)));

*/

/*
 * abandoned binary algorithm
 *
    long temp, a = 43;

    int Arr[64] = {};

    for (int i = 0; i < 64; i++){
        temp = a % 2;
        if ( temp != 0){
            Arr[i] = 1;
        } else{
            Arr[i] = 0;
        }
        if (a != 0) a = a/2;
    }

*/

/*
 * Array copying practice
 *
    int *s[64];

    printf("Srr address: %p\n", s);
    printf("Arr address: %p\n", Arr);

    for (int k = 0; k < 64; ++k) {
        s[k] = &Arr[k];

    }

    printf("Size of S: %d\n", (int)(sizeof(s)/sizeof(s[0])));
    printf("Size of Arr: %d\n", (int)(sizeof(Arr)/sizeof(Arr[0])));

    printf("Arr :");
    for (int j = 0; j < (int)(sizeof(Arr)/sizeof(Arr[0])); ++j) {

        printf("%d", Arr[j]);
    }

    printf("\nSrr :");

    for (int j = 0; j < (int)(sizeof(s)/sizeof(s[0])); ++j) {

        printf("%d", *s[j]);
    }
*/



    return 0;
}