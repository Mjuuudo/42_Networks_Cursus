/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:33:33 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 11:17:43 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../so_long.h"

void ft_moveforward(t_container *container)
{
    if (container->map_holder[container->player_pos_x - 1][container->player_pos_y] == '1')
        return ;
    else if (container->map_holder[container->player_pos_x - 1][container->player_pos_y] == 'C')
        container->collectibeles--;
    else if (container->map_holder[container->player_pos_x - 1][container->player_pos_y] == 'E' 
                    &&  container->collectibeles == 0)
    {
           printf("You Won\n");
           container->player_moves += 1;
           ft_endgame(container);
    }
    else if (container->map_holder[container->player_pos_x - 1][container->player_pos_y] == 'E')
        return ;
    container->map_holder[container->player_pos_x - 1][container->player_pos_y] = 'P';
    container->map_holder[container->player_pos_x][container->player_pos_y]     = '0';
    container->player_pos_x -= 1;
    container->player_moves += 1;
    mlx_clear_window(container->mlx_init, container->mlx_window);
    ft_drawmap(container);
    printf("Player Moves : %d\n", container->player_moves);
    
}

void ft_movebackward(t_container *container)
{
    if (container->map_holder[container->player_pos_x + 1][container->player_pos_y] == '1')
        return ;
    else if (container->map_holder[container->player_pos_x + 1][container->player_pos_y] == 'C')
        container->collectibeles--;
    else if (container->map_holder[container->player_pos_x + 1][container->player_pos_y] == 'E' 
                    &&  container->collectibeles == 0)
    {
           printf("You Won\n");
           container->player_moves += 1;
           ft_endgame(container);
    }
    else if (container->map_holder[container->player_pos_x + 1][container->player_pos_y] == 'E')
        return ;
    container->map_holder[container->player_pos_x + 1][container->player_pos_y] = 'P';
    container->map_holder[container->player_pos_x][container->player_pos_y]     = '0';
    container->player_pos_x += 1;
    container->player_moves += 1;
    mlx_clear_window(container->mlx_init, container->mlx_window);
    ft_drawmap(container);
    printf("Player Moves : %d\n", container->player_moves);
}

void ft_moveright(t_container *container)
{
    if (container->map_holder[container->player_pos_x][container->player_pos_y - 1] == '1')
        return ;
    else if (container->map_holder[container->player_pos_x][container->player_pos_y - 1] == 'C')
        container->collectibeles--;
    else if (container->map_holder[container->player_pos_x][container->player_pos_y - 1] == 'E' 
                    &&  container->collectibeles == 0)
    {
            printf("You Won\n");
           container->player_moves += 1;
           ft_endgame(container);
    }
    else if (container->map_holder[container->player_pos_x][container->player_pos_y - 1] == 'E')
        return ;
    container->map_holder[container->player_pos_x][container->player_pos_y - 1] = 'P';
    container->map_holder[container->player_pos_x][container->player_pos_y]     = '0';
    container->player_pos_y -= 1;
    container->player_moves += 1;
    mlx_clear_window(container->mlx_init, container->mlx_window);
    ft_drawmap(container);
    printf("Player Moves : %d\n", container->player_moves);
}

void ft_moveleft(t_container *container)
{
    if (container->map_holder[container->player_pos_x][container->player_pos_y + 1] == '1')
        return ;
    else if (container->map_holder[container->player_pos_x][container->player_pos_y + 1] == 'C')
        container->collectibeles--;
    else if (container->map_holder[container->player_pos_x][container->player_pos_y + 1] == 'E' 
                    &&  container->collectibeles == 0)
    {
        printf("You Won\n");
           container->player_moves += 1;
           ft_endgame(container);
    }
    else if (container->map_holder[container->player_pos_x][container->player_pos_y + 1] == 'E')
        return ;
    container->map_holder[container->player_pos_x][container->player_pos_y + 1] = 'P';
    container->map_holder[container->player_pos_x][container->player_pos_y]     = '0';
    container->player_pos_y += 1;
    container->player_moves += 1;
    mlx_clear_window(container->mlx_init, container->mlx_window);
    ft_drawmap(container);
    printf("Player Moves : %d\n", container->player_moves);
}
int ft_endgame(t_container *container)
{
        mlx_destroy_image(container->mlx_init, container->xpm_wall);
		mlx_destroy_image(container->mlx_init, container->xpm_coin);
		mlx_destroy_image(container->mlx_init, container->xpm_exit);
		mlx_destroy_image(container->mlx_init, container->xpm_player);
		mlx_destroy_image(container->mlx_init, container->xpm_floor);
        mlx_destroy_window(container->mlx_init, container->mlx_window);
        mlx_destroy_display(container->mlx_init);
        free(container->mlx_init);
		ft_freeerrors(container, 1);
        exit(1);
        return (0);
}