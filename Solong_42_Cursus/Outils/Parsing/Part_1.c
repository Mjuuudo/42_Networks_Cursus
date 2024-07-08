/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:12:31 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/06 16:09:47 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int  ft_mapnamecheck(char *name)
{
    int length;
 
    length = ft_strlen_x(name);
    if (length <= 4 || ft_strncmp(name + length - 4, ".ber", 4) != 0)
    {
        ft_putstr("The name You Entred Is In Wong Format Please Try Again !");
        exit (-1);
    }
    return (1);
}

void     ft_mapheight(t_container *container, char   *path)
{
    int fd;
    int length;
    char *line;

    length = 0;
    fd = open(path, O_RDWR);
    if (fd < 0)
    {
        ft_putstr("Wrong Map Path Please Check Your Input Field !\n");
        exit (-1);
    }
    line = get_next_line(fd);
    while (line)
    {
        free(line);
        length++;
        line = get_next_line(fd);
    }
    if (length == 0)
    {
        ft_putstr("Please Check Your Map Content Its Empty !\n");
        exit (-1);
    }
    container->game_height = length;
    free(line);
    get_next_line(-1000);
    close(fd);
}

void    ft_mapcreation(t_container *container, char *map_name)
{
    int     fd;
    int     compteur;
    char    *line;

    ft_mapheight(container, map_name);
    container->map_holder = (char **)malloc(sizeof(char *) * (container->game_height + 1));
    if (!container->map_holder)
        return (free(container->map_holder));
    fd = open(map_name, O_RDWR);
    if (fd < 0)
        return ;
    line = get_next_line(fd);
    
    if (!line)
        return (free(line));
    compteur = 0;
    while (line)
    {
        container->map_holder[compteur++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
    }
    container->map_holder[compteur] = NULL;
    free(line);
    get_next_line(-1000);
}

void  ft_mapvalidation(t_container *container)
{
    if ((ft_checkmaplength(container)) == 0)
    {
        ft_putstr("Size Of Map Is Invalid !\n");
        ft_freeerrors(container, 0);
    }
    if (ft_checklinescontent(container) == -1)
    {
        ft_putstr("Content Of Map Is Invalid !\n");
        ft_freeerrors(container, 0);  
    }
    if(ft_checkrepetiton(container) == -1)
    {
        ft_putstr("An Element have been repeaated !\n");
        ft_freeerrors(container, 0);
    }
    else if (ft_checkrepetiton(container) == -2)
    {
        ft_putstr("No Collectible In the Map !\n");
        ft_freeerrors(container, 0);
    }
    else if (ft_checkrepetiton(container) == -3)
    {
        ft_putstr("No Exits In the Map !\n");
        ft_freeerrors(container, 0);
    }
}
        


int ft_checkmaplength(t_container *container)
{
    int compteur;
    int length;

    length = ft_strlen_x(container->map_holder[0]);
    if (length > 1920)
        return (0);
    compteur = 1;
    while (container->map_holder[compteur])
    {
        if (ft_strlen_x(container->map_holder[compteur]) != length)
            return (0);
        compteur++;   
    }
    return (1);  
}