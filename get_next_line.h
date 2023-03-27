/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nicolaasvanstraten <nicolaasvanstraten@      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/16 13:00:45 by nicolaasvan   #+#    #+#                 */
/*   Updated: 2023/03/07 14:14:42 by nicolaasvan   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
// # include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

/*get_next_line_utils*/

/**frees input 'str'
returns NULL.*/
void	*ft_free(char *str);
/**computes the length of the string 'line'.*/
int		ft_strlen(const char *line);
/**Allocates (with malloc(3)) and returns a new
string, which is the result of the concatenation
of ’s1’ and ’s2’.*/
char	*ft_strjoin(char *s1, const char *s2);
/**allocates sufficient memory for a copy of the string s1,
does the copy, and returns a pointer to it.*/
char	*ft_strdup(const char *s1);
/**locates the first occurrence of c (converted to a char)
in the string pointed to by s.*/
char	*ft_strchr(const char *s, int c);

/*get_next_line main functions*/

/**reads from fd to buffer until \n or eof
concatenates 'saved_str' and 'buffer' until \n or eof
returns a pointer to the created string*/
char	*ft_read_line(int fd, char *saved_str);
/**trims the input 'str'
returns a pointer to a copy of 'str' until the newline if saved = 0
returns a pointer to a copy of 'str' from newline to \0 if saved = 1*/
char	*ft_modstr(char *str);
char    *ft_modline(char *str);

/**returns a line read from a file descriptor
returns NULL when there's nothing else to read,
or an error occured.*/
char	*get_next_line(int fd);

void	*ft_memcpy(void *dst, const void *src, size_t n);

#endif