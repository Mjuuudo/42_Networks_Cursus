/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:43:16 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/27 18:11:10 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void flood_fill(t_container *container)
{
    
    ft_duplicatemap(container);
    ft_getplayerposition(container);
    fill(container, container->player_pos_x, container->player_pos_y);
}

void  ft_duplicatemap(t_container *container)
{
    int compteur;
    
    container->flood_fill = malloc(sizeof(char *) * container->game_height);
    if (!container->flood_fill)
        return ;
    
    compteur = 0;
    while (container->map_holder[compteur])
    {
        container->flood_fill[compteur] = malloc(sizeof(char) * ft_strlen(container->map_holder[compteur]));
        if (!container->flood_fill)
            return ;
        container->flood_fill[compteur] = ft_strdup(container->map_holder[compteur]);
        compteur++;
    }
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