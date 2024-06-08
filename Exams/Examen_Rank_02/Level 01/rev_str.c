/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:57:16 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 10:57:18 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char **argv)
{
  if (argc == 1)
      printf("\n");
  else
  {
    int length = strlen(argv[1]);
    while (length--)
      {
        printf("%c",argv[1][length]);
      }
  }
}