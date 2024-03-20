/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:13:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/18 18:13:26 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*rest_line(char *line)
{
	char	*new_line;
	int		i;
	int		j;
	int		aux;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (free(line), NULL);
	i++;
	aux = i;
	j = ft_strlen(line + i);
	new_line = malloc((j + 1) * sizeof(char));
	if (!new_line)
		return (free(line), NULL);
	j = 0;
	while (line[aux])
		new_line[j++] = line[aux++];
	new_line[j] = '\0';
	free (line);
	return (new_line);
}

char	*clean_line(char *line)
{
	int		i;
	char	*clean_line;

	i = 0;
	if (line && line[0] == '\0')
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i += 2;
	else
		i += 1;
	clean_line = malloc(i * sizeof(char));
	if (!clean_line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		clean_line[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		clean_line[i++] = '\n';
	clean_line[i] = '\0';
	return (clean_line);
}

char	*ft_put_together(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!result)
	{
		free (str1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (str1[j])
		result[i++] = str1[j++];
	j = 0;
	while (str2[j])
		result[i++] = str2[j++];
	result[i] = '\0';
	free (str1);
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	if (!s1 && s2)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	return (ft_put_together(s1, s2));
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			readed;
	char		*clned_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	readed = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!is_eol(line) && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), free(line), line = NULL, line);
		buffer[readed] = '\0';
		if (readed != 0)
			line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (free(buffer), line);
	}
	free (buffer);
	return (clned_line = clean_line(line), line = rest_line(line), clned_line);
}
