/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:06:30 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:13:58 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst && !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*void f(void *content)
{
	((char *)content)[0] = ((char *)content)[0] + 1;
	printf("%s", (char *)content);
}

int	main(void)
{
	char st[] = "hi";

	t_list *s = ft_lstnew(st);
	ft_lstiter(s, f);

	free(s);
	return (0);
}*/