/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:47:19 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/22 21:13:35 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *saved;
    char *D_line;
    char *allocated;
    int readen;
    char *temp;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    saved = NULL;
    D_line = ft_strdup("");
    if (!D_line)
            return (NULL);
    if (saved != NULL)
        D_line = ft_strjoin(D_line, saved);
        if (!D_line)
            return (NULL);
    allocated = malloc((BUFFER_SIZE + 1));
    if (!allocated)
        return (NULL);
    readen = 0;
    while(!ft_strchr(allocated, '\n'))
    {
        readen = read(fd, allocated, BUFFER_SIZE);
        if (readen == 0) break;
        if (readen == -1) return (NULL);
        
        temp = ft_strjoin(D_line, allocated);
        free(D_line);
        D_line = temp;
    }
    cutter(&saved, &D_line);
    return (free(allocated),D_line);
}

int main(int argc, char *argv)
{
    char *name = "file.text";
    char *s;
    int fd = open(name, O_RDWR | O_CREAT, 0644);
    if(fd == -1)
    {
        dprintf(2,"the file %s failed and allocated -1\n", name);
        return 1;
    }
    int i = 0;
    while (i < 8)
    {
        s = get_next_line(fd);
        printf("[%d] : %s", i + 1, s);
        free(s);
        if (i == 7)
            printf("\n**********************\n");
        else
            printf("**********************\n");
        i++;
    }
}