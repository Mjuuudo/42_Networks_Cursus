/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:44:48 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 17:28:57 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*string;
	unsigned int	compteur;

	if (s && f)
	{
		string = (unsigned char *)malloc(sizeof(unsigned char) * (ft_strlen(s)
					+ 1));
		if (string)
		{
			compteur = 0;
			while (s[compteur])
			{
				string[compteur] = (*f)(compteur, s[compteur]);
				compteur++;
			}
			string[compteur] = '\0';
			return ((char *)string);
		}
	}
	return (NULL);
}
