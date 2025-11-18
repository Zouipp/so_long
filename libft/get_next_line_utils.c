/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:54:15 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/17 13:34:43 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_extraction(char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		dest = malloc(sizeof(char) * (i + 2));
	else
		dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	if (!s[i])
		return (dest[i] = '\0', dest);
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char	*ft_strsuperjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	j = 0;
	i = -1;
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s2)
		return (s1);
	dest = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (free (s1), dest);
}

char	*new_beginning(char *s)
{
	char	*dest;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	while (s[i + j])
		j++;
	dest = malloc(sizeof(char) * (j + 1));
	if (!dest)
		return (NULL);
	if (s[i] == '\n')
		i++;
	else
		return (free (dest), NULL);
	j = 0;
	while (s[i])
		dest[j++] = s[i++];
	return (dest[j] = '\0', dest);
}

// int main(void)
// {
// 	printf("%s\n", ft_strjoin("", " ca va "));
// 	return (0);
// }