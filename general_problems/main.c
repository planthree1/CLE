/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: TiagoRodrigues
 *
 * Created on 11 de Fevereiro de 2020, 17:08
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


int main(int argc, char** argv) {
    /*var declaration*/
    
    char byte;
    bool isMultiByte = false;
    int vogals, wordSize, n, maxSize = 0;
    int *numberOfLetters,*numberOfVogals,i;
    
    /*opens the file*/
    FILE *file;
    file = fopen("text.txt", "r");
    
    /*checks the worst case scenario*/
    if (file) {
        while ((byte = getc(file)) != EOF ) {
            if (byte ==  caracter que acaba a frase) {
                if(n >= maxSize) {
                    maxSize = n;
                }
                n = 0;
            } else {
                n++;
            }
        }
    }
    
    /*save n bytes*/
    numberOfLetters = (int*)calloc(maxSize, sizeof(int));
    numberOfVogals = (int*)calloc(maxSize*maxSize, sizeof(int));

    if (file) {
        while ((byte = getc(file)) != EOF ) {
            /* every array with 2 bytes always start with either c2 or c3 */
            
            if (isMultiByte) { /*its inside a multi-byte character*/
                
                /*tratar informação*/
                wordSize++;
                if ( verificar se  é um a com acento ){
                    vogals ++;
                }
                
                
                isMultiByte = false;
            }
            
            if ( byte == 0xc2 || byte == 0xc3){
                isMultiByte = true;
            } else {
                
                /*verificar se é um caracter que termina a frase*/
                if (encontrou caracter que acaba a palavra) {
                    numberOfLetters[wordSize] ++;
                    numberOfVogals[(wordSize*5)+vogals] ++;
                    wordSize = 0;
                    vogals = 0;
                }  else {
                    /* tratar informação*/
                    wordSize ++;
                    /*verifica se o byte é um a ou A*/
                    if (byte == 0x61 || byte == 0x41){
                        vogals ++;
                    }
                }
            }
        }
    }
    
    fclose(file);
            
    return (EXIT_SUCCESS);
}