/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:20:31 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/12 13:09:28 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

//Return zero if parameter is not alphanumeric and pisitive number if it is.
int	ft_isalnum(int c)
{
	if ((c < 'A' || ('Z' < c && c < 'a') || c > 'z') && (c < '0' || c > '9'))
		return (0);
	return (1);
}

/*int	main(void)
{
	int	result;

	result = ft_isalnum(48);
	printf("resultado = %d\n", result);
	result = isalnum(48);
	printf("resultadO = %d\n", result);
	return (0);
}*/
