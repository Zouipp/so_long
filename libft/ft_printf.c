/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:41:23 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/16 18:57:12 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	checkform(va_list args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putptrp1(va_arg(args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbrdec(va_arg(args, unsigned int)));
	if (c == 'x')
		return (ft_tolowerhex(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_toupperhex(va_arg(args, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *form, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	i = 0;
	if (!form)
		return (0);
	va_start (args, form);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			i++;
			count += checkform(args, form[i]);
		}
		else
			count += ft_putchar(form[i]);
		i++;
	}
	va_end(args);
	return (count);
}
// int main(void)
// {
// 	// void *ptr = &"p";
// 	ft_printf(NULL);
// 	// printf(" %%%%%%%% %%%% \n");
// 	return (0);
// }