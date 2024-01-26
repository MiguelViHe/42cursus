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

	printf("ft_strlen - cadena = %s, length = %d\n", cadena, ft_strlen(cadena));//zu
	printf("strlen - cadena = %s, lengthO = %d\n", cadena, strlen(cadena));//lu
	cadena = "";
	printf("ft_strlen - cadena = %s, length = %d\n", cadena, ft_strlen(cadena));//zu
	printf("strlen - cadena = %s, lengthO = %d\n", cadena, strlen(cadena));//lu
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

	/*num = 3; VOLVER A ABRIR RN MAC
	i = 0;
	printf("(%d) - bzero\n", num);
	bzero(str, num);
	while (i < 20)
	{
		printf("%d = %c\n", i, str[i]);
		i++;
	}*/
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

	//src < dest - ABRIR UNO Y CERRAR EL OTRO.
	memmove(destino, origen, 6);
	printf("memmove Origen: %s -> DestinoO: %s\n", origen, destino);
	ft_memmove(destino2, origen2, 6);
	printf("ft_memmove Origen: %s -> Destino: %s\n", origen2, destino2);
	//src > dest - ABRIR UNO Y CERRAR EL OTRO.
	/*memmove(origen, destino, 6);
	printf("memmove Origen: %s, DestinoO: %s\n", destino, origen);
	ft_memmove(origen2, destino2, 6);
	printf("ft_memmove Origen: %s, Destino: %s\n", destino2, origen2);*/
}

void	test_ft_strlcpy(void)
{
	char			destino[15];
	//char			destino2[15]; VOLVER A ABRIR EN MAC
	unsigned int	longitud;
	char			origen[] = "1234567890123456789";

	longitud = ft_strlcpy(destino, origen, 15);
	printf ("ft_strlcpy origen = %s\n", origen);
	printf ("ft_strlcpy destino: %s\n", destino);
	printf ("ft_strlcpy longitud = %d\n", longitud);
	/*longitud = strlcpy(destino2, origen, 15); VOLVER A ABRIR EN MAC
	printf ("strlcpy origen = %s\n", origen);
	printf ("strlcpy destino: %s\n", destino2);
	printf ("strlcpy longitud = %d\n", longitud);*/
}

void	test_ft_strlcat(void)
{
	char	desti[12] = "qwerty";
	//char	desti2[12] = "qwerty"; ABRIR TODO EN MAC
	char	src[] = "QWER";
	size_t	length;
	//size_t	original;

	length = ft_strlcat(desti, src, 12); //probar con0, 3 con 7 y con 12
	//original = strlcat(desti2, src, 7);
	printf("ft_strlcat longitud = %d, destino = %s\n", length, desti);
	//printf("strlcat longitud = %d, destino = %s\n", original, desti2);
}

void	test_ft_toupper(void)
{
	printf("toupper %c %c\n", 'W', toupper('W'));
	printf("toupper %c %c\n", '$',toupper('$'));
	printf("toupper %c %c\n", 't', toupper('t'));
	printf("toupper %c %c\n", '3', toupper('3'));
	printf("toupper %c %c\n", '`', toupper('`'));
	printf("ft_toupper %c %c\n", 'W', ft_toupper('W'));
	printf("ft_toupper %c %c\n", '$', ft_toupper('$'));
	printf("ft_toupper %c %c\n", 't', ft_toupper('t'));
	printf("ft_toupper %c %c\n", '3', ft_toupper('3'));
	printf("ft_toupper %c %c\n", '`', ft_toupper('`'));
}

void	test_ft_tolower(void)
{
	printf("tolower %c %c\n", 'W', tolower('W'));
	printf("tolower %c %c\n", '$',tolower('$'));
	printf("tolower %c %c\n", 't', tolower('t'));
	printf("tolower %c %c\n", '3', tolower('3'));
	printf("tolower %c %c\n", '`', tolower('`'));
	printf("ft_tolower %c %c\n", 'W', ft_tolower('W'));
	printf("ft_tolower %c %c\n", '$', ft_tolower('$'));
	printf("ft_tolower %c %c\n", 't', ft_tolower('t'));
	printf("ft_tolower %c %c\n", '3', ft_tolower('3'));
	printf("ft_tolower %c %c\n", '`', ft_tolower('`'));
}

void	test_ft_strchr(void)
{
	const char	*cadena = "Hola, mundo!";
	char		caracter = 'o';
	char		*resultado = strchr(cadena, caracter + 256);
	char		*resultadoft = ft_strchr(cadena, caracter + 256);

	printf("search = %c, strchr = %s\n",caracter, resultado);
	printf("search = %c, ft_strchr = %s\n",caracter, resultadoft);
}

void	test_ft_strrchr(void)
{
	const char	*cadena = "Hola, mundo!";
	char		caracter = 'o';
	char		*resultado = strrchr(cadena, caracter + 256);
	char		*resultadoft = ft_strrchr(cadena, caracter + 256);

	printf("search = %c, strrchr = %s\n",caracter, resultado);
	printf("search = %c, ft_strrchr = %s\n",caracter, resultadoft);
}

