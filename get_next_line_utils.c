/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicolaasvanstraten <nicolaasvanstraten@      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/07 10:59:49 by nicolaasvan   #+#    #+#                 */
/*   Updated: 2023/03/07 13:56:34 by nicolaasvan   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *str)
{
	free (str);
	return (NULL);
}

int	ft_strlen(const char *line)
{
	int	len;

	len = 0;
	while (line[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*source;
	unsigned char	*destination;

	i = 0;
	source = (unsigned char *) src;
	destination = (unsigned char *) dst;
	if (destination == source && n == 0)
		return (dst);
	if (source == 0 && destination == 0)
		return (0);
	if (n < 0)
		return (0);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}