#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"
#include "libftprintf.h"


int main()
{
    char* texto = "1";
    char* texto2 = "xxadiosxx";
    int i1;
    int i2;

    i1 = ft_printf("123:%c\n", 'X');
    i2 = printf("123:%c\n", 'X');
    printf("num = %i\n", i1);
    printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%s\n", texto);
    i2 = printf("123:%s\n", texto);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%p\n", texto);
    i2 = printf("123:%p\n", texto);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%d\n", -123);
    i2 = printf("123:%d\n", -123);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%i\n", -123);
    i2 = printf("123:%i\n", -123);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%u\n", 123);
    i2 = printf("123:%u\n", 123);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%x\n", 123);
    i2 = printf("123:%x\n", 123);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    i1 = ft_printf("123:%X\n", 123);
    i2 = printf("123:%X\n", 123);
    ft_printf("num = %i\n", i1);
    ft_printf("num = %i\n\n", i2);

    return (1);
}