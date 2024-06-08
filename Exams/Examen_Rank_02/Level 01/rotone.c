/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:20:51 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 18:27:15 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void rotone(char *string){
    int compteur;

    compteur = 0;
    while(string[compteur])
    {
        if ((string[compteur] >= 'a' && string[compteur] <= 'z') 
            || (string[compteur] >= 'A' && string[compteur] <= 'Z'))
        {
            if (string[compteur] == 'z')
                printf("a");
            else if (string[compteur] == 'Z')
                printf("A");
            else
                printf("%c", string[compteur] + 1);
        }
        else
            printf("%c", string[compteur]);
        compteur++;
    }
    printf("\n");
}
int main(int argc, char **argv)
{
    if (argc == 2)
        rotone(argv[1]);
    else
        printf("\n");
}