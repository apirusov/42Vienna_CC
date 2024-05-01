/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apirusov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:40:25 by apirusov          #+#    #+#             */
/*   Updated: 2024/04/30 17:40:29 by apirusov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdint.h>
# include <stdbool.h>

/*******************************GET NEXT LINE*********************************/
char	*get_next_line(int fd);

/*********************************UTILITIES***********************************/
char	*ft_strjoin(char **s1, char *s2);
char	*ft_calloc(size_t nmemb, size_t size);
int	    ft_strchr(const char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_newstr(char **str);
char	*ft_new(char **str);
void	*ft_allocate_read_check(ssize_t *nbyte, int *fd, \
								char **buf, char **line);
void ft_free(char **ptr);

#endif
