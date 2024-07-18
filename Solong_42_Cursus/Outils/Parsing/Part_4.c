/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:12:55 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 12:20:07 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void ft_normv1(int length)
{
    if(length == 0)
    {
        ft_putstr("Please Check Your Map Content Its Empty !\n");
        exit (1);
    } 
}
void ft_screensizecheck(t_container *container)
{
    if (container->game_width * 60 > 1920)
    {
        ft_putstr("Size Of Width of Map is Over 1920 px\n");
        ft_freeerrors(container, 1);
        exit (0);
    }
    if (container->game_height * 60 > 1080)
    {
        ft_putstr("Size Of Height of Map is Over 1080 px\n");
        ft_freeerrors(container, 1);
        exit (0);
    }
}