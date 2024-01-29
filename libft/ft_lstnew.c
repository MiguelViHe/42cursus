/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:58:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/28 17:58:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

/*int	main(void)
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
}*/
