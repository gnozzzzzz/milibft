/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintftxts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomez-m <ggomez-m@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:13:29 by ggomez-m          #+#    #+#             */
/*   Updated: 2023/12/05 14:13:35 by ggomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "ftprintffuncs.h"
#include "libft/libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	recibeletra(va_list *argumentos)
{
	char	aponer;

	aponer = va_arg(*argumentos, int);
	write(1, &aponer, 1);
	return (-1);
}

/*int	recibepalabra(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}*/
int	recibepalabra(char *aponer)
{
	int		extra;

	if (aponer == NULL)
	{
		ft_putstr("(null)");
		return (4);
	}
	extra = ft_strlen(aponer);
	write(1, aponer, extra);
	return (extra - 2);
}

int	recibenumdec(va_list *argumentos)
{
	int		extra;
	char	*aponer;

	aponer = ft_itoa(va_arg(*argumentos, int));
	extra = ft_strlen(aponer);
	write (1, aponer, extra);
	free (aponer);
	return (extra - 2);
}

int	recibeunsigdec(va_list *argumentos)
{
	int		extra;
	int		exextra;
	int		num;
	char	*aponer;

	extra = 0;
	exextra = 0;
	num = va_arg(*argumentos, int);
	if (num < 0)
	{
		exextra += 1;
		num *= -1;
	}
	aponer = ft_itoa(num);
	extra += ft_strlen(aponer);
	write (1, aponer, extra);
	free (aponer);
	return (extra + exextra - 2);
}
