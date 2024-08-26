/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 12:55:15 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/26 17:05:37 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char *argv[])
{
	pid_t   pidC;
	int		status;

	if (argc == 5)
	{
		(void)argv[1];
		ft_printf("** Proceso PID %d comienza **\n", getpid());
		pidC = fork();
		if (pidC == 0)
		{
			sleep(5);
			ft_printf("%s : %i \n", argv[0], getpid());
			argv[0] = "./proceso";
			execv("./proceso", argv);
		}
		else if (pidC > 0)
		{
			pidC = wait(&status);
			ft_printf("PADRE PID = %d, hijo PID %d terminado, status = %d\n", getpid(), pidC, WEXITSTATUS(status));
		}
		else
			ft_printf("ERROR\n");
	}
	else
		ft_fdprintf(2, "Bad num args. Try './pipex infile cmd1 cmd2 outfile'");
	return (0);
}
