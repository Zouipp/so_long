/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:00:34 by fbenech           #+#    #+#             */
/*   Updated: 2025/10/19 16:39:36 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif_charset(const char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	size;
	unsigned int	deb;
	char			*resultat;
	unsigned int	i;

	size = ft_strlen(s1);
	deb = 0;
	i = 0;
	while (verif_charset(s1[deb], set))
		deb++;
	while (size > deb && verif_charset(s1[size - 1], set))
		size--;
	resultat = malloc((size - deb + 1) * sizeof(char));
	if (!resultat)
		return (NULL);
	while (i < size - deb)
	{
		resultat[i] = s1[deb + i];
		i++;
	}
	resultat[i] = '\0';
	return (resultat);
}
// int main(void)
// {
// 	printf("%s\n", ft_strtrim(" ===str====", "==="));
// 	return(0);
// }