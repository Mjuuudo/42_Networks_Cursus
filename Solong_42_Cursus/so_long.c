/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:00 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/27 18:11:06 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_container  container;
    
    if (argc != 2)
    {
        ft_putstr("Please Check The Number Of Args That You Entred ( Must Be 2 )\n");
        exit(-1);
    }
    ft_mapnamecheck(argv[1]);
    ft_mapcreation(&container, argv[1]);
    ft_mapvalidation(&container);
    ft_isitrectangle(&container);
    flood_fill(&container);
 
    
  
}

//   int i = 0;
//     while(container.map_holder[i])
//     {
//         printf("%s\n", container.map_holder[i++]);
//     }

    //  int i = 0;
    // while(container.flood_fill[i])
    // {
    //     printf("%s\n", container.flood_fill[i++]);
    // }