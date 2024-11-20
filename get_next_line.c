/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoudani <asoudani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:47:19 by asoudani          #+#    #+#             */
/*   Updated: 2024/11/20 21:30:32 by asoudani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void fireforce(void *s)
{
    free(s);
}

char    *get_next_line(int fd)
{
    if (fd < 0)
        return (NULL);
    int readen;
    size_t Buffersize = BUFFER_SIZE;
    char *returned = ft_calloc((Buffersize + 1), sizeof(char));
    if (!returned)
        return (NULL);
    printf("the char * created successfully! \n");
    static char *previous = NULL;
    char *allocat = NULL;
    ft_strjoin(allocat, previous);
    //! you have a problem with the infinit loop in the last process, i guess cause it doesnt find the \n in the end so it doesnt return 1
    // !!!!             ^^^^^^^^^^^^^^^^^^^^
    while(newline(&returned, &previous) == 0)
    {
        readen = read(fd, returned, BUFFER_SIZE);
        allocat = ft_strjoin(allocat, returned);
    }
    return (allocat);
}

int main(int argc, char *argv)
{
    char *name = "file.text";
    int fd = open(name, O_RDWR | O_CREAT, 0644);
    if(fd == -1)
    {
        dprintf(2,"the file %s failed and returned -1\n", name);
        return 1;
    }
    else
        printf("the %s file created successfully! \n", name);
    char    *storage = get_next_line(fd);
    printf("%s\n", storage);
    storage = get_next_line(fd);
    printf("%s", storage);
    storage = get_next_line(fd);
    printf("%s", storage);
    return 0;
}