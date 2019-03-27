#include <stdio.h>
FILE *dir;
FILE *name;

int main() {

    long a = 32, temp;
    int Arr[64] = {0};

    for (int i = 0; i < 64; i++){

        temp = a % 2;

        if ( temp != 0){
            Arr[i] = 1;
        } else{
            Arr[i] = 0;
        }
        if (a != 0) a = a/2;

    }
    for (int j = 63; j >= 0 ; j--) {
        printf("%d", Arr[j]);
    }

    return 0;
}