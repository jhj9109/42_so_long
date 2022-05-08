/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 19:41:00 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/05/06 19:41:02 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *buf)
{
	char	*ret;
	char	*p;

	ret = malloc(sizeof(char) * \
		(ft_strlen((const char *)buf) + 1));
	if (!ret)
		return (NULL);
	p = ret;
	while (*buf)
		*p++ = *buf++;
	*p = '\0';
	return (ret);
}

char	*ft_strjoin(char *prev, char *added)
{
	int		i;
	int		j;
	char	*str;

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
	free(prev);
	return (str);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	uc;

	ptr = (unsigned char *)b;
	uc = (unsigned char)c;
	while (len--)
		*ptr++ = uc;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ret;
	size_t	i;

	if (count == 0 || size == 0 || size > ((size_t)(-1)) / count)
		return (NULL);
	ret = malloc(count * size);
	if (!ret)
		return (NULL);
	i = 0;
	ft_memset(ret, 0, count * size);
	return (ret);
}
