/*
 * File:   main.c
 * Author: part4
 *
 * Created on 20 kwietnia 2021, 18:04
 */
#include "Przyspieszenie.h"
#include <stdio.h>
#include <xc.h>
#define maskaTR 0b00000100;
#define captureMode 0b00000101;
#define TCY 0.0000002;
#define PI 3.14159;

void __interrupt() zero(void){
    if(CCP1IF == 1){
        
        CCP1IF = 0;
    } 
}

void main(void) {
    int counter = 1;
    int Obrot1 = 0;
    int Obrot2 = 0;
    double roznica = 0;
    double przysp = 0;
    TRISC = maskaTR;
    TMR1CS = 0;
    TMR1ON = 1;
    CCP1CON = captureMode;
    while(1){
        if(RC2 == 1){
            if(counter == 1) 
                Obrot1 = (int) CCPR1;
            else if(counter == 2)
                Obrot2 = (int) CCPR1;
            counter++;
            if(counter == 3){
                roznica = (double)Obrot2 - (double)Obrot1;
                roznica *= TCY;
                przysp = roznica * 2 * PI; 
                printf("%ld",przysp);
                counter = 1;
                Obrot1 = Obrot2 = 0 ;
            }   
        }
    }
}
