/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:41:58 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 19:42:00 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	const char	*origin;

	origin = str;
	while (*str)
		str++;
	return ((size_t)(str - origin));
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	src_size = (size_t)ft_strlen(src);
	if (dstsize == 0)
		return (src_size);
	i = 0;
	while (src[i] && i + 1 < dstsize)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	*s;
	unsigned char	uc;

	s = (unsigned char *)str;
	uc = (unsigned char)c;
	while (1)
	{
		if (*s == uc)
			return ((char *)s);
		if (!*s)
			return (0);
		s++;
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}


char	*ft_strjoin_or_dup(char *prev, char *added)
{
	int		i;
	int		j;
	char	*str;

	if (prev == NULL)
		prev = "";
	str = malloc((ft_strlen((const char *)prev) + \
		ft_strlen((const char *)added) + 1) * sizeof(char));
	if (!str)
	{
		free(prev);
		return (NULL);
	}
	i = -1;
	j = 0;
	while (prev[++i] != '\0')
		str[i] = prev[i];
	while (added[j] != '\0')
		str[i++] = added[j++];
	str[i] = '\0';
	if (prev[0] != '\0')
		free(prev);
	return (str);
}
