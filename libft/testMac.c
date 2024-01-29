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
#include <limits.h> // para ver los limites en itoa
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

	printf("ft_strlen - cadena = %s, length = %zu\n", cadena, ft_strlen(cadena));//zu
	printf("strlen - cadena = %s, lengthO = %lu\n", cadena, strlen(cadena));//lu
	cadena = "";
	printf("ft_strlen - cadena = %s, length = %zu\n", cadena, ft_strlen(cadena));//zu
	printf("strlen - cadena = %s, lengthO = %lu\n", cadena, strlen(cadena));//lu
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

	num = 3; //VOLVER A ABRIR RN MAC
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
	char			destino2[15]; //VOLVER A ABRIR EN MAC
	unsigned int	longitud;
	char			origen[] = "1234567890123456789";

	longitud = ft_strlcpy(destino, origen, 15);
	printf ("ft_strlcpy origen = %s\n", origen);
	printf ("ft_strlcpy destino: %s\n", destino);
	printf ("ft_strlcpy longitud = %d\n", longitud);
	longitud = strlcpy(destino2, origen, 15); //VOLVER A ABRIR EN MAC
	printf ("strlcpy origen = %s\n", origen);
	printf ("strlcpy destino: %s\n", destino2);
	printf ("strlcpy longitud = %d\n", longitud);
}

void	test_ft_strlcat(void)
{
	char	desti[12] = "qwerty";
	char	desti2[12] = "qwerty"; //ABRIR TODO EN MAC
	char	src[] = "QWER";
	size_t	length;
	size_t	original;

	length = ft_strlcat(desti, src, 12); //probar con0, 3 con 7 y con 12
	original = strlcat(desti2, src, 7);
	printf("ft_strlcat longitud = %zu, destino = %s\n", length, desti);
	printf("strlcat longitud = %zu, destino = %s\n", original, desti2);
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

	printf("search = %c, strchr = %s\n", caracter, resultado);
	printf("search = %c, ft_strchr = %s\n", caracter, resultadoft);
}

void	test_ft_strrchr(void)
{
	const char	*cadena = "Hola, mundo!";
	char		caracter = 'o';
	char		*resultado = strrchr(cadena, caracter + 256);
	char		*resultadoft = ft_strrchr(cadena, caracter + 256);

	printf("search = %c, strrchr = %s\n", caracter, resultado);
	printf("search = %c, ft_strrchr = %s\n", caracter, resultadoft);
}

void	test_ft_strncmp(void)
{
	size_t	n;
	char	s1[] = "testeado";
	char	s2[] = "test";

	n = 4;
	printf("n = %zu, s1 = %s, s2 = %s: strncmp %d\n", n, s1, s2, strncmp(s1, s2, n));//zu
	printf("n = %zu, s1 = %s, s2 = %s: ft_strncmp %d\n", n, s1, s2, ft_strncmp(s1, s2, n));//zu
}

