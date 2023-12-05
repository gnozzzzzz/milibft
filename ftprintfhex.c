/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintfhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomez-m <ggomez-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:12:38 by ggomez-m          #+#    #+#             */
/*   Updated: 2023/12/05 14:12:48 by ggomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft/libft.h"

static int	switchbase(char *nuevabase, unsigned long long int numero)
{
	int						resultado[60];
	int						digitos;
	unsigned long long int	copia;
	int						tam;

	digitos = ft_strlen(nuevabase);
	copia = numero;
	tam = 0;
	while (copia > 0)
	{
		tam++;
		copia = copia / digitos;
	}
	resultado[tam] = '\0';
	while (numero > 0)
	{
		tam--;
		resultado[tam] = nuevabase[numero % digitos];
		numero = numero / digitos;
	}
	while (resultado[tam] != 0)
		write(1, &resultado[tam++], 1);
	return (tam);
}

/*static void	checknegadd(int *i)
{
	if (*i < 0)
	{
		*i = -*i;
		write(1, "-", 1);
	}
}*/

int	hexadecimamin(int i)
{
	int						extra;
	int						j;
	unsigned long long int	copia;
	char					*allhexadecimalsmin;

	j = 0;
	copia = i;
	allhexadecimalsmin = "0123456789abcdef";
	extra = switchbase(allhexadecimalsmin, i);
	return (extra - 2);
}

int	hexadecimamay(int i)
{
	int						extra;
	int						j;
	unsigned long long int	copia;
	char					*allhexadecimalsmin;

	j = 0;
	copia = i;
	allhexadecimalsmin = "0123456789ABCDEF";
	extra = switchbase(allhexadecimalsmin, i);
	return (extra - 2);
}

int	hxdclng(va_list *argumentos)
{
	int						extra;
	int						j;
	unsigned long long int	i;
	unsigned long long int	copia;
	char					*allhexadecimalsmin;

	i = (unsigned long long int)va_arg(*argumentos, void *);
	j = 0;
	copia = i;
	allhexadecimalsmin = "0123456789abcdef";
	write(1, "0x", 2);
	extra = switchbase(allhexadecimalsmin, i);
	return (extra);
}
