/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:27:41 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/28 12:46:31 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new_l;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		new_l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = new_l;
	}
	*lst = 0;
}
