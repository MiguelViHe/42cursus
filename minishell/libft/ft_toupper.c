/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:15:21 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/12 13:15:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

/*Convert the element c to uppercase if it is lowercase.
 In other cases, return c without changes.*/
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*int	main(void)
{
	printf("%c\n", toupper('W'));
	printf("%c\n", toupper('$'));
	printf("%c\n", toupper('t'));
	printf("%c\n", toupper('3'));
	printf("%c\n", toupper('`'));
	printf("%c\n", ft_toupper('W'));
	printf("%c\n", ft_toupper('$'));
	printf("%c\n", ft_toupper('t'));
	printf("%c\n", ft_toupper('3'));
	printf("%c\n", ft_toupper('`'));
	return (0);
}*/
