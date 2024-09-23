/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:48:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/23 15:57:53 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "pipex_bonus.h"

static void	free_aux_buffers(char *buffer, char *bf_trim)
{
	free(buffer);
	free(bf_trim);
}

static void	error_here_doc(char *msg, char *buffer, char *bf_trim)
{
	perror(msg);
	free_aux_buffers(buffer, bf_trim);
	exit(-1);
}

static void	reset_next_round(char*buffer, char *bf_trim)
{
	free_aux_buffers(buffer, bf_trim);
	ft_printf(">");
}

static void	close_here_doc(int fdp[2], char	*buffer, char *bf_trim)
{
	free_aux_buffers(buffer, bf_trim);
	close(fdp[WRITE_END]);
}

//Read line to line from STDIN till the line is equal exit word (arg[2])
// It writes the result of every line in a pipe and return the read fd 
// of the pipe so that it can be used as a temporary file.
int	here_doc(t_px_args args)
{
	int		fdp[2];
	char	*bf;
	char	*bf_trim;

	if (pipe(fdp) == -1)
		exit(-1);
	ft_printf(">");
	while (1) // no saldremos de aqui hasta que se de el break
	{
		bf = get_next_line(STDIN_FILENO); //Leemos linea de STDIN
		if (!bf)
			continue ;
		bf_trim = ft_strtrim(bf, "\n"); // le eliminamos el salto de linea para poder compararlo bien con la frase de salida. Ya que esta no tiene el \n
		if (ft_strlen(bf_trim) == ft_strlen(args.argv[2])
			&& ft_memcmp(bf_trim, args.argv[2], (ft_strlen(args.argv[2]))) == 0) //si es la frase de salida..
		{
			close_here_doc(fdp, bf, bf_trim); //liberamos bufferes y cerramos el extremo de escritura de la pipe auxiliar.
			break ;
		}
		if (write(fdp[WRITE_END], bf, ft_strlen(bf)) != (ssize_t)ft_strlen(bf)) //escribimos la linea en el pipe
			error_here_doc("PIPEX - Error writing to fd", bf, bf_trim);
		reset_next_round(bf, bf_trim); //libera buffers y vuelve a escribir el >
	}
	return (fdp[READ_END]); // Cuando se sale del bucle se devuelve el fd de la parte de read del pipe auxiliar.
}
