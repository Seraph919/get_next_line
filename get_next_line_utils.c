/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:27:30 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/20 21:29:05 by asoudani         ###   ########.fr       */
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
int newline(char **allocated, char **saved)
{
	int i = 0;
	int len = ft_strlen(*allocated);
	while((*allocated)[i])
	{
		if ((*allocated)[i] == '\n')
		{
		    *saved = ft_substr(*allocated,i + 1, len - i);
			*allocated = ft_substr(*allocated, 0, i);
			return (1);
		}			
		i++;
	}	
	return (0);
}


void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	int		i;

	if (size == 0 || nitems == 0)
		return (malloc(0));
	if (size != 0 && (nitems > SIZE_MAX / size))
		return (NULL);
	i = 0;
	ptr = (char *)malloc(nitems * size);
	if (!ptr)
		return (NULL);
	while (i < (nitems * size))
	{
		(*(char *)ptr++) = 0;
		i++;
	}
	return (ptr);
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*returned;
	size_t	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len == 0 || start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	returned = (char *)malloc(sizeof(char) * (len + 1));
	if (!returned)
		return (NULL);
	while (i < len)
	{
		returned[i] = s[start + i];
		i++;
	}
	returned[i] = '\0';
	return (returned);
}
char	*ft_strdup(const char *str1)
{
	int		i;
	char	*allocated;

	i = 0;
	allocated = malloc(sizeof(char) * ft_strlen(str1) + 1);
	if (!allocated)
		return (NULL);
	while (str1[i])
	{
		allocated[i] = str1[i];
		i++;
	}
	allocated[i] = '\0';
	return (allocated);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*returned;

	if (!s1)
		return (((char *)s2));
	if (!s2)
		return ((char *)s1);
	i = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	returned = malloc(sizeof(char) * len1 + len2 + 1);
	if (!returned)
		return (NULL);
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
