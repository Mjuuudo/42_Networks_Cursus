/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:00 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/06 17:26:40 by abait-ou         ###   ########.fr       */
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
    flood_fill(&container, argv[1]);
   
    flood_fill_check(&container);
    ft_gameinit(&container);
    ft_drawmap(&container);
    printf("%d\n", container.window_height);
    printf("%d\n", container.window_width);
    //  mlx_loop(container.mlx_init);
    ft_freeerrors(&container, 1);
    
    
    
    
  
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


/*
    Starting By Re test some cases  with freeeing the array of map holder : lines length, lines content, wrong map naming, is the map rectangle or not,
            does it contains at least the minimum element s requirement ;
    then moving to flood fill algorithme with full testing for the map : try creating map by using the first map creatopn function, 
            checking if the flood fill Algo is Applyed, check if all the map is colored ;
*/