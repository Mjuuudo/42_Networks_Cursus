/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:46:23 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/21 11:34:10 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	length;

	length = 0;
	while (lst != NULL)
	{
		length++;
		lst = lst->next;
	}
	return (length);
}
/*int main()
{
	t_list *first,*last,*new1, *new2,*new3;
	int a = 10,b = 15, size, c = 1;


	new1 = ft_lstnew(&b);
	new2 = ft_lstnew(&a);
	new3 = ft_lstnew(&c);
	first = new1;
	new1->next = new2;
	new2->next = new3;
	size = ft_lstsize(first);


	printf("%d", size);

	return (0);



}*/
