#include <stdio.h>
#include <stdarg.h>
#include"ftprintffuncs.h"
#include "libft/libft.h"
void checknegadd(int *i) {
    if (*i < 0)
    {
        *i = -*i;
        write(1, "-", 1);
    }
}
int hexadecimamin(int i)
{
    int extra;
    char resultado[20];
    int j = 0;
    checknegadd(&i);
    int copia = i;
    char allhexadecimalsmin[] = "0123456789abcdef";
    while (copia > 0)
    {
        copia = copia / 16;
        j++;
    }
    extra = j;
    resultado[j] = '\0';
    while (i > 0)
    {
        j--;
        resultado[j] = allhexadecimalsmin[i % 16];
        i = i / 16;
    }
    while (resultado[j] != 0)
        write(1, &resultado[j++], 1);
    return(extra - 2);
}
int hexadecimamay(int i)
{
    int extra;
    char resultado[20];
    int j = 0;
    checknegadd(&i);
    int copia = i;
    char allhexadecimalsmin[] = "0123456789ABCDEF";
    while (copia > 0)
    {
        copia = copia / 16;
        j++;
    }
    extra = j;
    resultado[j] = '\0';
    while (i > 0)
    {
        j--;
        resultado[j] = allhexadecimalsmin[i % 16];
        i = i / 16;
    }
    while (resultado[j] != 0)
        write(1, &resultado[j++], 1);
    return(extra - 2);
}
int hexadecimalong(unsigned long long int i)
{
    int extra;
    write(1, "0x", 2);
    char resultado[20];
    int j = 0;
    unsigned long long int copia = i;
    char allhexadecimalsmin[] = "0123456789abcdef";
    while (copia > 0)
    {
        copia = copia / 16;
        j++;
    }
    extra = j + 2;
    resultado[j] = '\0';
    while (i > 0)
    {
        j--;
        resultado[j] = allhexadecimalsmin[i % 16];
        i = i / 16;
    }
    while (resultado[j] != 0)
        write(1, &resultado[j++], 1);
    return(extra - 2);
}
int recibeletra(va_list *argumentos)
{
    char aponer = va_arg(*argumentos, int);
    write(1, &aponer, 1);
    return (-1);
}
int recibepalabra(va_list* argumentos)
{
    int extra;

    char* aponer = va_arg(*argumentos, char*);
    extra = ft_strlen(aponer);
    write(1, aponer, extra);
    return (extra - 2);
}
int recibenumdec(va_list* argumentos)
{
    int extra;

    char* aponer = ft_itoa(va_arg(*argumentos, int));
    extra = ft_strlen(aponer);
    write(1, aponer, extra);
    return(extra -2);
}
int recibeunsigdec(va_list* argumentos)
{
    int extra = 0;
    int exextra = 0;
    int num = va_arg(*argumentos, int);
    if (num < 0)
    {
        exextra += 1;
        num *= -1;
    }
    char* aponer = ft_itoa(num);
    extra += ft_strlen(aponer);
    write(1, aponer, extra);
    return(extra + exextra - 2);
}