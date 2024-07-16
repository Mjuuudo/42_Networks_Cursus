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
    
    if (param < 2)
        return 0;
    while (compteur * compteur <= param)
    {
        if (param % compteur == 0)
            return 0;
        compteur++;
    }
    return (1);
}

int main()
{
    int i = 5;
    int res  = 0;
    
    while (i > 0)
    {
        if (add_prime_sum(i))
            res += i;
        i--;
    }
    printf("%d",res);
    return 0;
}