#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

static char *hexadecima(int i)
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
    return (NULL);
}


static char *hexadecima2(int i)
{
    int digitos = 0;
    int copia;
    int index;
    char *resultado; 
    char allhexadecimalsmay[] = "0123456789ABCDEF"; 
    char allhexadecimalsmin[] = "0123456789abcdef";

    copia = i;
    while (copia > 0)
    {
        copia = copia/16;
        digitos ++;
    }
    resultado = malloc (sizeof(char) * digitos);
    index = digitos - 1;
    while (i > 0)
    {
        int temp;
        temp = i%16;
        i = i/16;
        resultado[index] = allhexadecimalsmin[temp];;
        index --;
    }
    /*char duplicate[digitos];
    while(digitos > 0)
    {
        digitos --;
        duplicate[digitos] = resultado[digitos];
    }*/
    return (resultado);
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
                int numero = va_arg(argumentos, int);
                char *aponer = hexadecima(numero);
                write(1,aponer, ft_strlen(aponer));
                free (aponer);
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
                char *aponer = hexadecima(numero);
                //write(1,aponer, ft_strlen(aponer));    
            }
            else if (*(texto + indice) == 'X')                  /// numero hexadecimal mayusculas
            {
                indice ++;
                int numero = va_arg(argumentos, int);
                char *aponer = hexadecima(numero);
                write(1,aponer, ft_strlen(aponer));    
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
    ft_printf("el resultado es: %x\n", 255);
    //ft_printf("hola %d mundo 3 \n", -123);
    //ft_printf("hola mundo % 3 \n", 123);    
    return (1);
}