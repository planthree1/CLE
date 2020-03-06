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
    bool is_multi_byte = false;
    
    /*opens the file*/
    FILE *file;
    file = fopen("text.txt", "r");
    
    if (file) {
        while ((byte = getc(file)) != EOF ) {
            /* every array with 2 bytes always start with either c2 or c3 */
            
            if (is_multi_byte) { /*its inside a multi-byte character*/
                
                /*verificar se é um caracter que termina a frase*/
                if (byte == asd ){
                    
                }
                
                /*tratar informação*/
                
                is_multi_byte = false;
            }
            
            if ( byte == 0xc2 || byte == 0xc3){
                is_multi_byte = true;
            } else {
                
                /*verificar se é um caracter que termina a frase*/
                if (byte == asd ){
                    
                }
                
                /* tratar informação*/
                
            }
        }
        
    }
    
    fclose(file);
            
    return (EXIT_SUCCESS);
}