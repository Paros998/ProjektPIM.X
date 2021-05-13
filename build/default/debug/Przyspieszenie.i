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
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\string.h" 1 3





# 1 "E:/MPLAB/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\__size_t.h" 1 3



typedef unsigned size_t;
# 6 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\string.h" 2 3

# 1 "E:/MPLAB/packs/Microchip/PIC16Fxxx_DFP/1.2.33/xc8\\pic\\include\\__null.h" 1 3
# 7 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\string.h" 2 3







extern void * memcpy(void *, const void *, size_t);
extern void * memmove(void *, const void *, size_t);
extern void * memset(void *, int, size_t);
# 36 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\string.h" 3
extern char * strcat(char *, const char *);
extern char * strcpy(char *, const char *);
extern char * strncat(char *, const char *, size_t);
extern char * strncpy(char *, const char *, size_t);
extern char * strdup(const char *);
extern char * strtok(char *, const char *);


extern int memcmp(const void *, const void *, size_t);
extern int strcmp(const char *, const char *);
extern int stricmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern int strnicmp(const char *, const char *, size_t);
extern void * memchr(const void *, int, size_t);
extern size_t strcspn(const char *, const char *);
extern char * strpbrk(const char *, const char *);
extern size_t strspn(const char *, const char *);
extern char * strstr(const char *, const char *);
extern char * stristr(const char *, const char *);
extern char * strerror(int);
extern size_t strlen(const char *);
extern char * strchr(const char *, int);
extern char * strichr(const char *, int);
extern char * strrchr(const char *, int);
extern char * strrichr(const char *, int);
# 15 "./Przyspieszenie.h" 2

# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 1 3
# 11 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdarg.h" 1 3






typedef void * va_list[1];

#pragma intrinsic(__va_start)
extern void * __va_start(void);

#pragma intrinsic(__va_arg)
extern void * __va_arg(void *, ...);
# 11 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 2 3
# 43 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
struct __prbuf
{
 char * ptr;
 void (* func)(char);
};
# 85 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\conio.h" 1 3







# 1 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\errno.h" 1 3
# 29 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\errno.h" 3
extern int errno;
# 8 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\conio.h" 2 3




extern void init_uart(void);

extern char getch(void);
extern char getche(void);
extern void putch(char);
extern void ungetch(char);

extern __bit kbhit(void);



extern char * cgets(char *);
extern void cputs(const char *);
# 85 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 2 3



extern int cprintf(char *, ...);
#pragma printf_check(cprintf)



extern int _doprnt(struct __prbuf *, const register char *, register va_list);
# 180 "C:\\Program Files\\Microchip\\xc8\\v2.32\\pic\\include\\c90\\stdio.h" 3
#pragma printf_check(vprintf) const
#pragma printf_check(vsprintf) const

extern char * gets(char *);
extern int puts(const char *);
extern int scanf(const char *, ...) __attribute__((unsupported("scanf() is not supported by this compiler")));
extern int sscanf(const char *, const char *, ...) __attribute__((unsupported("sscanf() is not supported by this compiler")));
extern int vprintf(const char *, va_list) __attribute__((unsupported("vprintf() is not supported by this compiler")));
extern int vsprintf(char *, const char *, va_list) __attribute__((unsupported("vsprintf() is not supported by this compiler")));
extern int vscanf(const char *, va_list ap) __attribute__((unsupported("vscanf() is not supported by this compiler")));
extern int vsscanf(const char *, const char *, va_list) __attribute__((unsupported("vsscanf() is not supported by this compiler")));

#pragma printf_check(printf) const
#pragma printf_check(sprintf) const
extern int sprintf(char *, const char *, ...);
extern int printf(const char *, ...);
# 16 "./Przyspieszenie.h" 2


extern double policz_przyspieszenie(double t);

extern void wyswietl(char tab[]);
extern void konwersja_na_bity(double wart, char wynik[]);
# 1 "Przyspieszenie.c" 2


 double policz_przyspieszenie(double t)
{
    return t * 2 * 3.14159;;
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
