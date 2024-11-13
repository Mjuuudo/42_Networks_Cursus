/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:44:27 by abait-ou          #+#    #+#             */
/*   Updated: 2024/11/13 17:43:20 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    t_table table;
    
    if (argc == 5 || argc == 6)
    {
        // Validating and Parsing The Input
        ft_parsinput(&table, argv);
        // Seconde Step INIT The Struct Elements
        ft_inittable(&table);
        // Third Step Starting The Simulation
        ft_dinner(&table);
        // Mutexes Destroy
        ft_mutexdestroy(&table);
        
        
    }
    else
        printf("Error !\nPlease Use The Arguments In A Correct Way !\n");
    return (0);
}