/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 22:57:24 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/28 22:57:24 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

/*static void	ft_print_list(t_list **lst)
{
	t_list	*aux;

	aux = *lst;
	while (aux->next)
	{
		printf("%s -> ", (char *)aux->content);
		aux = aux->next;
	}
	printf("%s -> NULL\n", (char *)aux->content);
}*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*int	main(void)
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
	ft_print_list(first);
	ft_lstadd_front(first, node_new);
	ft_print_list(first);
	return (0);
}*/
