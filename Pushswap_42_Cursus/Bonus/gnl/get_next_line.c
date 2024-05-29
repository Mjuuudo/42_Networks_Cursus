/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ou <abait-ou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:26:42 by abait-ou          #+#    #+#             */
/*   Updated: 2024/05/29 18:49:35 by abait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_to_storage(char *cup, char *storage)
{
	char	*tempo;

	tempo = ft_strjoin(storage, cup);
	free(storage);
	return (tempo);
}

static char	*read_from_file(int fd, char *storage)
{
	char	*cup;
	int		bytes_readed;

	cup = ft_calloc((size_t)BUFFER_SIZE + 1, sizeof(char));
	if (!cup)
		return (free(storage), NULL);
	bytes_readed = 1;
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, cup, BUFFER_SIZE);
		if (bytes_readed <= 0)
			break ;
		cup[bytes_readed] = '\0';
		storage = join_to_storage(cup, storage);
		if (ft_strchr(cup, '\n'))
			break ;
	}
	free(cup);
	if (bytes_readed <= 0 && (!storage || ft_strlen(storage) == 0))
		return (free(storage), NULL);
	if (bytes_readed == -1)
		return (free(storage), NULL);
	return (storage);
}

static char	*exctract_line(char *storage)
{
	char	*line;
	int		compteur;

	compteur = 0;
	while (storage[compteur] && storage[compteur] != '\n')
		compteur++;
	line = ft_calloc(compteur + 2, sizeof(char));
	if (!line)
		return (NULL);
	compteur = 0;
	while (storage[compteur] && storage[compteur] != '\n')
	{
		line[compteur] = storage[compteur];
		compteur++;
	}
	if (storage[compteur] == '\n')
		line[compteur++] = '\n';
	line[compteur] = '\0';
	return (line);
}

static char	*get_the_rest(char *storage)
{
	char	*new_storage;
	int		compteur;

	compteur = 0;
	while (storage[compteur] && storage[compteur] != '\n')
		compteur++;
	if (!storage[compteur])
		return (free(storage), NULL);
	new_storage = ft_strdup(storage + compteur + 1);
	free(storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(storage), NULL);
	if (!storage)
		storage = ft_calloc(1, sizeof(char));
	if (!storage)
		return (NULL);
	if (!ft_strchr(storage, '\n'))
		storage = read_from_file(fd, storage);
	if (!storage)
		return (NULL);
	line = exctract_line(storage);
	storage = get_the_rest(storage);
	return (line);
}
