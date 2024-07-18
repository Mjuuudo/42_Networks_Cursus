/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:58:00 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 12:18:07 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void ft_filescheck_2()
{
    int fd;

    fd = open("./Assets/player.xpm",  O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("One Of Xpm Files Is Missing\n");
        exit (1);
    }
    close(fd);  
    fd = open("./Assets/wall.xpm",  O_RDONLY);
    if (fd == -1)
    {
        ft_putstr("One Of Xpm Files Is Missing\n");
        exit (1);
    }
    close(fd);  
}

void ft_launchgame(t_container *container)
{
    container->img_width = 60;
    container->img_height = 60;
    ft_screensizecheck(container);
    ft_gameinit(container);
    ft_drawmap(container);
}

int main(int argc, char **argv)
{
    t_container  container;
    
    if (argc != 2)
    {
        ft_putstr("Please Check The Number Of Args That You Entred ( Must Be 2 )\n");
        exit(-1);
    }
    ft_mapnamecheck(argv[1]);
    ft_filescheck();
    ft_filescheck_2();
    ft_mapcreation(&container, argv[1]);
    ft_mapvalidation(&container);
    init_members(&container, 'C');
    init_members(&container, 'P');
    init_members(&container, 'E');
    ft_isitrectangle(&container);
    flood_fill(&container, argv[1]);
    flood_fill_check(&container);
    ft_launchgame(&container);
    mlx_key_hook(container.mlx_window,  input_reaction,  &container);
    mlx_hook(container.mlx_window, 17, 0, ft_endgame, &container);
    mlx_loop(container.mlx_init);
    ft_freeerrors(&container, 1);
    return (0);
    
}


/*
    Starting By Re test some cases  with freeeing the array of map holder : lines length, lines content, wrong map naming, is the map rectangle or not,
            does it contains at least the minimum element s requirement ;
    then moving to flood fill algorithme with full testing for the map : try creating map by using the first map creatopn function, 
            checking if the flood fill Algo is Applyed, check if all the map is colored ;
*/