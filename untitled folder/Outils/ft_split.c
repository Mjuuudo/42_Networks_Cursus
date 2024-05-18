/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 20:33:56 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/12 20:21:44 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int	count_words(char *s, char c) 
{
	int		count; 
	int	inside_word;

	count = 0;
	while (*s) 
	{
		inside_word = 0; 
		while (*s == c) 
			++s; 
		while (*s != c && *s)  
		{
			if (!inside_word) 
			{
				++count; 
				inside_word = 1; 
			}
			++s; 
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c) 
{
	static int	cursor = 0; 
	char		*next_word; 
	int			len; 
	int			i; 

	len = 0;
	i = 0;
	while (s[cursor] == c) 
		++cursor;
	while ((s[cursor + len] != c) && s[cursor + len]) 
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1); 
	if (!next_word) 
		return (NULL);
	while ((s[cursor] != c) && s[cursor]) 
		next_word[i++] = s[cursor++];
	next_word[i] = '\0'; 
	return (next_word);
}

char **ft_split(char *s, char c) 
{
	int		words_count; 
	char	**result_array; 
	int		i; 

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
	{
		ft_putstr("Error\n");
		exit(1);	
	}
	result_array = malloc(sizeof(char *) * (size_t)(words_count + 2)); 
	if (!result_array) 
		return (NULL);
	while (words_count-- >= 0) 
	{
		if (i == 0) 
		{
			result_array[i] = malloc(sizeof(char)); 
			if (!result_array[i]) 
				return (NULL);
			result_array[i++][0] = '\0'; 
			continue ;
		}
		result_array[i++] = get_next_word(s, c); 
	}
	result_array[i] = NULL;
	return (result_array);
}

// 370282062 1838634744 -60624457 -996848475 871765003 -978318389 1218398499 -255151366 -1526704564 169275511 -155692589 -424817347 345972060 -260444283 1879091647 -1344790525 -359389352 -853665525 -1250277793 870967810