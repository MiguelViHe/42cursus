/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:02:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/23 16:04:18 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include "pipex_bonus.h"

void	middle_child(t_px_args *args, int fdp[2][2])
{
	char	**split_argv;
	char	*final_path;
	char	*curr_cmd;
	int		next_pipe;
	int		prev_pipe;

	curr_cmd = args->argv[args->num_cmd];
	prev_pipe = ((args->num_cmd) + 1) % 2;
	next_pipe = (args->num_cmd) % 2;
	close(fdp[next_pipe][READ_END]); //cerramos el read de la pipe que aun no esta usandose porque solo vamos a escribir en ella.
	if (!ft_strnstr(curr_cmd, "'", ft_strlen(curr_cmd))) // si no contiene ''
		split_argv = ft_split(curr_cmd, ' '); //split normal
	else
		split_argv = ft_split_squotes(curr_cmd, ' '); //split con ''
	final_path = find_cmd_in_path(args->split_path, split_argv[0]);
	free_path(args->split_path);
	dup2(fdp[prev_pipe][READ_END], STDIN_FILENO); // STDIN ahora es la lectura de la pipe anterior
	close(fdp[prev_pipe][READ_END]); // cerramos la lectura porque ya la tiene STDIN 
	dup2(fdp[next_pipe][WRITE_END], STDOUT_FILENO); // STDOUT ahora es la escritura de la pipe siguiente
	close(fdp[next_pipe][READ_END]); // cerramos la escritura porque ya la tiene STDOUT 
	exec_command(split_argv, args->env, final_path); //y finalmente ejecutamos.
}

void	last_child(t_px_args *args, int fdp[2])
{
	int		fd;
	char	**split_argv;
	char	*final_path;
	char	*last_cmd;

	last_cmd = args->argv[(args->argc) - 2];
	if (args->first_cmd == 3) // Si es here_doc
		fd = secure_open_bonus(args->argv[(args->argc) - 1], 2, args); //abro el fichedo destino en modo APPEND
	else
		fd = secure_open_bonus(args->argv[(args->argc) - 1], 1, args); //abro el fichedo de destino en modo TRUNC
	if (!ft_strnstr(last_cmd, "'", ft_strlen(last_cmd))) // si no contiene ''
		split_argv = ft_split(last_cmd, ' '); //uso sobre el ultimo comando split normal
	else
		split_argv = ft_split_squotes(last_cmd, ' '); //uso sobre el ultimo comando split con ''
	final_path = find_cmd_in_path(args->split_path, split_argv[0]); //generamos el comando con el path completo.
	free_path(args->split_path); //como ya tenemos el path completo liberamos el array
	dup2(fdp[READ_END], STDIN_FILENO); //la entrada estandar ahora es el pipe de entrada.
	close(fdp[READ_END]); //lo cerramos porque STDIN ya lo tiene.
	dup2(fd, STDOUT_FILENO); //la salida estandar ahora es el fichero de salida .
	close(fd); // lo cerramos porque STDOUT ya lo tiene.
	exec_command(split_argv, args->env, final_path); //y finalmente ejecutamos el comando.
}

void	first_child(t_px_args *args, int fdp[2], int fd_ph)
{
	int		fd;
	char	**split_argv;
	char	*final_path;
	char	*str_first_cmd;

	str_first_cmd = args->argv[args->first_cmd];
	close(fdp[READ_END]); // cierro read porque yo solo voy a escribir.
	if (args->first_cmd == 2) // si no es here_doc
		fd = secure_open_bonus(args->argv[1], 0, args); //abro archivo de argv[1]
	else if (args->first_cmd == 3) // si es here_doc
		fd = fd_ph; //no abro nada, simplemente uso la parte de read del pipe generado en here_doc, que haria de archivo auxiliar.
	if (!ft_strnstr(str_first_cmd, "'", ft_strlen(str_first_cmd))) // si el primer comando NO tiene ''
		split_argv = ft_split(str_first_cmd, ' '); // uso el split normal
	else // si SI
		split_argv = ft_split_squotes(str_first_cmd, ' '); //uso el split con ''
	final_path = find_cmd_in_path(args->split_path, split_argv[0]); //generamos el comando con el path completo.
	free_path(args->split_path); //como ya tenemos el path completo liberamos el array
	dup2(fd, STDIN_FILENO); //la entrada estandar ahora es here:doc o el fichero de entrada.
	close(fd); //lo cerramos porque STDIN ya tiene el fd que necesitamos asi que ya podemos dejar cerrado el nuestro.
	dup2(fdp[WRITE_END], STDOUT_FILENO); //en la salida estandar le decimos que escriba en la parte write del pipe pasado.
	close(fdp[WRITE_END]); //cerramos por lo mismo que el en de entrada
	exec_command(split_argv, args->env, final_path); //Y finalmente ejecutamos.
}

