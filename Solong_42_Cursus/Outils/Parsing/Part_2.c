/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:26:37 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/10 19:04:35 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_freeerrors(t_container *container)
{
    int compteur;

    compteur = 0;
    while (container->map_holder[compteur])
    {
        free(container->map_holder[compteur++]);
    }
    free(container->map_holder);
}
// take a line and go tourgh of it and checks if it contains only the allowed charachters

int  ft_checklinescontent(t_container *container)
{
    int compteur;
    int compteur_1;

    compteur = 0;
    while (container->map_holder[compteur])
    {
        compteur_1 = 0;
        while (container->map_holder[compteur][compteur_1] != '\n')
        {
            if (compteur == 0)
            {    if (container->map_holder[compteur][compteur_1] != '1')
                    return (-1);
            }
            else if (compteur == container->game_height)
            {
                if (container->map_holder[compteur][compteur_1] != '1')
                    return (-1);
            }
            compteur_1++;
        }
        compteur++;
    }
    return (1);
}