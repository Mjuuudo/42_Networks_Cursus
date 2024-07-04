/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:19:44 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/04 12:30:40 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_mapvalidation_2(t_container *container)
{
    int counter;
    int counter_1;

    counter = 0;
    
    while (container->flood_fill[counter] != NULL)
    {
        counter_1 = 0;
        while (container->flood_fill[counter][counter_1] != '\0')
        {
            if (container->flood_fill[counter][counter_1] == 'F' 
                    || container->flood_fill[counter][counter_1] == '1'
                        || container->flood_fill[counter][counter_1] == '0'
                            || container->flood_fill[counter][counter_1] == '\n')
                counter_1++;
            else
               return (0); 
        }
        counter++;
    }
    return (1);
}

void  flood_fillcopy(t_container *container, int compteur)
{
    int length;
    int counter;

    length = ft_strlen(container->map_holder[compteur]);
    container->flood_fill[compteur] = (char *)malloc(sizeof(char) * length);
    counter = 0;
    while (counter < length)
    {
        container->flood_fill[compteur][counter] = container->map_holder[compteur][counter];
        counter++;
    }
}