void	childs_management(t_px_args *args, int fdp[2][2], pid_t pid, int fd_ph)
{
	if (pid == -1)
		exit(-1);
	else if (pid == 0) //el proceso hijo
	{
		if (args->num_cmd == args->first_cmd)
			first_child(args, fdp[(args->num_cmd) % 2], fd_ph); //fd_ph solo si es el primero.
		else if (args->num_cmd == args->argc - 2)
			last_child(args, fdp[((args->num_cmd) + 1) % 2]); // +1 es el anterior (izq)
		else
			middle_child(args, fdp); // al ser intermedio le paso los dos (fdp completo.)
	}
	else if (pid > 0) //el proceso padre
	{ //Aqui siempre actuamos sobre el ya creado y usado. Ya sabemos lo que va a hacer el siguiente con él.
		if (args->num_cmd == args->first_cmd) //si es el primer comando cerramos la escritura
			close(fdp[(args->num_cmd) % 2][WRITE_END]); //porque el siguiente hijo de esta pipe solo le queda leer.
		else if (args->num_cmd == args->argc - 2) //si es el ultimo comando cerramos la lectura
			close(fdp[((args->num_cmd) + 1) % 2][READ_END]); // porque ya no vendrá ningun hijo más y asi queda cerrado todo tambien en el padre.
		else //Si es intermedia
		{
			close(fdp[(args->num_cmd) % 2][WRITE_END]); //cerramos la escritura porque el hijo que va a escribir ya la ha recibido abierta y el siguiente hijo de ella solo va a leer.
			close(fdp[((args->num_cmd) + 1) % 2][READ_END]); //cerramos lectura de la anterior porque igualmente el hijo que va a ller ya la ha recibido abierta y asi el padre deja su copia totalmente cerrada ya.
		}
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_px_args	args;
	int			fdp[2][2];
	pid_t		pid;
	int			fd_ph;

	if (argc < 5)
	{
		ft_fdprintf(2, "Try './pipex infile cmd_1 ... cmd_n outfile'");
		exit (-1);
	}
	args = (args_init(argc, argv, env)); //Para pasar los parametros sin ser demasiados.
	fd_ph = -42;
	if (args.first_cmd == 3) //Si here_doc
		fd_ph = here_doc(args); //Configuro una pipe para leer de ella como si fuera un file.
	while (args.num_cmd < argc - 1) //Mientras haya comandos a ejecutar.
	{
		if (args.num_cmd < argc - 2) //si el comando no es el ultimo, necesito una pipe. Si es el ultimo no.
			if (pipe(fdp[args.num_cmd % 2]) == -1)
				exit(-1);
		pid = fork();
		childs_management(&args, fdp, pid, fd_ph);
		args.num_cmd++;
	}
	free_path(args.split_path);
	return (wait_for_children((args.num_cmd) - (args.first_cmd)));
}

//./pipex infile.txt "cut -d ' ' -f 2,1" "sed 's/[aeiou]/_/g'"
// "sort" "uniq" "tr 'a-z' 'A-Z'"  outfile.txt
//./pipex infile.txt "awk '{print \$2, \$1}'" "grep o" "awk '{print \$1}'"
// "grep es" outfile.txt

//cut 
//	-d (delimitador)
//	-f (field)
//sed
//	's/patrón/reemplazo/modificadores'
//tr -- sustituir o traducir
//	set1 a cambiar por set2
//tr -d 'aeiou'
//	tr con -d tambien sirve para eliminar caracteres de la entrada
//tr -s ' '
//	dejar solo un elemento del indicado si aparecen mas de uno seguidos.
