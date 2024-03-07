/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:23:03 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:14:45 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	substr_len;

	substr_len = ft_strlen(substr);
	if (substr == NULL || len == 0 || (substr_len == 0 && len > 0))
		return ((char *)str);
	i = 0;
	while (i < len && str[i] && (i + substr_len) <= len)
	{
		if (!ft_strncmp(&str[i], substr, substr_len))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
