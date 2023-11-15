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

static void suma(int *a, int b)
{
    *a = *a + b;
}

static void punterea(void *j)
{
    int a = 1;
    int *c = &a;
    int b = 2;
    suma(c,b);
    printf("%i , %i", a, b);
    /*char cadena[] = "holamundo";

    printf("la cadena esta : %p\n", cadena);    /// devuelven lo mismo como puntero, pero da error al tratar de sacar la cadena en la segunda
    printf("la cadena esta : %p\n", &cadena);   ///
    */
    /*int marks[5][3] = { { 98, 76, 89},
                    { 81, 96, 79},
                    { 88, 86, 89},
                    { 97, 94, 99},
                    { 92, 81, 59}
                  };

    printf("Address of 0th array = %p\n", marks);
    printf("Addition of 1 results in %p\n", marks +1);
    printf("Address of 0th array =%p\n", &marks[0]);
    printf("Addition of 1 results in %p\n", &marks[0] + 1);

    printf("Value of 0th element of 0th array = %d\n", *(marks[2]+1));
    printf("Value of 0th element of 0th array = %d\n", *(*(marks + 1)+1));
    printf("Addition of 1 results in %d", marks[0][0] + 1);*/

    /*int prime[5] = {2,3,5,7,11};
    printf("array = %p, array + 1 = %p\n", &prime, &prime + 1);
    for( int i = 0; i < 5; i++)
    {
        printf("index = %i, address = %p, value = %d\n", i, &prime[i], prime[i]);
        printf("index = %i, address = %p, value = %d\n", i, prime + i, *(prime + i));
    }*/
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
    ft_printf("el resultado es:\n%p", 255);
    //ft_printf("hola %d mundo 3 \n", -123);
    //ft_printf("hola mundo % 3 \n", 123);    
    return (1);
}