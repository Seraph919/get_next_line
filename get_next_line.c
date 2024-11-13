/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:47:19 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/13 19:02:55 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char storage[1024];
    static char *p = storage;
    int bytesRead = read(fd, storage, 1024);
    while (*storage)
    {
        if (*p == '\n')
        {
            printf("\n");
            return ((char *)&p + 1);
        }
        printf("%c", *p);
        p++;
    }
    return ((char *)&p);
}



int main(int argc, char *argv)
{
    char *name = "file.text";
    int fd = open(name, O_RDWR | O_CREAT, 0644);
    if(fd == -1)
    {
        printf("the file %s failed and returned -1\n", name);
        return 1;
    }
    char    *storage = get_next_line(fd);
    storage = get_next_line(fd);
    return 0;
}