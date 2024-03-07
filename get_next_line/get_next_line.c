/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:13:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/07 20:01:30 by mvidal-h         ###   ########.fr       */
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
		return (NULL);
	i++;
	aux = i;
	j = 0;
	while (line[i++])
		j++;
	new_line = malloc((j + 1) * sizeof(char));
	j = 0;
	while (line[aux])
		new_line[j++] = line[aux++];
	new_line[j] = '\0';
	free(line);
	return (new_line);
}

char	*clean_line(char *line)
{
	int		i;
	char	*clean_line;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i += 2;
	else
		i += 1;
	clean_line = malloc(i * sizeof(char));
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	printf("s1+s2 = %s+%s\n", (char *)s1, s2);
	if (!s1 && s2)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 && !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			readed;
	char		*cleaned_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > sysconf(_SC_OPEN_MAX))
		return (NULL);
	readed = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!is_eol(line) && readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	cleaned_line = clean_line(line);
	line = rest_line(line);
	printf("Rest = %s\n", line);
	return (cleaned_line);
}
