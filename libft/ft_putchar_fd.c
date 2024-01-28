/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 08:58:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/23 08:58:40 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h> // Necesario para la función write
//#include <fcntl.h>  // Necesario para las constantes O_* con ficheros.
#include "libft.h"

/*writes the character c on the file descriptor fd.*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int	main(void)
{
	int		fd;
	char	s;

	s = '&';
	fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putchar_fd(s, fd);
	close(fd);
	return (0);
}*/
