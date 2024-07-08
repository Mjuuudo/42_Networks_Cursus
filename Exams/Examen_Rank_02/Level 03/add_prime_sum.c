/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>              +#+  +:+       +#+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:44:56 by abait-ou            #+#    #+#            */
/*   Updated: 2024/06/09 12:44:56 by abait-ou           ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int add_prime_sum(int param){
    int compteur = 2;
    int result = 0;

    while (compteur <= param)
    {
        if (compteur % compteur == 0 && compteur % 1 == 0)
            result += compteur;
        compteur++;
    }
    return (result);
}