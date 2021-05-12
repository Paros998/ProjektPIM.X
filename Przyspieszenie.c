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

void wyswietl(char tab[])
{
    for(int i = 0; i < strlen(tab); i++)
        printf("%c", tab[i]);
    puts("");
}

void konwersja_na_bity(double wart, char wynik[])
{
    int cz_calk = (int)wart;
    double cz_ulamk = wart - cz_calk;
    double n = wart;

    wynik[0] = (char)(cz_calk + '0');
    wynik[1] = '.';

    for(int i = 2; i < 9; i++)
    {
        n = cz_ulamk * 2;
        cz_calk = (int)n;
        cz_ulamk = n - cz_calk;
        wynik[i] = cz_calk > 0 ? '1' : '0';
    }
}