void	test_ft_memchr(void)
{
	//Con array de char.
	printf("memchr y ft_memchr con array de char:\n");
	const char str[] = "Hola, mundo!";
	char chr = 'u';
	size_t	n = 7;

	printf("memchr - %s, %c, %zu: %s\n", str, chr, n, (char *)memchr(str, chr, n));//zu
	printf("ft_memchr - %s, %c, %zu: %s\n", str, chr, n, (char *)ft_memchr(str, chr, n));//zu

	//con array de ints
	printf("\nmemchr y ft_memchr con array de int:\n");
	int array[] = {1, 2, 3, 4, 19, 6, 7, 18};
	int valor_buscado = 19;

	size_t tamano = sizeof(array) / sizeof(array[0]);
	printf("tamano = sizeof(array) / sizeof(array[0])-> %zu = %lu / %lu\n", tamano, sizeof(array), sizeof(array[0]));
	int *resultadoO = memchr(array, valor_buscado, tamano * sizeof(int));
	int *resultadoft = ft_memchr(array, valor_buscado, tamano * sizeof(int));

	if (resultadoO != NULL)
		printf("memchr - valor %d  en la posicion %ld.\n", valor_buscado, resultadoO - array);
	else
		printf("memchr - valor %d no fue encontrado.\n", valor_buscado);

	if (resultadoft != NULL)
		printf("ft_memchr - valor %d  en la posicion %ld.\n", valor_buscado, resultadoft - array);
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
	printf("memcmp - str = %s, str2 = %s n = %zu: %d\n", str, str2, n, memcmp(str, str2, n));
	printf("ft_memcmp - str = %s, str2 = %s n = %zu: %d\n", str, str2, n, ft_memcmp(str, str2, n));

	//con array de ints
	printf("\nmemcmp y ft_memcmp con array de int:\n");
	int array[] = {1, 2, 3, 4, 19, 6, 15, 18};
	int array2[] = {1, 2, 3, 4, 22, 6, 7, 18};

	size_t tamano = sizeof(array) / sizeof(array[0]);
	printf("tamano = sizeof(array) / sizeof(array[0]) -> %zu = %lu / %lu\n", tamano, sizeof(array), sizeof(array[0]));
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
		printf("ft_strnstr - str = %s, needle = %s, len = %zu: %s\n", str, needle, len, result);//zu
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

void test_ft_calloc(void)
{
	int		*oi;
	char	*oc;
	int		*fti;
	char	*ftc;
	size_t	i;
	size_t	num_elem;

	num_elem = 5;
	printf("CALLOC:\n");
	oi = (int *)calloc(num_elem, sizeof(int));
	oc = (char *)calloc(num_elem, sizeof(char));
	fti = (int *)ft_calloc(num_elem, sizeof(int));
	ftc = (char *)ft_calloc(num_elem, sizeof(char));
	i = 0;
	if (oi == NULL || oc == NULL || fti == NULL || ftc == NULL)
	{
		fprintf(stderr, "Error al asignar memoria.\n");
	}
	while (i < num_elem)
	{
		printf("Elemento original int %zu: %d\n", i, oi[i]);
		printf("Elemento original char %zu: %c\n", i, oc[i]);
		printf("Elemento ft int %zu: %d\n", i, fti[i]);
		printf("Elemento ft char %zu: %c\n", i, ftc[i]);
		i++;
	}
	free(oi);
	free(oc);
	free(fti);
	free(ftc);
}

void	*test_ft_strdup(void)
{
	char	src[] = "Hola_mundo!";
	char	*ori;
	char	*ft;

	ori = strdup(src);
	if (!ori)
		return (NULL);
	ft = ft_strdup(src);
	if (!ft)
		return (NULL);
	printf("src = %s\n", src);
	printf("strdup = %s\n", ori);
	printf("ft_strdup = %s\n", ft);
	free(ori);
	free(ft);
	return (0);
}

void	test_ft_substr(void)
{
	char			cadena[] = "Hola_Mundo";
	char			*substring;
	unsigned int	start = 5;
	size_t			length = 3;

	substring = ft_substr(cadena, start, length);
	printf("str = %s, start = %d, length = %zu : ft_substr = %s\n", cadena, start, length, substring);
	free(substring);
}

void	test_ft_strjoin(void)
{
	char	cadena1[] = "hola, ";
	char	cadena2[] = "como estas?";
	char	*resultado;

	resultado = ft_strjoin(cadena1, cadena2);
	printf("ft_strjoin: s1 = %s, s2 = %s: resultado = %s\n", cadena1, cadena2, resultado);
	free(resultado);
}

void	test_ft_strtrim(void)
{
	//char	*clean = NULL;
	char	clean[] = "3321Hola1112";
	char	set[] = "123";
	char	*result;

	result = ft_strtrim(clean, set);
	printf("strtrim: set = %s, cadena = %s: cleaned string = %s\n", set, clean, result);
	free(result);
}

void	test_ft_split(void)
{
	char	*cadena = "      split       this for   me  !       ";
	char	de = ' ';
	char	**result;
	int		i;

	i = 0;
	result = ft_split(cadena, de);
	if (result)
	{
		printf("ft_split: cadena = %s,\ndelimitador = %c,\n", cadena, de);
		while (result && result[i])
		{
			printf("palabra %d = %s\n", i + 1, result[i]);
			i++;
		}
		//free_array(result, count_words(cadena, de));
	}
}

void	test_ft_itoa(void)
{
	printf("ft_itoa:\n");
	printf("numero = -2147483648 : numero en cadena = %s\n", ft_itoa(-2147483648));
	printf("numero = 2147483647 : numero en cadena = %s\n", ft_itoa(2147483647));
	printf("numero = -123 : numero en cadena = %s\n", ft_itoa(-123));
	printf("numero = 0 : numero en cadena = %s\n", ft_itoa(0));
	printf("numero = -0 : numero en cadena = %s\n", ft_itoa(-0));
	printf("El rango de int es: %d a %d\n", INT_MIN, INT_MAX);
	printf("El rango de long int es: %ld a %ld\n", LONG_MIN, LONG_MAX);
}

//sum the intex to the char
static char	enigma(unsigned int index, char c)
{
	return (c + index);
}
//make the encoding method ROT13 to the even elements
static char	rot13(unsigned int index, char c)
{
	if (!(index % 2))
	{
	c = (c + 13) % 127;
	if (c < 32)
		c += 32;
	}
	return (c);
}

void	test_ft_strmapi(void)
{
char	str[] = "Hello world";

printf("ft_strmapi:\n");
printf("original = %s\n", str);
printf("enigma = %s\n", ft_strmapi(str, enigma));
printf("rot13 = %s\n", ft_strmapi(str, rot13));
}

//sum the intex to the char
static void	enigma_iteri(unsigned int index, char *c)
{
	*c = *c + index;
}
//make the encoding method ROT13 to the even elements
static void rot13_iteri(unsigned int index, char *c)
{
	if (!(index % 2))
	{
	*c = (*c + 13) % 127;
	if (*c < 32)
		*c += 32;
	}
}

void	test_ft_striteri(void)
{
char	str1[] = "world";
char	str2[] = "world";

printf("ft_striteri:\n");
printf("original1 = %s\n", str1);
printf("original2 = %s\n", str2);
ft_striteri(str1, enigma_iteri);
printf("enigma = %s\n", str1);
ft_striteri(str2, rot13_iteri);
printf("rot13 = %s\n", str2);
}

void	test_ft_putchar_fd(void)
{
	int		fd;
	char	s;

	s = '&';
	fd = open("ft_putchar_fd.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putchar_fd(s, fd);
	close(fd);
	printf("ft_putchar_fd... archivo creado o modificado.\n");
}

void	test_ft_putstr_fd(void)
{
	int		fd;
	char	str[] = "Hola Mundo";

	fd = open("ft_putstr_fd.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putstr_fd(str, fd);
	close(fd);
	printf("ft_putstr_fd... archivo creado o modificado.\n");
}

void	test_ft_putendl_fd(void)
{
	int		fd;
	char	str[] = "-Hola Mundo-";

	fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putendl_fd(str, fd);
	close(fd);
	printf("ft_putendl_fd... archivo creado o modificado.\n");
}

void	test_ft_putnbr_fd(void)
{
	int	number;
	int	fd;

	number = -483648;
	fd = open("file.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		perror("Error opening the file");
	ft_putnbr_fd(number, fd);
	close(fd);
	printf("ft_putnbr_fd... archivo creado o modificado.\n");
}

//BONUS TEST

void	test_ft_lstnew(void)
{
	char	*str = "Hola Mundo";
	char	c = 'e';
	int		i = 8;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew(str);
	node2 = ft_lstnew(&c);
	node3 = ft_lstnew(&i);
	printf("ft_lstnew:\n");
	printf("contenido de node1 = %s\n", (char *)node1->content);
	if (node1->next == NULL)
		printf("next de node1 es NULL\n");
	else
		printf("next de node1 distinto de NULL\n");
	printf("contenido de node2 = %c\n", *(char *)node2->content);
	if (node2->next == NULL)
		printf("next de node2 es NULL\n");
	else
		printf("next de node2 distinto de NULL\n");
	printf("contenido de node3 = %d\n", *(int *)node3->content);
	if (node3->next == NULL)
		printf("next de node3 es NULL\n");
	else
		printf("next de node3 distinto de NULL\n");
}

static void	ft_print_list(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		printf("%s -> ", (char *)aux->content);
		aux = aux->next;
	}
	printf("NULL\n");
}

void	test_ft_lstadd_front(void)
{
	t_list	*node;
	t_list	*node2;
	t_list	*node_new;
	t_list	**first;
	char	*str = "Hola";
	char	*str2 = "Mundo";
	char	*str3 = "Im the first one";

	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node_new = ft_lstnew(str3);
	node->next = node2;
	first = &node;
	printf("ft_lstadd_front:\n");
	ft_print_list(*first);
	ft_lstadd_front(first, node_new);
	ft_print_list(*first);
}

void	test_ft_lstsize(void)
{
	t_list	*node;
	t_list	*node2;
	t_list	*node3;
	char	*str = "Hola";
	char	*str2 = "Mundo";
	char	*str3 = "Im the first one";

	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node3 = ft_lstnew(str3);
	node->next = node2;
	node2->next = node3;
	printf("ft_lstsize;\n");
	ft_print_list(node);
	printf("numero de nodos = %d\n",ft_lstsize(node));
}

void	test_ft_lstlast(void)
{
	t_list	*node;
	t_list	*node2;
	t_list	*node3;
	//t_list	*test_null;
	t_list	*ultimo;
	char	*str = "Hola";
	char	*str2 = "Mundo";
	char	*str3 = "Im the last one";

	//test_null = NULL;
	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node3 = ft_lstnew(str3);
	node->next = node2;
	node2->next = node3;
	printf("ft_lstlast:\n");
	ft_print_list(node);
	ultimo = ft_lstlast(node);
	if (ultimo)
		printf("ultimo nodo  = %s\n", (char *)ultimo->content);
	else
		printf("no existe ningun nodo.\n");
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
	test_ft_calloc();
	printf("-----\n");
	test_ft_strdup();
	printf("-----\n");
	test_ft_substr();
	printf("-----\n");
	test_ft_strjoin();
	printf("-----\n");
	test_ft_strtrim();
	printf("-----\n");
	test_ft_split();
	printf("-----\n");
	test_ft_itoa();
	printf("-----\n");
	test_ft_strmapi();
	printf("-----\n");
	test_ft_striteri();
	printf("-----\n");
	test_ft_putchar_fd();
	printf("-----\n");
	test_ft_putchar_fd();
	printf("-----\n");
	test_ft_putstr_fd();
	printf("-----\n");
	test_ft_putendl_fd();
	printf("-----\n");
	test_ft_putnbr_fd();
	printf("\n----- final parte obligatoria---\n\n");
	test_ft_lstnew();
	printf("-----\n");
	test_ft_lstadd_front();
	printf("-----\n");
	test_ft_lstsize();
	printf("-----\n");
	test_ft_lstlast();
	printf("-----\n");
	return (0);
}
