/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:55:16 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/18 12:17:58 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include <unistd.h>
#include "Outils/gnl/get_next_line.h"
#include <X11/keysym.h>

typedef struct s_container{
    void    *mlx_init;
    void    *mlx_window;
    int      window_height;
    int      window_width;
    int      img_width;
    int      img_height;
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
char    *ft_strcpy(char *s1, char *s2);
// char	*ft_strdup(char *src);


// Parsing functions

int      ft_mapnamecheck(char *name);
void     ft_mapheight(t_container *container, char   *path);
void     ft_mapcreation(t_container *container, char *map_name);
void     ft_mapvalidation(t_container *container);
int      ft_checkmaplength(t_container *container);
int      ft_checklinescontent(t_container *container);
int      resolution(t_container *container, char *string, int compteur);
void     ft_freeerrors(t_container *container, int flag);
int      ft_resolution2(char *string);
int      validity(char s);
int      ft_validatemapelement(char s);
int      ft_checkrepetiton(t_container *container);
int      ft_counter(t_container *container, char target);
void     ft_isitrectangle(t_container *container);
void     ft_handlegnlerrors(t_container *container, char *line, int flag);
void     init_members(t_container *container, char c);
void     ft_filescheck();
void ft_normv1(int length);
void ft_screensizecheck(t_container *container);


// Flood Fill Algorithm


void     flood_fill(t_container *container, char *map_name);
void     ft_duplicatemap(t_container *container, char *map_name);
void     ft_getplayerposition(t_container *container);
void     fill(t_container *container, int pos_x, int pos_y);
int      ft_mapvalidation_2(t_container *container);
void     flood_fill_check(t_container *container);
void     flood_fillcopy(t_container *container, int compteur);
int      ft_resolutionfloodfill(char *s);

// Game Starting Function

void     ft_gameinit(t_container *container);
void     ft_putimginpx(t_container *container, char *type, int w, int h);
int      ft_drawmap(t_container *container);
void     ft_try(t_container *container, char *s, int h);

// Game Event handling Functions

int      input_reaction(int keysym, t_container *container);
void     ft_moveforward(t_container *container);
void     ft_movebackward(t_container *container);
void     ft_moveright(t_container *container);
void     ft_moveleft(t_container *container);
int     ft_endgame(t_container *container);





#endif