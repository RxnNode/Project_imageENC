#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <MacTypes.h>
#include <setjmp.h>
#include <jpeglib.h>
#include <jerror.h>
#define INT_BIT 2
#define buffersize 8

void binaryn(int *ptr, int n){
    for (int i = sizeof(n)*INT_BIT - 1; i >= 0; --i) {
        *ptr++ = (n>>i) & 1;
    }
}

int main() {






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
    printf("\nSP : %d",(951 & (1<<9)));
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