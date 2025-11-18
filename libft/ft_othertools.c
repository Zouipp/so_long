/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_othertools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:11:10 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/16 18:57:32 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbrhex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n >= 16)
	{
		count += ft_putnbrhex(n / 16, base);
	}
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_tolowerhex(unsigned int c)
{
	const char	*base;

	base = "0123456789abcdef";
	return (ft_putnbrhex((unsigned long)c, (char *)base));
}

int	ft_toupperhex(unsigned int c)
{
	const char	*base;

	base = "0123456789ABCDEF";
	return (ft_putnbrhex((unsigned long)c, (char *)base));
}

int	ft_putptrp2(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putptrp2(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptrp1(void *n)
{
	unsigned long	nb;
	int				count;

	count = 0;
	nb = (unsigned long)n;
	if (!n)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_putptrp2(nb);
	return (count);
}
