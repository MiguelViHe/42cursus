/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:13:02 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/04 13:25:34 by mvidal-h         ###   ########.fr       */
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

	printf("s1 = %s\n", (char *)s1);
	if (!s1 && s2) //5. YA NO VA A SER NULL. (TiENE CARACTERES ESPECIALES)
	{
		printf("Entro aqui\n");
		s1 = malloc(sizeof(char)); //6. POR LO QUE NO ENTRA AQUI A RESERVAR MEMORIA
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
		str[i++] = s1[j++]; //7. aSI QUE USA ESOS CARACTERES ESPECIALES COMO S1...
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free (s1); //8. PERO EL PUNTERO NO APUNTA REALMENTE A NINGUN SITIO PORQUE NO HEMOS HECHO MALLOC. REALMENTE SI QUE ESTA APUNTANDO A DONDE APUNTABA RESULT, TRATANDO DE LIBERARLO DE NUEVO.
	return (str); // 9. ANTES DE DEVOLVERLO HABRIA QUE DEJARLA INICIALIZADA CON EL RESTO.
}

char *get_next_line(int fd)
{
	static char	*line; //2. ESTE STATIC LINE, QUE YA NO VA A SER NULL - ABAJO
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
		line = ft_strjoin(line, buffer); //4. AL ENTRAR EN STRJOIN...
	}
	free (buffer);
	return (line); //3. AQUI LO DEVOLVIA DONDE SE TRANSFORMA EN RESULT ^^
}

int main(void)
{
	int		fd;
	char	*result;
	int		i;

	i = 3;
	fd = open("prueba.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	while (i)
	{
		result = get_next_line(fd);
		if (result == NULL)
			break;
		printf("Buffer leido es: %s\n", result);
		free (result); //1. CUANDO HAGO ESTE FREE ESTOY LIBERANDO ^
		i--;
	}
	close (fd);
	return (0);
}
