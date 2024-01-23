/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:46:44 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/23 12:46:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h> // Necesario para la función write
//#include <fcntl.h>  // Necesario para las constantes O_* con ficheros.
#include "libft.h"

/*writes the stringr s on the file descriptor fd.*/
void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

/*void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}*/

/*int	main(void)
{
	int		fd;
	char	str[] = "Hola Mundo";

	fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putstr_fd(str, fd);
	close(fd);
	return (0);
}*/
