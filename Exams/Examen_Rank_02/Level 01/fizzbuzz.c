/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:55:12 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 10:55:14 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void){
  int compteur;

  compteur = 1;
  while (compteur <= 100){
    if (compteur % 3 == 0 && compteur % 5 == 0)
        printf("fizzbuzz\n");
    else if (compteur % 5 == 0)
          printf("buzz\n");
    else if (compteur % 3 == 0)
        printf("fizz\n");
    else 
      printf("%d\n", compteur);
    compteur++;
  }
}