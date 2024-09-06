/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:48:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/06 17:22:03 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "pipex_bonus.h"

int	here_doc(t_px_args *args)
{
	int		fdp[2];
	char 	*buffer;
	
	ft_printf("HERE_DOC\n");
	if (pipe(fdp) == -1)
		exit(-1);
	while (1)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (!buffer)
		{
			perror("PIPEX - Error reading in STDIN");
			exit(-1);
		}
		if (ft_memcmp(buffer, args->argv[2], (ft_strlen(buffer) - 1)) == 0)
		{
			close(fdp[WRITE_END]);
			break;
		}
		if (write(fdp[WRITE_END], buffer, ft_strlen(buffer)) != (ssize_t)ft_strlen(buffer))
		{
			perror("PIPEX - Error writing to fd");
			exit(-1);
		}
		free(buffer);
	}
	return (fdp[READ_END]);
}
