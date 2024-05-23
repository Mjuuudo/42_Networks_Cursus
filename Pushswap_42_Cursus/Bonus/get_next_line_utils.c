/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:53:14 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/22 14:53:42 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	compteur;

	compteur = 0;
	while (str[compteur])
	{
		compteur++;
	}
	return (compteur);
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	if (num == 0 || size == 0)
		return (NULL);
	total_size = num * size;
	if (total_size / num != size)
		return (NULL);
	ptr = (unsigned char *)malloc(total_size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return ((char *)str);
}

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

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
