#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include"libftprintf.h"
#include"ftprintffuncs.h"

int ft_printf(char const *texto , ...)
{
    int indice;
    int extra;
    va_list argumentos;
    va_start(argumentos, texto);

    indice = 0;
    extra = 0;
    while(*(texto + indice) != 0)
    {
        if(*(texto + indice) == '%')
        {
            indice ++;
            if (*(texto + indice) == 'c')                       /// un solo caracter        DONE
                extra += recibeletra(&argumentos);
            else if (*(texto + indice) == 's')                  /// una string      DONE
                extra += recibepalabra(&argumentos);
            else if (*(texto + indice) == 'p')                  /// puntero void * en hexadecimal       DONE
                extra += hexadecimalong((unsigned long long int)va_arg(argumentos, void*));
            else if (*(texto + indice) == 'd')                  /// numero decimal      DONE
                extra += recibenumdec(&argumentos);
            else if (*(texto + indice) == 'i')                  /// entero base 10      DONE
                extra += recibenumdec(&argumentos);
            else if (*(texto + indice) == 'u')                  /// numero decimal sin signo    DONE
                extra += recibeunsigdec(&argumentos);
            else if (*(texto + indice) == 'x')                  /// numero hexadecimal en minusculas
                extra += hexadecimamin(va_arg(argumentos, int));
            else if (*(texto + indice) == 'X')                  /// numero hexadecimal mayusculas
                extra += hexadecimamay(va_arg(argumentos, int));
            else if (*(texto + indice) == '%')
            {
                write(1, "%", 1);
                extra -= 1;
            }
            indice++;
        }
        else
            write(1,(texto + indice++), 1);
    }
    return(indice + extra );
}