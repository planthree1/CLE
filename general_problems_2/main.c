/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: TiagoRodrigues
 *
 * Created on 9 de Março de 2020, 12:31
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

float circularCrossCorrelation (int k, int n, int t){
    return getX(k) * getY((t+k)%n);
}

int getX(int k){
    unsigned char *bufferX;
    bufferX = (int*)calloc(k, sizeof(int));
    FILE *ptrX;
    ptrX = fopen("sigVal2.bin","rb");  // r for read, b for binary
    
    fread(bufferX,sizeof(bufferX),1,ptrX);
    /*
    printf("%hhu\n ", bufferX[k]); // prints a series of bytes
    */
    return bufferX[k];
}

int getY(int k){
    unsigned char *bufferY;
    bufferY = (int*)calloc(k, sizeof(int));
    FILE *ptrY;

    ptrY = fopen("sigVal3.bin","rb");  // r for read, b for binary

    fread(bufferY,sizeof(bufferY),1,ptrY); // read 10 bytes to our buffer
    /*
    for(int i = 0; i<10; i++)
    printf("%hhu ", bufferY[i]); // prints a series of bytes
    */
    return bufferY[k];
}

int main(int argc, char** argv) {

    int t = 1;
    float CCC = 0;
    int k = 0;
    int n = 10;
    
    while (k < n){
        CCC += circularCrossCorrelation(k, n, t);
        k++;
    }
    printf("circular cross coorelation\n");
    printf("%f", CCC);
    
    return (EXIT_SUCCESS);
}

