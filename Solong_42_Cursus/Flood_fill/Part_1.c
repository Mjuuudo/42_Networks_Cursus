/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:43:16 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 11:43:38 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void flood_fill(t_container *container, char *map_name)
{
    
    ft_duplicatemap(container, map_name);
    ft_getplayerposition(container);
    fill(container, container->player_pos_x, container->player_pos_y);
}

void  ft_duplicatemap(t_container *container, char *map_name)
{
     int     fd;
    int     compteur;
    char    *line;

    container->flood_fill = (char **)malloc(sizeof(char *) * (container->game_height + 1));
    if (!container->flood_fill)
        return (free(container->flood_fill));
    fd = open(map_name, O_RDWR);
    if (fd < 0)
        return ;
    line = get_next_line(fd);
    
    if (!line)
        return (free(line));
    compteur = 0;
    while (line)
    {
        container->flood_fill[compteur++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
    }
    container->flood_fill[compteur] = NULL;
    free(line);
    get_next_line(-1000);
}

void ft_getplayerposition(t_container *container)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (container->map_holder[x])
    {
        y = 0;
        while (container->map_holder[x][y])
        {
            if (container->map_holder[x][y] == 'P')
            {
                container->player_pos_x = x;
                container->player_pos_y = y;
                return ;
            }
            y++;
        }
        x++;
    }
}

void fill(t_container *container, int pos_x, int pos_y)
{
    if (pos_x < 0 || pos_y >= container->game_width || pos_y < 0
            || pos_x >= container->game_height || container->flood_fill[pos_x][pos_y] == 'F')
            return ;
    if (container->flood_fill[pos_x][pos_y] != '1' )
    {
        container->flood_fill[pos_x][pos_y] = 'F';
        fill(container, pos_x, pos_y - 1);
        fill(container, pos_x, pos_y + 1);
        fill(container, pos_x - 1, pos_y);
        fill(container, pos_x + 1, pos_y);
    }
}

void flood_fill_check(t_container *container)
{
    // int compteur;

    if (!ft_mapvalidation_2(container))
    {
        ft_putstr("Attention the Map Is Not Playable! \n");
        // compteur = 0;
        // while (container->map_holder[compteur])
        // {
        //     free(container->map_holder[compteur++]);
        // }
        // free(container->map_holder);
        // compteur = 0;
        // while (container->flood_fill[compteur])
        // {
        //     free(container->flood_fill[compteur++]);
        // }
        // free(container->flood_fill);
        ft_freeerrors(container, 1);
    }
}

