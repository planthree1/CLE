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

/**
 * Return true if the char/byte is a symbol that represents a word or phrase ending.
 * @param byte
 * @return 
 */
bool isEndOfWord(char byte) {
    if (byte == (char) 0x20 || byte == (char) 0x2d || byte == (char) 0x9 || byte == (char) 0xA || byte == (char) 0x22 || byte == (char) 0xE2809C || byte == (char) 0xe2809D || byte == (char) 0x5b || byte == (char) 0x5d || byte == (char) 0x28 || byte == (char) 0x29 || byte == (char) 0x2e || byte == (char) 0x2c || byte == (char) 0x3a || byte == (char) 0x3b || byte == (char) 0x3f || byte == (char) 0x21 || byte == (char) 0xE28093 || byte == (char) 0xE280A6) {
        return true;
    }
    return false;
}

/**
 * This function return true is the char/byte is a vowel.
 * @param byte
 * @return 
 */
bool isVowel(char byte) {
    if (byte == (char) 0x61 || byte == (char) 0x41 || byte == (char) 0x65 || byte == (char) 0x45 || byte == (char) 0x69 || byte == (char) 0x49 || byte == (char) 0x6f || byte == (char) 0x4f || byte ==(char) 0x75 || byte == (char) 0x55) {
        return true;
    }
    return false;
}

/**
 * Return true is the byte represents the first byte of a multi-byte character
 * @param byte
 * @return 
 */
bool isTwoByteChar(char byte) {
    if (byte == (char) 0xc2 | byte == (char) 0xc3) {
        return true;
    }
    return false;
}

bool isThreeByteChar(char byte) {
    if (byte == (char) 0xe2) {
        return true;
    }
    return false;
}

/**
 * Return true if is "A" character family
 * @param byte
 * @return 
 */
bool isACharFamily(char byte) {
    // Respectively á, à, â, ã, Á, À, Â, Ã
    if (byte == (char) 0xa1 || byte == (char) 0xa0 || byte == (char) 0xa2 || byte == (char) 0xa3 || byte == (char) 0x81 || byte == (char) 0x80 || byte == (char) 0x82 || byte == (char) 0x83) {
        return true;
    }
    return false;
}

/**
 * Return true if is "A" character family
 * @param byte
 * @return 
 */
bool isECharFamily(char byte) {
    // Respectively é, è, ê, É, È, Ê
    if (byte == (char) 0xa9 || byte == (char) 0xa8 || byte == (char) 0xaa || byte == (char) 0x89 || byte == (char) 0x88 || byte == (char) 0x8a) {
        return true;
    }
    return false;
}

/**
 * Return true if is "A" character family
 * @param byte
 * @return 
 */
bool isICharFamily(char byte) {
    // Respectively í, ì, Í, Ì
    if (byte == (char) 0xad || byte == (char) 0xac || byte == (char) 0x8d || byte == (char) 0x8c) {
        return true;
    }
    return false;
}

/**
 * Return true if is "A" character family
 * @param byte
 * @return 
 */
bool isOCharFamily(char byte) {
    // Respectively ó, ò, ô, õ, Ó, Ò, Ô, Õ
    if (byte == (char) 0xb9 || byte == (char) 0xb2 || byte == (char) 0xb4 || byte == (char) 0xb5 || byte == (char) 0x93 || byte == (char) 0x92 || byte == (char) 0x94 || byte == (char) 0x95) {
        return true;
    }
    return false;
}

/**
 * Return true if is "A" character family
 * @param byte
 * @return 
 */
bool isUCharFamily(char byte) {
    // Respectively ú, ù, Ú, Ù
    if (byte == (char) 0xba || byte == (char) 0xb9 || byte == (char) 0x9a || byte == (char) 0x99) {
        return true;
    }
    return false;
}

/**
 * Return true if is "C" character family
 * @param byte
 * @return 
 */
bool isCCharFamily(char byte) {
    // Respectively ç, Ç
    if (byte == (char) 0xa7 || byte == (char) 0x87) {
        return true;
    }
    return false;
}


