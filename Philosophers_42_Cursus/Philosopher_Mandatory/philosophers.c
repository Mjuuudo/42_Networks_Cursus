/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:44:27 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/13 18:28:09 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		ft_parsinput(&table, argv);
		ft_inittable(&table);
		ft_dinner(&table);
		ft_mutexdestroy(&table);
	}
	else
		printf("Error !\nPlease Use The Arguments In A Correct Way !\n");
	return (0);
}
