/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:55:33 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 10:55:51 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

static void ft_putchar(char c)
{
    int res;
    
    res = write(1, &c, 1);
}

void	ft_putstr(char *str){
  int  compteur = 0;
  
  
  while (str[compteur]){
   ft_putchar(str[compteur]);
    compteur++;
  }
}