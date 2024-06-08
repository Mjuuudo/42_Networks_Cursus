/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:56:39 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 10:57:03 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int return_index(char c)
{
  char s[] = "abcdefghijklmnopqrstuvwxyz";
  int compteur = 0;

  while (s[compteur] != '\0')
  {
    if (s[compteur++] == c)
      return compteur;    
  }
  return -1;
}

void  ft_print(char c)
{
  int index = return_index(c);
  while (index--)
    {
      printf("%c", c);
    }
}

