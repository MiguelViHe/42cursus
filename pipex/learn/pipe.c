/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 08:35:11 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/27 09:34:05 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(void){
	int     fd[2];
	pid_t   pidC;
	char	buffer[15];
	int 	rbytes;

	pipe(fd);
	pidC = fork();
	if (pidC > 0)
	{
		close(fd[1]); //escritura
		rbytes = read(fd[0], buffer, sizeof(buffer));
		close(fd[0]);
		ft_printf("mensaje de Hijo recibido: %s, rbytes = %d\n", buffer, rbytes);
	}
	else if (pidC == 0)
	{
		close(fd[0]); //lectura
		write(fd[1], "Hola Padre", 11);
		close(fd[1]);
		exit(0);
	}
	else
		ft_printf("Error in fork\n");
}