/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 01:57:34 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/29 01:57:34 by mvidal-h         ###   ########.fr       */
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

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*aux;

	aux = lst;
	count = 0;
	while (aux)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}

/*int	main(void)
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
	printf("numero de nodos = %d",ft_lstsize(node));
	return (0);
}*/
