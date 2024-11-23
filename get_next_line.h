/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:44:02 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/23 18:25:32 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
// ! fix the buffersize problem!
# define BUFFER_SIZE 22
#endif

# include <unistd.h>
# include <fcntl.h>
#include <stdint.h>
# include <stdio.h>
# include <string.h>
#include <string.h>
#include <stdlib.h>

char    *get_next_line(int fd);
void	*ft_calloc(size_t nitems, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str1);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int search_str);
int     cutter(char **saved, char **line);

#endif