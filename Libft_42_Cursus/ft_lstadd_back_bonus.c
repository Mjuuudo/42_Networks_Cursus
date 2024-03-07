/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:07:16 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:45 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->next = NULL;
	}
}

/*int main()
{
	t_list *first,*new1, *new2;
	int a = 10,b = 15;

	first = NULL;
	new1 = ft_lstnew(&b);
	new2 = ft_lstnew(&a);
	ft_lstadd_back(&first, new1);
	ft_lstadd_back(&first, new2);

	while (first)
	{
			printf("%d", *((int *)first->content));
			first = first->next;
	}
	return (0);



}*/
