/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:59:40 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/28 12:42:35 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_string;
	size_t	compteur;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	compteur = 0;
	new_string = (char *)malloc(sizeof(char *) * (len_s1 + len_s2 + 1));
	if (!new_string)
		return (NULL);
	while (s1[compteur])
	{
		new_string[compteur] = s1[compteur];
		compteur++;
	}
	compteur = 0;
	while (s2[compteur])
		new_string[len_s1++] = s2[compteur++];
	new_string[len_s1] = '\0';
	return (new_string);
}
