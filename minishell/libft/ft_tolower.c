/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:46:57 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/12 13:46:57 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

/*Convert the element c to uppercase if it is lowercase.
 In other cases, return c without changes.*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*int	main(void)
{
	printf("%c\n", tolower('W'));
	printf("%c\n", tolower('$'));
	printf("%c\n", tolower('t'));
	printf("%c\n", tolower('3'));
	printf("%c\n", tolower('`'));
	printf("%c\n", ft_tolower('W'));
	printf("%c\n", ft_tolower('$'));
	printf("%c\n", ft_tolower('t'));
	printf("%c\n", ft_tolower('3'));
	printf("%c\n", ft_tolower('`'));
	return (0);
}*/
