/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:10:10 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/09/27 14:32:35 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Return 1 when c is one of the values defined in isspace.
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
