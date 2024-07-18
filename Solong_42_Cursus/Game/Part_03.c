/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_03.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:00:25 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 16:22:20 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	rebuild(t_container *container)
{
	ft_putstr("Player Moves :");
	ft_putnbr(container->players++);
	ft_putstr("\n");
	mlx_clear_window(container->mlx_init, container->mlx_window);
	ft_drawmap(container);
}
