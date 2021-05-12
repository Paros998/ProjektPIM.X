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

extern double policz_szybkosc(double R, double t);
extern double policz_przyspieszenie_katowe(double R, double t);
extern double policz_przyspieszenie_styczne(double R, double t);

#endif // PRZYSPIESZENIE_H_INCLUDED


#ifdef	__cplusplus
}
#endif



