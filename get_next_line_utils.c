/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:27:30 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/23 18:21:04 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)search_str)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char)search_str == '\0')
		return (&((char *)str)[i]);
	return (NULL);
}

int cutter(char **saved, char **line)
{
	char *pointer_to_start;
	if (!*line)
		return (0);
	if ((pointer_to_start = ft_strchr(*line, '\n')))
	{
		free(*saved);
		*saved = ft_strdup(pointer_to_start + 1);
		if (!(*saved))
			return (0);
		*(pointer_to_start + 1) = '\0';
		return (1); 
	}
	free(*saved);
	*saved = NULL;
	return (1);
}
char	*ft_strdup(const char *str1)
{
	int		i;
	char	*returned;

	i = 0;
	returned = malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (!returned)
		return (NULL);
	while (str1[i])
	{
		returned[i] = str1[i];
		i++;
	}
	returned[i] = '\0';
	return (returned);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*returned;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	returned = malloc(sizeof(char) * len1 + len2 + 1);
	if (!returned)
	{
		return (NULL);
	}
	while (s1[++i])
		returned[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		returned[len1 + i] = s2[i];
		i++;
	}
	returned[len1 + i] = '\0';
	return (returned);
}
