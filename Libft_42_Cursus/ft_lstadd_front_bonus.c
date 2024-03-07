/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:16:00 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/24 09:58:43 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*int main()
{
	t_list *first,*new1, *new2;
	int a = 10,b = 15;

	first = NULL;
	new1 = ft_lstnew(&b);
	new2 = ft_lstnew(&a);
	ft_lstadd_front(&first, new1);
	ft_lstadd_front(&first, new2);

	while (first)
	{
			printf("%d", *((int *)first->content));
			first = first->next;
	}
	return (0);



}*/
