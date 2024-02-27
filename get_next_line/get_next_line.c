/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:13:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/27 19:43:01 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	is_eol(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

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

char *get_next_line(int fd)
{
	static char	*line;
	char		*buffer;
	int			readed;

	readed = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while(!is_eol(line) && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		buffer[readed] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free (buffer);
	return (line);
}

int main(void)
{
	int	fd;

	fd = open("prueba.txt", O_RDONLY, 0444);
	if (fd == -1)
		perror("Error opening the file");
	printf("Buffer leido es: %s\n", get_next_line(fd));
	printf("Buffer leido es: %s\n", get_next_line(fd));
	printf("Buffer leido es: %s\n", get_next_line(fd));
	return (0);
}