void	test_ft_strncmp(void)
{
	size_t	n;
	char	s1[] = "testeado";
	char	s2[] = "test";

	n = 4;
	printf("n = %d, s1 = %s, s2 = %s: strncmp %d\n", n, s1, s2, strncmp(s1, s2, n));//zu
	printf("n = %d, s1 = %s, s2 = %s: ft_strncmp %d\n", n, s1, s2, ft_strncmp(s1, s2, n));//zu
}

void	test_ft_memchr(void)
{
	//Con array de char.
	printf("memchr y ft_memchr con array de char:\n");
	const char str[] = "Hola, mundo!";
	char chr = 'u';
	size_t	n = 7;

	printf("memchr - %s, %c, %d: %s\n", str, chr, n, (char *)memchr(str, chr, n));//zu
	printf("ft_memchr - %s, %c, %d: %s\n", str, chr, n, (char *)ft_memchr(str, chr, n));//zu

	//con array de ints
	printf("memchr y ft_memchr con array de int:\n");
	int array[] = {1, 2, 3, 4, 19, 6, 7, 18};
	int valor_buscado = 19;

	size_t tamano = sizeof(array) / sizeof(array[0]);
	printf("tamano = sizeof(array) / sizeof(array[0])-> %d = %d / %d\n", tamano, sizeof(array), sizeof(array[0]));
	int *resultadoO = memchr(array, valor_buscado, tamano * sizeof(int));
	int *resultadoft = ft_memchr(array, valor_buscado, tamano * sizeof(int));

	if (resultadoO != NULL)
		printf("memchr - valor %d  en la posicion %d.\n", valor_buscado, resultadoO - array);
	else
		printf("memchr - valor %d no fue encontrado.\n", valor_buscado);

	if (resultadoft != NULL)
		printf("ft_memchr - valor %d  en la posicion %d.\n", valor_buscado, resultadoft - array);
	else
		printf("ft_memchr - valor %d no fue encontrado.\n", valor_buscado);
}

void	test_ft_memcmp(void)
{
	//Con array de char.
	printf("memcmp y ft_memcmp con array de char:\n");
	const char str[] = "Hola Mundo!";
	const char str2[] = "Hola mundo!";
	size_t	n = 6;

	//printf("original = %d\n", memcmp(str, str2, sizeof(str)));
	//printf("ft = %d\n", ft_memcmp(str, str2, sizeof(str)));
	printf("memcmp - str = %s, str2 = %s n = %d: %d\n", str, str2, n, memcmp(str, str2, n));
	printf("ft_memcmp - str = %s, str2 = %s n = %d: %d\n", str, str2, n, ft_memcmp(str, str2, n));

	//con array de ints
	printf("memcmp y ft_memcmp con array de int:\n");
	int array[] = {1, 2, 3, 4, 19, 6, 15, 18};
	int array2[] = {1, 2, 3, 4, 22, 6, 7, 18};

	size_t tamano = sizeof(array) / sizeof(array[0]);
	printf("tamano = sizeof(array) / sizeof(array[0]) -> %d = %d / %d\n", tamano, sizeof(array), sizeof(array[0]));
	int resultadoO = memcmp(array, array2, tamano * sizeof(int));
	int resultadoft = ft_memcmp(array, array2, tamano * sizeof(int));

	if (resultadoO > 0)
		printf("memcmp array es mayor que array2: %d\n", resultadoO);
	else if (resultadoO < 0)
		printf("memcmp array es menor que array2: %d\n", resultadoO);
	else
		printf("memcmp array y array2 son iguales\n");

	if (resultadoft > 0)
		printf("ft_memcmp array es mayor que array2: %d\n", resultadoft);
	else if (resultadoft < 0)
		printf("ft_memcmp array es menor que array2: %d\n", resultadoft);
	else
		printf("ft_memcmp array y array2 son iguales\n");
}

void	test_ft_strnstr(void)
{
	char	str[] = "perone";
	char	needle[] = "ron";
	size_t	len = 5;
	char	*result;

	result = ft_strnstr(str, needle, len);
	if (!result)
		printf("ft_strnstr - No se ha encontrado coincidencia\n");
	else
		printf("ft_strnstr - str = %s, needle = %s, len = %d: %s\n", str, needle, len, result);//zu
}

int	test_ft_atoi(void)
{
	const char	str[] = "     		\t    \r \v \f  \n   -98738i8372";
	int			num = atoi(str);
	int			num2 = ft_atoi(str);

	printf("El numero convertido por atoi es: %d\n", num);
	printf("El numero convertido por ft_atoi es: %d\n", num2);
	return (0);
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
	test_ft_strlcat();
	printf("-----\n");
	test_ft_toupper();
	printf("-----\n");
	test_ft_tolower();
	printf("-----\n");
	test_ft_strchr();
	printf("-----\n");
	test_ft_strrchr();
	printf("-----\n");
	test_ft_strncmp();
	printf("-----\n");
	test_ft_memchr();
	printf("-----\n");
	test_ft_memcmp();
	printf("-----\n");
	test_ft_strnstr();
	printf("-----\n");
	test_ft_atoi();
	printf("-----\n");
	printf("-----\n");
	printf("-----\n");
	printf("-----\n");
	return (0);
}
