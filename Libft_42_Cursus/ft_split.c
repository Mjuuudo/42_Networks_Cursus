/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 09:56:56 by abait-ou          #+#    #+#             */
/*   Updated: 2023/11/27 14:24:36 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	is_word;

	count = 0;
	is_word = 0;
	if (!s)
		return (count);
	while (*s)
	{
		if (*s == c)
			is_word = 0;
		else
		{
			if (!is_word)
			{
				is_word = 1;
				count++;
			}
		}
		s++;
	}
	return (count);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	result = (char *)malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	if (result)
	{
		while (i < n)
		{
			result[i] = s[i];
			i++;
		}
		result[n] = '\0';
	}
	return (result);
}

static void	*free_memory(char **str_array, int *i)
{
	if (!str_array[(*i) - 1])
	{
		while (*i > 0)
			free(str_array[--(*i)]);
		free(str_array);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		string_count;
	int		i;
	char	**str_array;
	char	*start;

	string_count = count_words(s, c);
	str_array = (char **)malloc((string_count + 1) * sizeof(char *));
	if (!str_array || !s)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = (char *)s;
			while (*s && *s != c)
				s++;
			str_array[i++] = ft_strndup(start, s - start);
			free_memory(str_array, &i);
		}
		else
			s++;
	}
	str_array[i] = NULL;
	return (str_array);
}
