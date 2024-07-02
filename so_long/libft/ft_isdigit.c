/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:40:40 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/15 17:42:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

//Return zero if parameter is not a digit and positive number if it is.
int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

/*int	main(void)
{
	int		result;

	result = ft_isdigit(48);
	printf("resultado = %d\n", result);
	result = isdigit(48);
	printf("resultadO = %d\n", result);
	return (0);
}*/
