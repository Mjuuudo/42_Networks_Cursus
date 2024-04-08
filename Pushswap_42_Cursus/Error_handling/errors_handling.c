/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:54:01 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/08 14:07:16 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int ft_checkrepetition(linked_list *head, int number)
{

    while (head)
    {
        if (head->data == number)
            return (1);
        head = head->next;
    }
    return (0);
}

void ft_freelinkedlist(linked_list **head)
{
    linked_list *temp;
    linked_list *current;

    if (head == NULL)
        return ;
    current = *head;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *head = NULL;
    
}

void  ft_freeheapargv(char **argv)
{
    int compteur;

    compteur = -1;
    if (argv == NULL || *argv == NULL)
        return ;
    while (argv[compteur])
    {
        free(argv[compteur]);
        compteur++;
    }
    free(argv - 1);
}

void ft_freeerrors(linked_list **head, char **argv, int flag_heapornot)
{
    ft_freelinkedlist(a);
    if (flag_heapornot)
        ft_freeheapargv(argv);
    ft_putstr("Error\n");
    exit(1);
}

int syntaxe_error(const char *string)
{
    int compteur;
    
    if (!string || ((string[0] == '-' || string[0] == '+')&& string[1] == '\0'))
        return (1);
    compteur = 0;
    if (string[compteur] == '-' || string[compteur] == '+')
        compteur++;   
    while (string[compteur])
    {
        if (string[compteur] >= 48 && string[compteur] <= 57)
            compteur++;
        else
            return (1);
    }
    return (0);
}