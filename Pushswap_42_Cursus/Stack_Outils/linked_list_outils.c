/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_outils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 20:34:18 by abait-ou          #+#    #+#             */
/*   Updated: 2024/04/06 20:40:37 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int ft_linkedlength(linked_list *head)
{
    int compteur;
    
    if (!head)
        return NULL; 
    compteur = 0;
    while (head->next)
    {
        compteur = 0;
        head = head->next;
    }
    return (compteur);
}

linked_list *ft_lastnode(linked_list *head)
{
    if (!head)
        return NULL; 
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

void ft_addnode(linked_list **head, int data)
{
   linked_list *node;
   linked_list *last_node;
   
   node = malloc(sizeof(linked_list));
   if (!node)
      return ;
    node->data = data;
    node->next = NULL;
   if (*(head) == NULL)
   {
     *head = node;
     node->prev = NULL;
   }
   else
   {
     last_node = ft_lastnode(*head);
     node->prev = last_node;
     last_node->next = node;
   }
}