/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:40:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 14:32:34 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Return zero if parameter is not a digit and positive number if it is.
int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}
