/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:52:12 by fbenech           #+#    #+#             */
/*   Updated: 2025/10/19 13:41:46 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	i;

	s = (char *)src;
	i = ft_strlen(src);
	if (i + 1 < size)
		ft_memcpy(dst, s, i + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, s, size - 1);
		dst[size - 1] = '\0';
	}
	return (i);
}
// int main(void)
// {
// 	char dst[] = "asd";
// 	const char src[] = "aasdasdsd";
// 	size_t size = 56;
// 	printf("%zu\n", ft_strlcpy(dst, src, size));
// 	printf("%zu\n", strlcpy(dst, src, size));
// 	return(0);
// }
