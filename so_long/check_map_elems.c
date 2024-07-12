/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:26:57 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/07/10 12:30:58 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static int	is_char_in_elems(char c, char *elems)
{
	int	i;

	i = 0;
	while (elems[i])
	{
		if (c == elems[i])
			return (1);
		i++;
	}
	return (0);
}

static void	check_middle(char *buffer, char *elems)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		if (i == 0 || i == (get_len_of_line(buffer) - 1))
		{
			if (buffer[i] != '1')
				wrong_map_exit(buffer, "Error\nIncorrect boundary elements.", 1);
		}
		else
			if (!is_char_in_elems(buffer[i], elems))
				wrong_map_exit(buffer, "Error\nInvalid elements in map.", 1);
		i++;
	}
}

static void	check_up_down(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		if (buffer[i] != '1')
			wrong_map_exit(buffer, "Error\nIncorrect boundary elements.", 1);
		i++;
	}
}

void	check_map_elems(char *map_name, int map_lines)
{	
	int 		fd;
	char		*buffer;
	int			current_line;

	fd = secure_open(map_name);
	buffer = get_next_line(fd);
	if (buffer == NULL)
		wrong_map_exit(buffer, "Error\nReading line from map.", 0);
	current_line = 1;
	while(buffer)
	{
		if (current_line == 1 || current_line == map_lines)
			check_up_down(buffer);
		else
			check_middle(buffer, "01CEP");
		current_line++;
		free (buffer);
		buffer = get_next_line(fd);
	}
	secure_close(fd);
}