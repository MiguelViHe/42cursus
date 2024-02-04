/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:40:22 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/23 17:40:22 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <fcntl.h> // Necesario para las constantes O_* con ficheros.
#include "libft.h"

/*It writes the int n on the file descriptor fd*/
void	ft_putnbr_fd(int n, int fd)
{
	if (fd > 0)
	{
		if (n == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
			ft_putnbr_fd(n, fd);
		}
		else if (n >= 0 && n <= 9)
			ft_putchar_fd(n + '0', fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}

/*int	main(void)
{
	int	number;
	int	fd;

	number = -483648;
	fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putnbr_fd(number, fd);
	close(fd);
	return (0);
}*/
