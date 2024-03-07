/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:50:43 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:14:29 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	index;
	char			*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res || !s)
		return (NULL);
	index = 0;
	while (start < ft_strlen((char *)s) && s[start + index] && index < len)
	{
		res[index] = s[start + index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
