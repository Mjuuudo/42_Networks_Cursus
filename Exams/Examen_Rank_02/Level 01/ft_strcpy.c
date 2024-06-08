/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:56:04 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 10:56:14 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>


char    *ft_strcpy(char *s1, char *s2)
{
    int compteur = 0;

    while (s1[compteur])
      {
        s2[compteur] = s1[compteur];
        compteur++;
      }
    s2[compteur] = '\0';
  return s2;
}
