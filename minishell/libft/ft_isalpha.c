/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:43:48 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/23 19:51:58 by mvidal-h         ###   ########.fr       */
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
	printf("ft_isalpha resultado = %d\n", result);
	result = isalpha(123456789);
	printf("isalpha resultado = %d\n", result);
	return (0);
}*/
