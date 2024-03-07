/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:11:02 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:23:12 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!f || !lst || !del)
		return (NULL);
	node = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&node, new);
		lst = lst->next;
	}
	return (node);
}
/*void    del(void *content)
{
	free(content);
}

void	*f(void *content)
{
	((char *)content)[0] = ((char *)content)[0] + 1;
	printf("%s", (char *)content);
	return (content);
}

int	main(void)
{
	char st[] = "hi";
	t_list *s = ft_lstnew(st);
	ft_lstmap(s, f, del);
}*/
