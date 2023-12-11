/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomez-m <ggomez-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:12:05 by ggomez-m          #+#    #+#             */
/*   Updated: 2023/12/05 14:12:21 by ggomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"
#include "ftprintffuncs.h"

static int	lee_letra(char c, va_list *argumentos)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += recibeletra(argumentos);
	else if (c == 's')
		i += recibepalabra(va_arg(*argumentos, char *));
	else if (c == 'p')
		i += hxdclng(argumentos);
	else if (c == 'd')
		i += recibenumdec(argumentos);
	else if (c == 'i')
		i += recibenumdec(argumentos);
	else if (c == 'u')
		i += recibeunsigdec(argumentos);
	else if (c == 'x')
		i += hexadecimamin(va_arg(*argumentos, int));
	else if (c == 'X')
		i += hexadecimamay(va_arg(*argumentos, int));
	else if (c == '%')
	{
		write(1, "%", 1);
		i -= 1;
	}
	return (i);
}

int	ft_printf(char const *texto, ...)
{
	int		indice;
	int		extra;
	va_list	argumentos;

	va_start(argumentos, texto);
	indice = 0;
	extra = 0;
	while (*(texto + indice) != 0)
	{
		if (*(texto + indice) == '%')
		{
			indice ++;
			extra += lee_letra (*(texto + indice), &argumentos);
			indice++;
		}
		else
			write (1, (texto + indice++), 1);
	}
	va_end(argumentos);
	return (indice + extra);
}
