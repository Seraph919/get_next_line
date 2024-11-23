/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:47:19 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/23 18:25:03 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *saved = NULL;
    char        *realloced;
    char        *returned_line;
    int         readen;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (saved)
        returned_line = ft_strdup(saved);
    if (!saved)
       returned_line = ft_strdup("");
    if (!returned_line)
    {
        return (NULL);
    }
    realloced = malloc(BUFFER_SIZE + 1);
    if (!realloced)
        return (NULL);
    while (!ft_strchr(returned_line, '\n'))
    {
        readen = read(fd, realloced, BUFFER_SIZE);
        if (readen == 0)
        {
            break;
        }
        if (readen == -1)
            return(free(returned_line), free(realloced), NULL);
        realloced[readen] = '\0';
        char *temp = returned_line;
        returned_line = ft_strjoin(returned_line, realloced);
        free(temp);
    }
    free(realloced);
    if (cutter(&saved, &returned_line) == 0)
        return (NULL);
    return (returned_line);
}

// int main()
// {
//     int i = 1;
//     int fd = open("files.txt", O_RDONLY | O_CREAT, 0644);
//     if (fd == -1)
//         return (0);
//     char *s = get_next_line(fd);
//     printf("[%d] : %s", i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
//     s = get_next_line(fd);
//     printf("[%d] : %s", ++i, s);
//     free(s);
// }