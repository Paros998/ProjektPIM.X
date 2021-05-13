/* 
 * File:   Przyspieszenie.h
 * Author: part4
 *
 * Created on 21 kwietnia 2021, 17:08
 */

#ifdef	__cplusplus
extern "C" {
#endif

#ifndef PRZYSPIESZENIE_H_INCLUDED
#define PRZYSPIESZENIE_H_INCLUDED

#include <string.h>
#include <stdio.h>
#define PI 3.14159;    
extern double policz_przyspieszenie(double t);

extern void wyswietl(char tab[]);
extern void konwersja_na_bity(double wart, char wynik[]);

#endif // PRZYSPIESZENIE_H_INCLUDED


#ifdef	__cplusplus
}
#endif



