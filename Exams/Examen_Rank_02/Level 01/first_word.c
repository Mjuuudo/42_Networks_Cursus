/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:54:39 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 10:54:52 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(int argc, char **argv) {

    int compteur = 0;
    
  if (argc == 2)
  {
    if (argv[1][0] == ' ' || argv[1][0] == '\t')
        compteur++;
    while (argv[1][compteur] != '\0' && (argv[1][compteur] != ' ' && argv[1][compteur] != '\t'))
    {
        printf("%c", argv[1][compteur]);
      compteur++;
    }
  }
  printf("\n");
  return 0;
}