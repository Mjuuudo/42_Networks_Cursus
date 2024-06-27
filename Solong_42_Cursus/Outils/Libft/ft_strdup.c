/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:51:29 by abait-ou          #+#    #+#             */
/*   Updated: 2024/06/27 15:01:32 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

// char	*ft_strdup(char *src)
// {
// 	char	*new;
// 	int		i;
// 	int		size;

// 	size = 0;
// 	while (src[size])
// 		++size;
// 	if (!(new = malloc(sizeof(char) * (size + 1))))
// 		return (NULL);
// 	i = 0;
// 	while (src[i])
// 	{
// 		new[i] = src[i];
// 		i++;
// 	}
// 	new[i] = '\0';
// 	return (new);
// }