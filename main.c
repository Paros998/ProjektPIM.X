/*
 * File:   main.c
 * Author: part4
 *
 * Created on 20 kwietnia 2021, 18:04
 */
#include "Przyspieszenie.h"
#include <xc.h>
#define maskaTR 0b00000100;//Maska 8 bitowa do rejestru TRISC ustawiaj?ca port RC2/CCP1 na PORTC na tryb wej?ciowy , a reszte portów na wyj?cie
#define captureMode 0b00000101;//Maksa 8 bitowa do rejestru CCP1CON, która ustawia modu? CCP1 w tryb Capture na ka?dym rosn?cym zboczu
#define TCY 0.0000002;//Czas jednego cyklu w sekundach

int counter = 1;
long Obrot1 = 0;
long Obrot2 = 0;
double roznica = 0;
double przysp = 0;
char wynik[9];

void __interrupt() zero(void){
    if(CCP1IF == 1 && CCP1IE == 1){//Sprawdzenie czy przerwanie przysz?o z Uk?adu Capture
        if(counter == 1)//Sprawdzenie czy to przerwanie jest dla 1 obrotu ko?a
            Obrot1 = (long) CCPR1;//Zapisanie warto?ci ilo?ci cykli ,które up?yne?y zanim ko?o obróci?o si? po raz pierwszy
        else if(counter == 2)//Sprawdzenie czy to przerwanie jest dla 2 obrotu ko?a
            Obrot2 = (long) CCPR1;//Zapisanie warto?ci ilo?ci cykli ,które up?yne?y zanim ko?o obróci?o si? po raz drugi
        counter++;//Zwi?kszenie iteratora sprawdzaj?cego obroty
        if(counter == 3){//Sprawdzenie czy dosz?o do zatrza?ni?cia warto?ci dla obu obrotów ko?a
            roznica = (double)Obrot2 - (double)Obrot1;//Obliczenie ró?nicy w ilo?ci cykli mi?dzy obrotami
            roznica *= TCY;//Przeliczenie ró?nicy w cyklach na warto?? w sekundach
            przysp = policz_przyspieszenie(roznica);//Obliczenie przy?pieszenia w radianach na sekund?
            konwersja_na_bity(przysp,wynik);//Przekonwertowanie warto?ci double do liczby binarnej sta?oprzecinkowej 7 precyzji i wstawienie do tablicy charów
            counter = 1;//Zresetowanie p?tli
            Obrot1 = Obrot2  = 0;//I zmiennych
            roznica = przysp = 0.0;//I zmiennych
        }   
        CCP1IF = 0;//Wyzerowanie bitu przerwania
    }
    if(TMR1IF == 1 && TMR1IE == 1){//Sprawdzenie czy przerwanie przysz?o z modu?u Timer1
        counter = 1;//Zresetowanie p?tli sprawdzaj?cej
        Obrot1 = Obrot2  = 0;//I zmiennych
        roznica = przysp = 0.0;//I zmiennych
        TMR1 = 0;//Wyzerowanie warto?ci rejestrów timera
        TMR1IF = 0;//Wyzerowanie bitu przerwania
    }
}

void main(void) {
    TRISC = maskaTR; //TRISC - rejestr specjalny zarz?dzaj?cy I/O PORTU C , W??czenie nó?ki RC2 jako wej?ciowej
    CCP1CON = captureMode;//CCP1CON - rejestr specjalny zarz?dzaj?cy uk?adem Capture, W??czenie i Ustawienie trybu capture na nó?ke RC2
    
    GIE = 1;//W??czenie systemu przerwa? 
    PEIE = 1;//W??czenie przerwa? urz?dze? peryferyjnych
    CCP1IE = 1;//W??czenie przerwa? uk?adu capture
    TMR1IE = 1;//W??czenie przerwa? modu?u Timer1
    
    TMR1CS = 0;//Ustawienie ?ród?a zegara na wewn?trzny zegar Timera1
    TMR1ON = 1;//W??czenie modu?u Timer1
    while(1);      
}
