/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:44:27 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/07 17:11:41 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_table table;
    pthread_t monitor;
    
    if (argc == 5 || argc == 6)
    {
        // Validating and Parsing The Input
        ft_parsinput(&table, argv);
        // Seconde Step INIT The Struct Elements
        ft_inittable(&table, &monitor);

        // printf ("%ld %ld %ld %ld %ld", table.number_of_philos, table.time_to_die, 
        // table.time_to_eat, table.time_to_sleep, table.meals_left);
    }
    else
        printf("Error !\nPlease Use The Arguments In A Correct Way !\n");
    return (0);
}