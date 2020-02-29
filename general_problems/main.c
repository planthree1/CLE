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
#include <stdlib.h>


int main(int argc, char** argv) {
    
    /*
    unsigned char a[] = "á";
    printf("á = %hhx \n" , a[1]);
    */
    
    /* Create text file */
    
    FILE* pf = NULL;
    pf = fopen("texto.txt", "w");
    fprintf(pf, "%s", "áéíóúá ");
    fclose(pf);
    
    
    /* Count the number of characters*/
    FILE* fp;
    int count = 0;
    char c; 
    fp = fopen("texto.txt", "r"); 
    if (fp == NULL) {
        return 0; 
    }
    for (c = getc(fp); c != EOF; c = getc(fp)) count = count + 1;
    fclose(fp);
    /*
    printf("The file has %d characters\n ", count); 
    printf("next \n"); 
    */
    /* Read text file*/
    int character; /* n is the character */
    int vogals = 0;
    int number_of_letters[20] = {0};
    int number_of_vogals[20] = {0};
    
    FILE *file;
    file = fopen("texto.txt", "r");
    
    if (file) {
        int word_end = 0;
        while ((character = getc(file)) != EOF) {
            if ( character == 0x20 || character == 0x9 || character == 0xA || character == 0x2d || character == 0x22 || character == 0xE2809C || character ==  0xe2809D || character == 0x5b ||character == 0x5d || character == 0x28 || character == 0x29 || character == 0x2e || character == 0x2c || character == 0x3a || character == 0x3b || character == 0x3f || character == 0x21 || character == 0xE28093 || character == 0xE280A6) {
                /* evita  incrementar no caso de varios espaços ou \n*/
                if (word_end != 0) {
                    number_of_letters[word_end]++;
                    number_of_vogals[word_end] += vogals;
                    word_end = 0;
                    vogals = 0;
                }
            } else {
                /* Identifica que é um 'a' e conta as vogais*/
                if ( character == 0xA1 || character == 0xA0 || character == 0xA2 || character <= 0xA3 || character == 0x81 || character == 0x80 || character == 0x82 || character == 0x83 || character == 0x41 || character == 0x61) {
                    vogals++;
                }
                /* Identifica que é um 'e' e conta as vogais*/
                if ( character == 0xA9 || character == 0xA9 || character == 0xAA || character <= 0x89 || character == 0x88 || character == 0x8A || character == 0x65 || character == 0x45) {
                    vogals++;
                }
                /* Identifica que é um 'i' e conta as vogais*/
                if (character == 0xAD || character == 0xAC || character == 0x8D || character == 0x8C || character == 0x69 || character == 0x49) {
                    vogals++;
                }
                /* Identifica que é um 'o' e conta as vogais*/
                if (character == 0xB3 || character == 0xB2 || character == 0xB4 || character == 0xB5 || character == 0x93 || character <= 0x92 || character == 0x94 || character == 0x95 || character == 0x6F || character == 0x4F) {
                    vogals++;
                }
                /* Identifica que é um 'u' e conta as vogais*/
                if (character == 0xBA || character == 0xB9 || character == 0x9A || character == 0x99 || character == 0x75 || character == 0x55) {
                    vogals++;
                }
                word_end++;
            }
        }
        number_of_letters[word_end]++;
        number_of_vogals[word_end] += vogals;
        word_end = 0;
        vogals = 0;
        fclose(file);
    }
    
    int counter;
    printf("number of letters : \n");
    for(counter = 0; counter < 20; counter++){
        printf(" %d ", number_of_letters[counter]);
    }
    
    printf("\nnumber of vogals : \n");
    for(counter = 0; counter < 20; counter++){
        printf(" %d ", number_of_vogals[counter]);
    }
    
    return (0);
}