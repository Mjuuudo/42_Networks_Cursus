/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:57:58 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:27:49 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*#include <stdio.h>
int	main(void)
{
	t_list *new;

	int a = 15;
	new = ft_lstnew(&a);
	printf("%d \n", *((int *)new->content));
	return (0);
}*/