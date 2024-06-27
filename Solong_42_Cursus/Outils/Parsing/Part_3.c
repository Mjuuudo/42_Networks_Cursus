/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 10:36:31 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/27 12:12:28 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int ft_checkrepetiton(t_container *container)
{
    if (ft_counter(container, 'P') != 1)
        return -1;
    if (ft_counter(container, 'C') < 1)
        return -2;
    if (ft_counter(container, 'E') != 1)
        return -3;
    
}
int  ft_counter(t_container *container, char target)
{
    int repetition;
    int compteur;
    int compteur_1;

    repetition = 0;
    compteur = 0;
    while (container->map_holder[compteur])
    {
        compteur_1 = 0;
        while (container->map_holder[compteur][compteur_1])
        {
            if (container->map_holder[compteur][compteur_1] == target)
                repetition++;
            compteur_1++;
        }
        compteur++;
    }
    return repetition;
}

void   ft_isitrectangle(t_container *container)
{
    int width;

    width = ft_strlen_x(container->map_holder[0]);
    if (container->game_height == width  || container->game_height > width)
    {
        ft_putstr("Map Must Be rectangular !\n");
        ft_freeerrors(container);
    }
    container->game_width =  width;
}