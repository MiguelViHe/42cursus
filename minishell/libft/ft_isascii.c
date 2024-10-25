/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:37:07 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/10 12:39:06 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

//Check if the parameter is in the ascii code (between 0 and 127)
int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	return (1);
}

/*int	main(void)
{
	int		result;

	result = ft_isascii(-2);
	printf("resultado = %d\n", result);
	result = isascii(-2);
	printf("resultadO = %d\n", result);
	return (0);
}*/
