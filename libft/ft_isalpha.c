/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:43:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/12 13:09:50 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

//Return zero if parameter is not alphabetic and pisitive number if it is.
int	ft_isalpha(int str)
{
	if (str < 'A' || ('Z' < str && str < 'a') || str > 'z')
		return (0);
	return (1);
}

/*int	main(void)
{
	int		result;

	result = ft_isalpha(123456789);
	printf("resultado = %d\n", result);
	result = isalpha(123456789);
	printf("resultadO = %d\n", result);
	return (0);
}*/
