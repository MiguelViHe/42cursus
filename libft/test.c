/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:48:32 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/23 19:48:32 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //printf
#include <ctype.h> //isdigit, isalpha...
#include <string.h> //strlen
#include "libft.h"

void	test_ft_isalpha(void)
{
	int		result;
	int		c;

	c = 48;
	result = ft_isalpha(c);
	printf("%c - ft_isalpha resultado = %d\n", c, result);
	result = isalpha(c);
	printf("%c - isalpha resultado = %d\n", c, result);
}

void	test_ft_digit(void)
{
	int		result;
	int		c;

	c = 48;
	result = ft_isdigit(c);
	printf("%c - ft_isdigit resultado = %d\n", c, result);
	result = isdigit(c);
	printf("%c - isdigit resultadO = %d\n", c, result);
}

void	test_ft_isalnum(void)
{
	int	result;
	int	c;

	c = 48;
	result = ft_isalnum(c);
	printf("%c - ft_isalnum resultado = %d\n", c, result);
	result = isalnum(c);
	printf("%c - isalnum resultadO = %d\n", c, result);
}

void	test_ft_isascii(void)
{
	int		result;
	int		c;

	c = 59;
	result = ft_isascii(c);
	printf("%c - ft_isascii resultado = %d\n", c, result);
	result = isascii(c);
	printf("%c - isascii resultadO = %d\n", c, result);
}

void	test_ft_isprint(void)
{
	int		result;
	int		c;

	c = 48;
	result = ft_isprint(c);
	printf("%c - ft_isprint resultado = %d\n", c, result);
	result = isprint(c);
	printf("%c - isprint resultadO = %d\n", c, result);
	c = 0;
	result = ft_isprint(c);
	printf("%c - ft_isprint resultado2 = %d\n", c, result);
	result = isprint(c);
	printf("%c - isprint resultadO2 = %d\n", c, result);
}

void	test_ft_strlen(void)
{
	char	*cadena = "Camion";

	printf("ft_strlen - cadena = %s, length = %zu\n", cadena, ft_strlen(cadena));
	printf("strlen - cadena = %s, lengthO = %lu\n", cadena, strlen(cadena));
	cadena = "";
	printf("ft_strlen - cadena = %s, length = %zu\n", cadena, ft_strlen(cadena));
	printf("strlen - cadena = %s, lengthO = %lu\n", cadena, strlen(cadena));
}

void	test_ft_memset(void)
{
	char	str[20] = "Hola mundo";
	char	c = '$';

	memset(str, c, 5); // memset da warning si usamos 0 como 3er parametro.
	printf("%c - memset: Cadena resultante: %s\n", c, str);
	c = '*';
	ft_memset(str, c, 3);
	printf("%c - ft_memset: Cadena resultante: %s\n", c, str);
}

void	test_ft_bzero(void)
{
	char	str[20] = "Hola mundo";
	int		i;
	int		num;

	num = 3;
	i = 0;
	printf("(%d) - bzero\n", num);
	bzero(str, num);
	while (i < 20)
	{
		printf("%d = %c\n", i, str[i]);
		i++;
	}
	num = 5;
	ft_bzero(str, num);
	i = 0;
	printf("\n(%d) - ft_bzero\n", num);
	while (i < 20)
	{
		printf("%d = %c\n", i, str[i]);
		i++;
	}
}

void	test_ft_memcpy(void) {
	char	origen[] = "Hola, mundo!";
	char	destino[20];
	char	origen2[] = "Hola, mundo!";
	char	destino2[20];

	memcpy(destino, origen, 7);
	printf("memcpy Origen: %s\nDestinoO: %s\n", origen, destino);
	ft_memcpy(destino2, origen2, 7);
	printf("ft_memcpy Origen: %s\nDestino: %s\n", origen2, destino2);
}

void	test_ft_memmove(void) {
	char origen[] = "Hola, mundo!";
	char origen2[] = "Hola, mundo!";
	char *destino = origen + 4;
	char *destino2 = origen2 + 4;

	//src < dest
	memmove(destino, origen, 6);
	printf("memmove Origen: %s -> DestinoO: %s\n", origen, destino);
	ft_memmove(destino2, origen2, 6);
	printf("ft_memmove Origen: %s -> Destino: %s\n", origen2, destino2);
	//src > dest
	/*memmove(origen, destino, 6);
	printf("memmove Origen: %s, DestinoO: %s\n", destino, origen);
	ft_memmove(origen2, destino2, 6);
	printf("ft_memmove Origen: %s, Destino: %s\n", destino2, origen2);*/
}

void	test_ft_strlcpy(void)
{
	char			destino[15];
	char			destino2[15];
	unsigned int	longitud;
	char			origen[] = "1234567890123456789";

	longitud = ft_strlcpy(destino, origen, 15);
	printf ("ft_strlcpy origen = %s\n", origen);
	printf ("ft_strlcpy destino: %s\n", destino);
	printf ("ft_strlcpy longitud = %d\n", longitud);
	longitud = strlcpy(destino2, origen, 15);
	printf ("strlcpy origen = %s\n", origen);
	printf ("strlcpy destino: %s\n", destino2);
	printf ("strlcpy longitud = %d\n", longitud);
}

int	main(void)
{
	test_ft_isalpha();
	printf("-----\n");
	test_ft_digit();
	printf("-----\n");
	test_ft_isalnum();
	printf("-----\n");
	test_ft_isascii();
	printf("-----\n");
	test_ft_isprint();
	printf("-----\n");
	test_ft_strlen();
	printf("-----\n");
	test_ft_memset();
	printf("-----\n");
	test_ft_bzero();
	printf("-----\n");
	test_ft_memcpy();
	printf("-----\n");
	test_ft_memmove();
	printf("-----\n");
	test_ft_strlcpy();
	printf("-----\n");
	return (0);
}
