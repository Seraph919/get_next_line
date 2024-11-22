/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:44:02 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/22 21:14:03 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
// ! fix the buffersize problem!
# define BUFFER_SIZE 1
#endif

# include <unistd.h>
# include <fcntl.h>
#include <stdint.h>
# include <stdio.h>
# include <string.h>
#include <string.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *str1);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int search_str);
int cutter(char **saved, char **line);

#endif