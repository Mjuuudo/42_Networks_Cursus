/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:55:16 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/27 16:45:52 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include "Outils/gnl/get_next_line.h"

typedef struct s_container{
    void    *mlx_init;
    void    *mlx_window;
    int      window_height;
    int      window_width;
    void    *xpm_wall;
    void    *xpm_player;
    void    *xpm_coin;
    void    *xpm_exit;
    void    *xpm_floor;
    char    **map_holder;
    int     game_width;
    int     game_height;
    int     players;
    int     collectibeles;
    int     exits;
    int     player_pos_x;
    int     player_pos_y;
    char    **flood_fill;
    int     player_moves;
}              t_container;


// Outils For So long

int     ft_strlen_x(char *s);
void	ft_putstr(char *s);
int	    ft_strncmp(const char *str1, const char *str2, size_t n);

// Parsing functions

int      ft_mapnamecheck(char *name);
void     ft_mapheight(t_container *container, char   *path);
void     ft_mapcreation(t_container *container, char *map_name);
void     ft_mapvalidation(t_container *container);
int      ft_checkmaplength(t_container *container);
int      ft_checklinescontent(t_container *container);
int      resolution(t_container *container, char *string, int compteur);
void     ft_freeerrors(t_container *container);
int      ft_resolution2(char *string);
int      validity(char s);
int      ft_validatemapelement(char s);
int      ft_checkrepetiton(t_container *container);
int      ft_counter(t_container *container, char target);
void     ft_isitrectangle(t_container *container);

// Flood Fill Algorithm


void     flood_fill(t_container *container);
void     ft_duplicatemap(t_container *container);
void     ft_getplayerposition(t_container *container);
void     fill(t_container *container, int pos_x, int pos_y);

#endif