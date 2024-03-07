/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:30:01 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/21 10:42:46 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			compteur;
	unsigned char	*s;

	s = (unsigned char *)str;
	compteur = 0;
	while (n > 0)
	{
		s[compteur] = (unsigned char)c;
		n--;
		compteur++;
	}
	return (s);
}
/*int main()
{
	int a;
	memset(&a, 255, 4);
	memset(&a, 250, 2);
	memset(&a, 199, 1);
	printf("%d",a);
}*/
