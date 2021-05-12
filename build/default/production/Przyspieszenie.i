# 1 "Przyspieszenie.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "E:/MPLAB/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "Przyspieszenie.c" 2
# 1 "./Przyspieszenie.h" 1
# 15 "./Przyspieszenie.h"
extern double policz_szybkosc(double R, double t);
extern double policz_przyspieszenie_katowe(double R, double t);
extern double policz_przyspieszenie_styczne(double R, double t);
# 1 "Przyspieszenie.c" 2



static double policz_predkosc_katowa(double t)
{
    return 2 * 3.14159 / t;
}

double policz_szybkosc(double R, double t)
{
    double w = policz_predkosc_katowa(t);

    return w * R;
}

double policz_przyspieszenie_katowe(double R, double t)
{
    double w = policz_predkosc_katowa(t);

    return w / t;
}

double policz_przyspieszenie_styczne(double R, double t)
{
    double E = policz_przyspieszenie_katowe(R, t);

    return E * R;
}
