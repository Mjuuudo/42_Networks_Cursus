/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:11:32 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/07 17:11:29 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void ft_validateinput(char *string)
{
    int counter;

    counter = 0;
    while (ft_isspace(string[counter]))
        counter++;
    if (string[counter] == '+')
        counter++;
    else if (string[counter] == '-')
        ft_caseexite01();
    if (!ft_isdigit(string[counter]))
        ft_caseexite01();
    while (ft_isdigit(string[counter]))
        counter++;
}
static void ft_rangecheck(t_table *table)
{
    if (table->number_of_philos >= INT_MAX 
           || table->number_of_philos <= INT_MIN)
        ft_caseexite01();
    if (table->time_to_die >= INT_MAX 
           || table->time_to_die <= INT_MIN)
        ft_caseexite01();  
    if (table->time_to_eat >= INT_MAX 
           || table->time_to_eat <= INT_MIN)
        ft_caseexite01();
    if (table->time_to_sleep >= INT_MAX 
           || table->time_to_sleep <= INT_MIN)
        ft_caseexite01();   
    if (table->meals_left >= INT_MAX 
           || table->meals_left <= INT_MIN)
        ft_caseexite01();         
}
static void ft_checktimestamps(t_table *table)
{
    if (table->time_to_die <=6000)
        ft_caseexite01(); 
    if (table->time_to_eat <=6000)
        ft_caseexite01();
    if (table->time_to_sleep <=6000)
        ft_caseexite01();
}

static void ft_lastmeal(t_table *table)
{
    int counter;

    counter = 0;
    while (counter < table->number_of_philos)
    {
        table->philos[counter].last_meal = get_time();
        counter++;
    }
}
void   ft_parsinput(t_table *table, char **argv)
{
    int counter;

    counter = 1;
    while (argv[counter])
        ft_validateinput(argv[counter++]);
    table->number_of_philos = ft_atol(argv[1]);
    table->time_to_die      = ft_atol(argv[2]) * 1e3;
    table->time_to_eat      = ft_atol(argv[3]) * 1e3;
    table->time_to_sleep    = ft_atol(argv[4]) * 1e3;
    if (argv[5])
        table->meals_left   = ft_atol(argv[5]) * 1e3;
    else
        table->meals_left   = -1;
    if (table->number_of_philos == 0 || table->number_of_philos > 200)
        ft_caseexite01();
    table->start_simulation = get_time();
    table->flag_end_simulation = 0;
    ft_rangecheck(table);
    ft_checktimestamps(table);
    ft_lastmeal(table);
    table->ready_or_not = 0;
}

