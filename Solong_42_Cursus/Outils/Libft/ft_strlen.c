/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:09:25 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/27 15:01:06 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int ft_strlen_x(char *s)
{
    int compteur;

    compteur = 0;
    while (s[compteur] && s[compteur] != '\n')
    {
        compteur++;
    }
    return (compteur);
}

// int ft_strlen(char *s)
// {
//     int compteur;

//     compteur = 0;
//     while (s[compteur])
//     {
//         compteur++;
//     }
//     return (compteur);
// }