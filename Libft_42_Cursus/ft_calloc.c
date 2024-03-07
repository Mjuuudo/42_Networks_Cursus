/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:55:19 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/30 19:45:17 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	the_size;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(1);
		ft_bzero(ptr, 1);
		return (ptr);
	}
	the_size = nmemb * size;
	if (the_size / nmemb != size)
		return (NULL);
	ptr = malloc(the_size);
	if (ptr != NULL)
	{
		ft_bzero(ptr, the_size);
	}
	return (ptr);
}
/*int main()
{
	char *c = ft_calloc(0,0);
	printf("%d", c);
}*/
