/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:47:12 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/07 17:15:16 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	compteur;

	compteur = ft_strlen(str);
	while (compteur >= 0)
	{
		if (str[compteur] == c)
			return ((char *)str + compteur);
		compteur--;
	}
	return (NULL);
}
