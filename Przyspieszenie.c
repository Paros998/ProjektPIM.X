#include "Przyspieszenie.h"
#define PI 3.14159

static double policz_predkosc_katowa(double t)
{
    return 2 * PI / t;
}

double policz_szybkosc(double R, double t)
{
    double  w = policz_predkosc_katowa(t);

    return w * R;
}

double policz_przyspieszenie_katowe(double R, double t)
{
    double  w = policz_predkosc_katowa(t);

    return w / t;
}

double policz_przyspieszenie_styczne(double R, double t)
{
    double E = policz_przyspieszenie_katowe(R, t);

    return E * R;
}
