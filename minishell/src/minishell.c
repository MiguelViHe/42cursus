/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:09:14 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/10/25 15:44:16 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(void)
{
	char *input;

	while (1) {
		// Muestra el prompt y espera la entrada del usuario
		input = readline("mvidal-h> ");
		// Verifica si la entrada es NULL (EOF o error)
		if (input == NULL)
		{
			printf("Error o fin de entrada.\n");
			break;
		}
		// Compara la entrada para ver si es "exit"
		if (ft_strlen(input) == 4 && ft_strncmp(input, "exit", 4) == 0)
		{
			free(input);
			break;
		}
		// Si el usuario escribió algo, agrégalo al historial
		if (*input) {
			add_history(input);
		// Imprime el comando que el usuario ingresó
			printf("Comando ingresado: %s\n", input);
		}
		// Libera la memoria de la entrada para evitar fugas de memoria
		free(input);
	}
	// Borra el historial cuando termina el programa
	rl_clear_history();
	return 0;
}
