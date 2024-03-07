/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:20:35 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:18:44 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len_str;
	char	*strcp;

	len_str = ft_strlen(str);
	strcp = (char *)malloc(len_str + 1);
	if (!strcp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		strcp[i] = str[i];
		i++;
	}
	strcp[i] = '\0';
	return (strcp);
}
