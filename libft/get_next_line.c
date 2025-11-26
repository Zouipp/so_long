/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:54:05 by fbenech           #+#    #+#             */
/*   Updated: 2025/11/13 16:29:24 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	buffer_check(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	if ((s[i] == '\n' || !s[i]) && i < BUFFER_SIZE)
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*dest;
	ssize_t		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (free (buf), ft_get_out(&dest));
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		dest = ft_strsuperjoin(dest, buf);
		if (buffer_check(dest))
			return (free (buf), got_no_name(&dest));
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (!dest || dest[0] == '\0' || bytes_read < 0)
		return (free (buf), ft_get_out(&dest));
	return (free (buf), got_no_name(&dest));
}

char	*ft_get_out(char **dest)
{
	if (*dest)
		free(*dest);
	*dest = NULL;
	return (NULL);
}

char	*got_no_name(char **dest)
{
	char	*line;
	char	*tmp;

	line = ft_extraction(*dest);
	tmp = *dest;
	*dest = new_beginning(*dest);
	if (!dest)
		dest = NULL;
	return (free (tmp), line);
}
// int main(void)
// {
// 	int fd = open("only_nl.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free (line);
// 	}
// 	get_next_line(-1);
// 	close(fd);
// 	return (0);
// }