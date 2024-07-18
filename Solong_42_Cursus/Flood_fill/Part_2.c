/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:19:44 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 14:54:49 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_mapvalidation_2(t_container *container)
{
	int	counter;

	counter = 0;
	while (container->flood_fill[counter] != NULL)
	{
		if (ft_resolutionfloodfill(container->flood_fill[counter]))
			counter++;
		else
			return (0);
	}
	return (1);
}

void	flood_fillcopy(t_container *container, int compteur)
{
	int	length;
	int	counter;

	length = ft_strlen(container->map_holder[compteur]);
	container->flood_fill[compteur] = (char *)malloc(sizeof(char) * length);
	counter = 0;
	while (counter < length)
	{
		container->flood_fill[compteur][counter]
			= container->map_holder[compteur][counter];
		counter++;
	}
}

int	ft_resolutionfloodfill(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
	{
		if (s[counter] == 'F' || s[counter] == '1' || s[counter] == '0'
			|| s[counter] == '\n')
			counter++;
		else
			return (0);
	}
	return (1);
}
