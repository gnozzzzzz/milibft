#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

static void hexadecima(int i)
{
    char allhexadecimalsmay[] = "0123456789ABCDEF"; 
    char allhexadecimalsmin[] = "0123456789abcdef";
    while (i > 0)
    {
        int temp;
        temp = i%16;
        write(1,&allhexadecimalsmin[temp], 1); 
        i = i/16;
    }
}

static void punterea(void *j)
{
    int prime[5] = {2,3,5,7,11};
    printf("array = %p, array + 1 = %p\n", &prime, &prime + 1);
    for( int i = 0; i < 5; i++)
    {
        printf("index = %i, address = %p, value = %d\n", i, &prime[i], prime[i]);
    }
}


int ft_printf(char const *texto , ...)
{
    int indice;
    va_list argumentos;
    va_start(argumentos, texto);

    indice = 0;
    while(*(texto + indice) != 0)
    {
        if(*(texto + indice) == '%')
        {
            indice ++;
            if (*(texto + indice) == 'c')                       /// un solo caracter
            {
                indice ++;
                char aponer = va_arg(argumentos, int);
                write(1, &aponer, 1);
            }
            else if (*(texto + indice) == 's')                  /// una string
            {
                indice ++;
                char *aponer = va_arg(argumentos, char *);
                write(1,aponer, ft_strlen(aponer));    
            }
            else if (*(texto + indice) == 'p')                  /// puntero void * en hexadecimal
            {
                indice ++;
                punterea(va_arg(argumentos, void *));
            }
            else if (*(texto + indice) == 'd')                  /// numero decimal
            {
                indice ++;
                int numero = va_arg(argumentos, int);
                char *aponer = ft_itoa(numero);
                write(1,aponer, ft_strlen(aponer));    
            }
            else if (*(texto + indice) == 'i')                  /// entero base 10
            {
                indice ++;
                int numero = va_arg(argumentos, int);
                char *aponer = ft_itoa(numero);
                write(1,aponer, ft_strlen(aponer));    
            }
            else if (*(texto + indice) == 'u')                  /// numero decimal sin signo
            {
                indice ++;
                int numero = va_arg(argumentos, int);
                if (numero < 0)
                    numero *= -1;
                char *aponer = ft_itoa(numero);
                write(1,aponer, ft_strlen(aponer));    
            }
            else if (*(texto + indice) == 'x')                  /// numero hexadecimal en minusculas
            {
                indice ++;
                int numero = va_arg(argumentos, int);
                hexadecima(numero);
            }
            else if (*(texto + indice) == 'X')                  /// numero hexadecimal mayusculas
            {
                indice ++;
                int numero = va_arg(argumentos, int);
                hexadecima(numero);
            }
            else if (*(texto + indice) == '%')
            {
                indice ++;
                write(1,"%",1);  
            }
        }
        else
        {
            write(1,(texto + indice), 1);
            indice ++;
        }
        
    }
    return(1);
}

int main()
{
    //ft_printf("hola %s mundo 1 \n", "- argumento 1 -");
    ft_printf("el resultado es:\n%p\n", 255);
    //ft_printf("hola %d mundo 3 \n", -123);
    //ft_printf("hola mundo % 3 \n", 123);    
    return (1);
}