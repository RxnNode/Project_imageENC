#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void binaryn(int *ptr, long long n){
    for (int i = sizeof(n)*CHAR_BIT - 1; i >= 0; --i) {
        *ptr++ = (n>>i) & 1;
    }
}
int main() {
    
    int *k[65];

    long long inp =9223372036854775807;
    int binbuf[64];

    binaryn(binbuf,inp);

    for (int i = 0; i < sizeof inp * CHAR_BIT; ++i)
        printf("%d", binbuf[i]);

    printf("\n");

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