int main(int argc, char** argv) {
    /*var declaration*/
    char byte;

    bool isTwoByte = false;
    bool isThreeByte = false;
    int counteThreeByte = 0;
    int vogals, wordSize,maxSize = 0;
    int *numberOfLetters,*numberOfVogals,i;
    
    /*opens the file*/
    FILE *file;
    file = fopen("text0.txt", "r");
    /*checks the worst case scenario*/
    int n = 0;
    bool multbyte = false;
    if (file) {
        while ((byte = getc(file)) != EOF ) {
            if (multbyte){
                n++;
                multbyte = false;
            } else {
                if (isEndOfWord(byte)) {
                    if(n > maxSize) {
                        maxSize = n;
                    }
                    n = 0;
                } else {
                    if (!isTwoByteChar(byte)) {
                        n++;
                    } else {
                        multbyte = true;
                    }
                }
            }
            
        }
        maxSize+=1;
    }
    fclose(file);
    /*save n bytes*/
    numberOfLetters = (int*)calloc(maxSize, sizeof(int));
    numberOfVogals = (int*)calloc(maxSize*maxSize, sizeof(int));

    file = fopen("text0.txt", "r");
    
    if (file) {
        while ((byte = getc(file)) != EOF ) {
            /* every array with 2 bytes always start with either c2 or c3 */
            if (isThreeByte) {
                counteThreeByte--;
                if (counteThreeByte == 0){
                    isThreeByte = false;
                }
                
            } else {
                if (isTwoByte) {
                    if (byte != (char) 0x80 || byte != (char) 0x92){
                        wordSize++;
                        if (isACharFamily(byte) || isECharFamily(byte) || isICharFamily(byte) || isOCharFamily(byte) || isUCharFamily(byte)) {
                            vogals++;
                        }
                        isTwoByte = false;
                    }
                /*its inside a multi-byte character*/
                /*tratar informação*/
                } else {
                    if (isTwoByteChar(byte)){
                        isTwoByte = true;
                    } else {
                        if (isThreeByteChar(byte)){
                        isThreeByte = true;
                        counteThreeByte = 2;
                    } else {
                        /*verificar se é um caracter que termina a frase*/
                        if (isEndOfWord(byte)) {
                            if (wordSize != 0) {
                                if (wordSize == 7) {
                                    printf("%d max size\n", maxSize);
                                    printf("%d vogals\n", vogals);
                                }
                                numberOfLetters[wordSize] ++;
                                numberOfVogals[(wordSize*maxSize) - maxSize + vogals] ++;
                                wordSize = 0;
                                vogals = 0;
                            }
                        }  else {
                                /*não contar se for - ou '*/
                                if (byte != 0x27){
                                    wordSize ++;
                                    /*verifica se o byte é um a ou A*/
                                    if (isVowel(byte)) {
                                        vogals++;
                                    }
                                }

                            }
                    }
                        
                    } 
                }
            }
            
            
        }
        if (wordSize != 0) {
            if (wordSize == 7) {
                printf("%d max size\n", maxSize);
                printf("%d vogals\n", vogals);
            }
            numberOfLetters[wordSize] ++;
            numberOfVogals[(wordSize*maxSize) - maxSize + vogals] ++;
            wordSize = 0;
            vogals = 0;
        }
        int i;
        for (i=0; i<maxSize ;i++){
            printf("there is %d words with %d letters \n",numberOfLetters[i], i);
        }
        
        printf("\n\n");
        int x = 0;
        for (i=0; i< (maxSize*maxSize) - maxSize ;i = i+maxSize){
            printf("the words with %d letters:", (i/maxSize) +1);
            for (x=0; x <(maxSize); x++){
                printf("\n%d ocurrences of vogals, in %d letters ", numberOfVogals[i+x],x );
            }
            printf("\n");
            
        }
        
    }
    
    fclose(file);
            
    return (EXIT_SUCCESS);
}