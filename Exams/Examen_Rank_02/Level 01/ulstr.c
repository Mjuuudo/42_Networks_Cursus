/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:41:23 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 18:51:57 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void ulstr(char *string)
{
 int compteur = 0;

 while (string[compteur])
 {
    if (string[compteur] >= 'a' && string[compteur] <= 'z')
        printf("%c", string[compteur] - 32);
    else if (string[compteur] >= 'A' && string[compteur] <= 'Z')
        printf("%c", string[compteur] + 32);
    else 
        printf("%c", string[compteur]);
    compteur++;
 }  
 printf ("\n"); 
}
int main(int argc, char **argv)
{
    if (argc == 2)
        ulstr(argv[1]);
    else
        printf("\n");
}