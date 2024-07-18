/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:22:53 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 11:44:18 by abait-ou         ###   ########.fr       */
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
    container->xpm_wall = mlx_xpm_file_to_image(container->mlx_init, "./Assets/wall.xpm",
                                         &container->img_width, &container->img_height);
	container->xpm_floor = mlx_xpm_file_to_image(container->mlx_init,
			"./Assets/floor_black.xpm", &container->img_width, &container->img_height);
	container->xpm_coin = mlx_xpm_file_to_image(container->mlx_init,
			"./Assets/coin.xpm", &container->img_width, &container->img_height);
	container->xpm_player = mlx_xpm_file_to_image(container->mlx_init,
			"./Assets/player.xpm", &container->img_width, &container->img_height);
	container->xpm_exit = mlx_xpm_file_to_image(container->mlx_init,
			"./Assets/exit.xpm", &container->img_width, &container->img_height);
	container->player_moves = 0;			
}

void ft_putimginpx(t_container *container, char *type, int w, int h)
{
    int word_size;

    word_size = ft_strlen(type);
    if (ft_strncmp(type, "floor", word_size) == 0)
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_floor, w * 60, h * 60);
	else if (ft_strncmp(type, "wall", word_size) == 0)
		mlx_put_image_to_window(container->mlx_init,
			container->mlx_window, container->xpm_wall, w * 60, h * 60);
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
		ft_try(container, container->map_holder[h], h);
        h++;
    }
    return (0);
}

void ft_try(t_container *container, char *s, int h)
{
	int w;

	w = 0;
	while (w <= container->game_width - 1)
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

int input_reaction(int keysym, t_container *container)
{
	if (keysym == 65307)
		ft_endgame(container);
	else if (keysym == 119)
		ft_moveforward(container);
	else if (keysym == 115)
		ft_movebackward(container);
	else if (keysym == 97)
		ft_moveright(container);
	else if (keysym == 100)
		ft_moveleft(container);
    return (0);
}