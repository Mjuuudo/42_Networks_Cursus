/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:54:30 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/21 11:33:23 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
/*int main()
{
	t_list *first,*last,*new1, *new2;
	int a = 10,b = 15;


	new1 = ft_lstnew(&b);
	new2 = ft_lstnew(&a);
	first = new1;
	new1->next = new2;

	last = ft_lstlast(first);

	printf("%d", *((int *)last->content));
	while (first)
	{
			printf("%d", *((int *)first->content));
			first = first->next;
	}
	return (0);



}*/
