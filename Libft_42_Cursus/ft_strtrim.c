/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:51:38 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/28 12:52:09 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;
	char	*ns;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1);
	while (s1[first] && ft_strchr(set, s1[first]))
	{
		first++;
	}
	while (last > first && ft_strchr(set, s1[last - 1]) && s1[last - 1])
	{
		last--;
	}
	ns = (char *)malloc(last - first + 1);
	if (ns != NULL)
	{
		ft_strlcpy(ns, &s1[first], last - first + 1);
		ns[last - first] = '\0';
	}
	return (ns);
}
