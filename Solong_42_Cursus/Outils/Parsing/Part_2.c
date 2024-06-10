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