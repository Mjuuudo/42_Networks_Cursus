/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:33:56 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/19 22:02:43 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	count_words(char *s, char c)
// {
// 	int		count;
// 	int	inside_word;

// 	count = 0;
// 	while (*s)
// 	{
// 		inside_word = 0;
// 		while (*s == c)
// 			++s;
// 		while (*s != c && *s)
// 		{
// 			if (!inside_word)
// 			{
// 				++count;
// 				inside_word = 1;
// 			}
// 			++s;
// 		}
// 	}
// 	return (count);
// }

// static char	*get_next_word(char *s, char c)
// {
// 	static int	cursor = 0;
// 	char		*next_word;
// 	int			len;
// 	int			i;

// 	len = 0;
// 	i = 0;
// 	while (s[cursor] == c)
// 		++cursor;
// 	while ((s[cursor + len] != c) && s[cursor + len])
// 		++len;
// 	next_word = malloc((size_t)len * sizeof(char) + 1);
// 	if (!next_word)
// 		return (NULL);
// 	while ((s[cursor] != c) && s[cursor])
// 		next_word[i++] = s[cursor++];
// 	next_word[i] = '\0';
// 	return (next_word);
// }

// char **ft_split(char  *s, char c)
// {
// 	int		words_count;
// 	char	**result_array;
// 	int		i;

// 	i = 0;
// 	words_count = count_words(s, c);
// 	if (!words_count)
// 	{
// 		ft_putstr("Error\n");
// 		exit(1);
// 	}
// 	result_array = malloc(sizeof(char *) * (size_t)(words_count + 1));
// 	if (!result_array)
// 		return (NULL);
// 	while (words_count-- >= 0)
// 	{
// 		// if (i == 0)
// 		// {
// 		// 	result_array[i] = malloc(sizeof(char));
// 		// 	if (!result_array[i])
// 		// 		return (NULL);
// 		// 	result_array[i++][0] = '\0';
// 		// 	continue ;
// 		// }
// 		result_array[i++] = get_next_word(s, c);
// 	}
// 	result_array[i] = NULL;
// 	return (result_array);
// }

static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
