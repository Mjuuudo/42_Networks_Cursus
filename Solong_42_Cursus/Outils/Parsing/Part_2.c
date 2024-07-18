/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:26:37 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 16:32:26 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_freeerrors(t_container *container, int flag)
{
	int	compteur;

	compteur = 0;
	while (container->map_holder[compteur])
	{
		if (container->map_holder[compteur])
			free(container->map_holder[compteur]);
		compteur++;
	}
	free(container->map_holder);
	if (flag)
	{
		compteur = 0;
		while (container->flood_fill[compteur])
		{
			free(container->flood_fill[compteur++]);
		}
		free(container->flood_fill);
	}
	exit(1);
}

int	ft_checklinescontent(t_container *container)
{
	int	compteur;

	compteur = 0;
	while (container->map_holder[compteur])
	{
		if (r(container, container->map_holder[compteur], compteur) == -1)
			return (-1);
		compteur++;
	}
	return (1);
}

int	r(t_container *container, char *string, int compteur)
{
	int	compteur_1;

	compteur_1 = 0;
	if (compteur == 0)
	{
		while (string[compteur_1] && string[compteur_1] != '\n')
		{
			if (string[compteur_1++] != '1')
				return (-1);
		}
	}
	else if (compteur == container->game_height - 1)
	{
		while (string[compteur_1] && string[compteur_1] != '\n')
		{
			if (string[compteur_1++] != '1')
				return (-1);
		}
	}
	else if (compteur > 0 && compteur < container->game_height - 1)
	{
		if (ft_resolution2(string) == -1)
			return (-1);
	}
	return (1);
}

int	ft_resolution2(char *string)
{
	int	compteur;

	compteur = 0;
	while (string[compteur] && string[compteur] != '\n')
	{
		if (compteur == 0)
		{
			if (string[compteur] != '1')
				return (-1);
		}
		else if (string[ft_strlen_x(string) - 1] != '1')
			return (-1);
		else if (compteur > 0 && compteur < ft_strlen_x(string) - 1)
		{
			if (ft_validatemapelement(string[compteur]) == 0)
				return (-1);
		}
		compteur++;
	}
	return (1);
}

int	ft_validatemapelement(char s)
{
	char	chars[5];
	int		compteur;

	chars[0] = '1';
	chars[1] = 'C';
	chars[2] = 'P';
	chars[3] = 'E';
	chars[4] = '0';
	compteur = 0;
	while (chars[compteur])
	{
		if (s == chars[compteur])
			return (1);
		compteur++;
	}
	return (0);
}
