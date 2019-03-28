#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <MacTypes.h>
#define INT_BIT 2


void binaryn(int *ptr, int n){
    for (int i = sizeof(n)*INT_BIT - 1; i >= 0; --i) {
        *ptr++ = (n>>i) & 1;
    }
}
int main() {

    FILE *dir;
    FILE *out;
    FILE *outtest;
    int c,co,count=0;
    Boolean test = false, t = true;

    dir = fopen("../images/image.jpg","r+b");

    if (dir== NULL){
        printf("Can't read file.");
        perror("Error");
    } else{
        printf("Read image successfully.\n");
        out = fopen("../out.txt","wb+");
        if (out){
            while ((c=fgetc(dir))!=EOF) {
                int binbuf[8];
                binaryn(binbuf, c);
                if (t) {
                    for (int i = 0; i < 8; ++i) {
                        fputc(binbuf[i], out);
                        printf("%d", binbuf[i]);
                    }
                    //t = false;
                }
                count++;
            }
            printf("\n%d byte read.\n",count);
            printf("Create a output file successfully.");
            test = true;
        } else{
            printf("Can't create a output file.");
            perror("Error");
        }
        fclose(dir);
        fclose(out);
    }

    if (test){

        FILE *cmess;
        cmess = fopen("../Enc/Enc/secret","rb+");
        if (cmess){
            printf("Read message successfully.\n");

        } else{
            printf("Can't read message file.");
            perror("Error");
        }

    } else{

    }




/*
 *  output file check
 *
    outtest = fopen("../out.txt","rb");

    if (outtest == NULL){
        perror("Error");
    } else{
        printf("\nStart checking output file...\n");
        while ((co=fgetc(outtest))!=EOF){
            printf("%d",co);
        }
    }
*/

/*
 *  binary convert test
 *
    int bin[64];
    long long inp =9223372036854775807;
    printf("\n");
    printf("Binary: ");
    binaryn(bin,inp);

    for (int i = 0; i < sizeof inp * CHAR_BIT; ++i)
        printf("%d", bin[i]);

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