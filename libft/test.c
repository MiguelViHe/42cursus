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
	printf("ft_isalpha resultado = %d\n", result);
	result = isalpha(c);
	printf("isalpha resultado = %d\n", result);
}

void	test_ft_digit(void)
{
	int		result;
	int		c;

	c = 48;
	result = ft_isdigit(c);
	printf("ft_isdigit resultado = %d\n", result);
	result = isdigit(c);
	printf("isdigit resultadO = %d\n", result);
}

void	test_ft_isalnum(void)
{
	int	result;
	int		c;

	c = 48;
	result = ft_isalnum(c);
	printf("ft_isalnum resultado = %d\n", result);
	result = isalnum(c);
	printf("isalnum resultadO = %d\n", result);
}

void	test_ft_isascii(void)
{
	int		result;
	int		c;

	c = -2;
	result = ft_isascii(c);
	printf("ft_isascii resultado = %d\n", result);
	result = isascii(c);
	printf("isascii resultadO = %d\n", result);
}

void	test_ft_isprint(void)
{
	int		result;
	int		c;

	c = 32;
	result = ft_isprint(c);
	printf("ft_isprint resultado = %d\n", result);
	result = isprint(c);
	printf("isprint resultadO = %d\n", result);
	result = ft_isprint(127);
	printf("ft_isprint resultado2 = %d\n", result);
	result = isprint(127);
	printf("isprint resultadO2 = %d\n", result);
}

void	test_ft_strlen(void)
{
	printf("length = %d\n", ft_strlen("Camion"));
	printf("lengthO = %d\n", strlen("Camion"));
	printf("length = %d\n", ft_strlen(""));
	printf("lengthO = %d\n", strlen(""));
}

void	test_ft_memset(void)
{
	char	str[20] = "Hola mundo";

	memset(str, '$', 5); // memset da warning si usamos 0 como 3er parametro.
	printf("memset: Cadena resultante: %s\n", str);
	ft_memset(str, '*', 3);
	printf("ft_memset: Cadena resultante: %s\n", str);
}

void	test_ft_bzero(void)
{
	char	str[20] = "Hola mundo";
	int		i;

	/*i = 0;
	printf("bzero\n");
	bzero(str, 3);
	while (i < 20)
	{
		printf("%d = %c\n", i, str[i]);
		i++;
	}*/
	ft_bzero(str, 5);
	i = 0;
	printf("ft_bzero\n");
	while (i < 20)
	{
		printf("%d = %c\n", i, str[i]);
		i++;
	}
}

void test_ft_memcpy(void) {
    char origen[] = "Hola, mundo!";
    char destino[20];
    char origen2[] = "Hola, mundo!";
    char destino2[20];
    //char *origen = NULL;
    //char *destino = NULL;
    //char *origen2 = NULL;
    //char *destino2 = NULL;

    memcpy(destino, origen, 7);
    printf("memcpy Origen: %s\nDestinoO: %s\n", origen, destino);
    ft_memcpy(destino2, origen2, 7);
    printf("ft_memcpy Origen: %s\nDestino: %s\n", origen2, destino2);
}

void test_ft_memmove(void) {
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
	unsigned int	longitud;
	char			origen[] = "1234567890123456789";

	longitud = ft_strlcpy(destino, origen, 15); //probar en mac borrando ft_
	printf ("ft_strlcpy origen = %s\n", origen);
	printf ("ft_strlcpy destino: %s\n", destino);
	printf ("ft_strlcpy longitud = %d\n", longitud);
}

int	main(void)
{
	test_ft_isalpha();
	printf("\n");
	test_ft_digit();
	printf("\n");
	test_ft_isalnum();
	printf("\n");
	test_ft_isascii();
	printf("\n");
	test_ft_isprint();
	printf("\n");
	test_ft_strlen();
	printf("\n");
	test_ft_memset();
	printf("\n");
	test_ft_bzero();
	printf("\n");
	test_ft_memcpy();
	printf("\n");
	test_ft_memmove();
	printf("\n");
	test_ft_strlcpy();
	printf("\n");
	return (0);
}
