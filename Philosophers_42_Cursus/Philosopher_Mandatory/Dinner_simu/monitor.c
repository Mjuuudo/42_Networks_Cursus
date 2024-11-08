/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:02:18 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/07 20:51:06 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void *ft_monitor(void *arg)
{
    t_table *table;
    int     counter;

    table = (t_table *)arg;
    while (!table->ready_or_not);
    ft_usleep(200);
    counter = 0;
    while (1)
    {
        while (counter < table->number_of_philos)
        {
            if ((get_time() - table->philos[counter].last_meal) > table->time_to_die)
            {
                pthread_mutex_lock(&table->print_mutex);
                table->flag_end_simulation = 1;
                printf("%d Died\n", counter + 1);
                pthread_mutex_unlock(&table->print_mutex);
            }
            counter++;
        }
        if (table->flag_end_simulation)
            break ;
        counter = 0;
    }
}