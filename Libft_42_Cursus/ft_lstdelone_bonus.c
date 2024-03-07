/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:20:00 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/28 12:46:02 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*void    del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *list = NULL;
	char d[] = "zero";
	t_list *s = ft_lstnew(d);
	ft_lstdelone(s, del);
}*/
