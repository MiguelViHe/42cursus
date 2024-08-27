/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 09:53:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/08/27 11:26:49 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#define READ_END	0
#define WRITE_END	1
#define FILE_NAME	"infile"

int main(void)
{
	int fdp[2];
	int fd;
	int	status;
	int	pid;

	pipe(fdp);
	ft_printf("soy %d, el padre\n", getpid());
	pid = fork();
	if (pid == 0) //hijo
	{
		ft_printf("soy %d y voy a morir\n", getpid());
		close(fdp[READ_END]);
		dup2(fdp[WRITE_END], STDOUT_FILENO);
		close(fdp[WRITE_END]);
		execlp("/bin/ls", "ls", "-l", "/home", NULL);
	}
	else if (pid > 0) //Padre
	{
		close(fdp[WRITE_END]);
		pid = fork();
		if (pid == 0)
		{
			ft_printf("soy %d y voy a morir\n", getpid());
			fd = open(FILE_NAME, O_WRONLY);
			dup2(fdp[READ_END], STDIN_FILENO);
			close(fdp[READ_END]);
			dup2(fd, STDOUT_FILENO);
			execlp("/usr/bin/wc", "wc", NULL);
			
		}
		else if (pid > 0)
		{
			close(fdp[READ_END]);
		}
		else //ERROR
			ft_printf("Error in fork\n");
	}
	else	//ERROR
		ft_printf("Error in fork\n");

	pid = wait(&status);
	ft_printf("PADRE PID = %d, hijo PID %d muerto, status = %d\n", getpid(), pid, WEXITSTATUS(status));
	pid = wait(&status);
	ft_printf("PADRE PID = %d, hijo PID %d muerto, status = %d\n", getpid(), pid, WEXITSTATUS(status));
	return (0);
}