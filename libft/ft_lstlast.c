/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:28:55 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/29 18:28:55 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	ft_print_list(t_list *lst)
{
	t_list	*aux;

	aux = lst;
	while (aux)
	{
		printf("%s -> ", (char *)aux->content);
		aux = aux->next;
	}
	printf("NULL\n");
}*/

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (last)
	{
		while (last->next)
		{
			last = last->next;
		}
	}
	return (last);
}

/*int	main(void)
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
	printf("ft_lstlast;\n");
	ft_print_list(node);
	ultimo = ft_lstlast(node);
	if (ultimo)
		printf("ultimo nodo  = %s\n", (char *)ultimo->content);
	else
		printf("no existe ningun nodo.\n");
	return (0);
}*/
