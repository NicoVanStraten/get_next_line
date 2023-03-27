/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicolaasvanstraten <nicolaasvanstraten@      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 12:56:55 by nicolaasvan   #+#    #+#                 */
/*   Updated: 2023/03/07 14:15:08 by nicolaasvan   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*ptr;
	size_t	s1len;
	size_t	s2len;

	if (s1 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc (s1len + s2len + 1);
	if (!ptr)
		return (ft_free(s1));
	ft_memcpy(ptr, s1, s1len);
    ft_memcpy(&ptr[s1len], s2, s2len);
	ptr[s1len + s2len] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_read_line(int fd, char *saved_str)
{
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	bytes_read = 1;
	if (!saved_str)
		saved_str = ft_strdup("");
	if (!saved_str)
		return (NULL);
	buffer[0] = '\0';
	while (bytes_read && !ft_strchr(saved_str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (ft_free(saved_str));
		buffer[bytes_read] = '\0';
		saved_str = ft_strjoin(saved_str, buffer);
		if (!saved_str)
			return (NULL);
	}
	if (saved_str[0] == '\0')
		return (ft_free(saved_str));
	return (saved_str);
}

char *ft_modline(char *str)
{
	int		index;
	char	*trimmed_str;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index])
	{
		if (str[index] == '\n')
		{
			str[index + 1] = '\0';
			trimmed_str = ft_strdup(str);
			free (str);
			return (trimmed_str);
		}
		index++;
	}
	return (str);
}

char	*ft_modstr(char *str)
{
	int		index;
	char	*trimmed_str;

	index = 0;
	if (!str)
		return (NULL);
	while (str[index])
	{
		if (str[index] == '\n')
		{
			trimmed_str = ft_strdup(&str[index] + 1);
			free (str);
			return (trimmed_str);
		}
		index++;
	}
	return (ft_free(str));
}

char	*get_next_line(int fd)
{
	static char	*saved_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str = ft_read_line(fd, saved_str);
	if (!saved_str)
		return (NULL);
	line = ft_strdup(saved_str);
	saved_str = ft_modstr(saved_str);
	line = ft_modline(line);
	if (!line)
	{
		free(saved_str);
		saved_str = NULL;
		return (NULL);
	}
	return (line);
}