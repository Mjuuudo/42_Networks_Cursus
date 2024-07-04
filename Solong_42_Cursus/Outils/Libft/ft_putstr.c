/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:31:57 by abait-ou          #+#    #+#             */
/*   Updated: 2024/07/04 11:41:40 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../so_long.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	compteur;

	compteur = 0;
	if (!s)
		return ;
	while (s[compteur])
	{
		ft_putchar(s[compteur]);
		compteur++;
	}
}

char    *ft_strcpy(char *s1, char *s2)
  {
      int i;
 
      i = 0;
      while (s2[i])
      {
          s1[i] = s2[i]; // so this will make s1 = to whatever s2 is looping through the string
          i++;
      }
      s1[i] = s2[i];  // now that we are finsihing looping though s1[i] will equal s2[i]
      return (s1);
  }