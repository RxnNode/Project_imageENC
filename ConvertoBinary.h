//
// Created by Yung-An Jen on 2019-03-27.
//

#ifndef PROJECT_IMAGEENC_CONVERTOBINARY_H
#define PROJECT_IMAGEENC_CONVERTOBINARY_H

#endif //PROJECT_IMAGEENC_CONVERTOBINARY_H

int *bianry (long a){

    long temp;
    double *pointer;
    int Arr[64] = {0};

    for (int i = 0; i < 64; i++){
        temp = a % 2;
        if ( temp != 0){
            Arr[63 - i] = 1;
        } else{
            Arr[63 - i] = 0;
        }
        if (a != 0) a = a/2;
    }

    pointer = Arr;
    return pointer;

}