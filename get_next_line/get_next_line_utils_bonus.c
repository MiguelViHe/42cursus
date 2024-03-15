/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:40:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/15 20:19:31 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

int	is_eol(char	*str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (str[i] == '\n')
		return (1);
	return (0);
}
