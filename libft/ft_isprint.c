/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:43:06 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/10 12:44:28 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

//Check if the parameter is printable (between 32 and 126)
int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

/*int	main(void)
{
	int		result;

	result = ft_isprint(32);
	printf("resultado = %d\n", result);
	result = isprint(32);
	printf("resultadO = %d\n", result);
	result = ft_isprint(127);
	printf("resultado2 = %d\n", result);
	result = isprint(127);
	printf("resultadO2 = %d\n", result);
	return (0);
}*/
