/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:03:56 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:45:44 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

int	ft_biggest(int num1, int num2)
{
	if (num1 >= num2)
		return (num1);
	else
		return (num2);
}
