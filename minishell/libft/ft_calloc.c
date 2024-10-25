/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/02/02 21:07:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*contiguously allocates enough space for count objects
that are size bytes of memory each and returns a pointer to the allocated
memory.  The allocated memory is filled with bytes of value zero.*/
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

/*int	main(void)
{
	int		*oi;
	char	*oc;
	int		*fti;
	char	*ftc;
	size_t	i;
	size_t	num_elem;

	num_elem = 5;
	oi = (int *)calloc(num_elem, sizeof(int));
	oc = (char *)calloc(num_elem, sizeof(char));
	fti = (int *)ft_calloc(num_elem, sizeof(int));
	ftc = (char *)ft_calloc(num_elem, sizeof(char));
	i = 0;
	if (oi == NULL || oc == NULL || fti == NULL || ftc == NULL)
	{
		fprintf(stderr, "Error al asignar memoria.\n");
		return (1);
	}
	while (i < num_elem)
	{
		printf("Elemento oi %zu: %d\n", i, oi[i]);
		printf("Elemento oc %zu: %c\n", i, oc[i]);
		printf("Elemento fti %zu: %d\n", i, fti[i]);
		printf("Elemento ftc %zu: %c\n", i, ftc[i]);
		i++;
	}
	free(oi);
	free(oc);
	free(fti);
	free(ftc);
	return (0);
}*/
