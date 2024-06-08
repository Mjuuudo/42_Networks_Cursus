/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot13.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:57:34 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 11:18:31 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void rot13(char  *string){
    int difference;
    int compteur;

    compteur = 0;
    difference = 0;
    while (string[compteur])
    {
        if ((string[compteur] >= 'a' && string[compteur] <= 'z') 
                || ( string[compteur] >= 'A' && string[compteur] <= 'Z'))
        {
            if (string[compteur] < 'n' && string[compteur] >= 'a')
            {
                difference = string[compteur] - 'a';
                difference = 13 - difference - 1;
                printf("%c", 'z' - difference);
            }
            else if (string[compteur] <'N' && string[compteur] >= 'A')
            {
                difference = string[compteur] - 'A';
                difference = 13 - difference - 1;
                printf("%c", 'Z' - difference);
            }
            else
            {
                printf("%c", string[compteur] - 13);
            }
            
        }
        else{
            printf("%c", string[compteur]);
        }
        compteur++;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rot13(argv[1]);    
    else 
        printf("\n");
}