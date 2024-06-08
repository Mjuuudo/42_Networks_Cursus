/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:30:26 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/08 18:39:17 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void search_and_replace(char *string, char source, char target)
{
    int compteur = 0;

    while(string[compteur])
    {
        if (string[compteur] == target)
                string[compteur] = source;
        printf("%c", string[compteur++]);
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    if (argc == 4 && !argv[2][1] && !argv[3][1])
        search_and_replace(argv[1], *argv[3], *argv[2]);
    else   
        printf("\n");
}