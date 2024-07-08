/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:22:53 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/06 19:05:50 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void  ft_gameinit(t_container *container)
{
	container->window_height = container->game_height;
	container->window_width  = container->game_width;
    container->mlx_init = mlx_init();
    if (container->mlx_init == NULL)
        exit (1);
    container->mlx_window = mlx_new_window(container->mlx_init,
                                container->window_width * 60, container->window_height * 60, "So_long");
    if (container->mlx_window == NULL)
        exit (1);
	if (!container->mlx_init)
		printf("wrong\n");
    container->xpm_wall = mlx_xpm_file_to_image(container->mlx_init, "./textures/wall_mincraft.xpm",
	 											&container->window_width, &container->window_height);
	container->xpm_floor = mlx_xpm_file_to_image(container->mlx_init,
			"./textures/floor_black.xpm", &container->window_width, &container->window_height);
	container->xpm_coin = mlx_xpm_file_to_image(container->mlx_init,
			"./textures/coin_60.xpm", &container->window_width, &container->window_height);
	container->xpm_player = mlx_xpm_file_to_image(container->mlx_init,
			"./textures/player.xpm", &container->window_width, &container->window_height);
	container->xpm_exit = mlx_xpm_file_to_image(container->mlx_init,
			"./textures/exit.xpm", &container->window_width, &container->window_height);
	container->player_moves = 0;

	if (!container->xpm_wall)
		printf("true\n");
	// mlx_destroy_window(container->mlx_init, container->mlx_window);
	// mlx_destroy_display(container->mlx_init);
}

void ft_putimginpx(t_container *container, char *type, int w, int h)
{
    int word_size;

    word_size = ft_strlen(type);
	printf("%s\n", type);
    if (ft_strncmp(type, "floor", word_size) == 0)
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_floor, w * 60, h * 60);
	else if (ft_strncmp(type, "wall", word_size) == 0)
	{
		printf("im in\n");
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_wall, w * 60, h * 60);
		printf("segfailt\n");
	}
	else if (ft_strncmp(type, "coin", word_size) == 0)
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_coin, w * 60, h * 60);
	else if (ft_strncmp(type, "player", word_size) == 0)
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_player, w * 60, h * 60);
	else if (ft_strncmp(type, "exit", word_size) == 0)
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_exit, w * 60, h * 60);
}

int ft_drawmap(t_container *container)
{
    int h;

    h = 0;
    while (container->map_holder[h] != NULL)
    {
        
        // while (container->map_holder[h][w] != '\0' || container->map_holder[h][w] != '\n')
        // {
        //     // if (container->map_holder[h][w] == '0')
		// 	// 	ft_putimginpx(container, "floor", w, h);
		// 	// else if (container->map_holder[h][w] == '1')
		// 	// 	ft_putimginpx(container, "wall", w, h);
		// 	// else if (container->map_holder[h][w] == 'C')
		// 	// 	ft_putimginpx(container, "coin", w, h);
		// 	// else if (container->map_holder[h][w] == 'P')
		// 	// 	ft_putimginpx(container, "player", w, h);
		// 	// else if (container->map_holder[h][w] == 'E')
		// 	// 	ft_putimginpx(container, "exit", w, h);
        //     w++;
        // }
		ft_try(container, container->map_holder[h], h);
        h++;
    }
    return (0);
}

void ft_try(t_container *container, char *s, int h)
{
	int w;

	w = 0;
	while (s[w] != '\0' || s[w] != '\n')
        {
            if (s[w] == '0')
				ft_putimginpx(container, "floor", w, h);
			else if (s[w] == '1')
				ft_putimginpx(container, "wall", w, h);
			else if (s[w] == 'C')
				ft_putimginpx(container, "coin", w, h);
			else if (s[w] == 'P')
				ft_putimginpx(container, "player", w, h);
			else if (s[w] == 'E')
				ft_putimginpx(container, "exit", w, h);
            w++;
        }
}

/*
	Actual problem Comes From The  put imgs Function soo it segfault checks the content of the elemts that is
	used there the type is correct soo im talking about the params of the function

*/