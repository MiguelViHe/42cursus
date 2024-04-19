/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:44:39 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/29 19:44:39 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

/*int	main(void)
{
	t_list	*node;
	t_list	*node2;
	t_list	*node_new;
	t_list	**first;
	char	*str = "Hola";
	char	*str2 = "Mundo";
	char	*str3 = "Im the new one";

	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node_new = ft_lstnew(str3);
	node->next = node2;
	first = &node;
	printf("ft_lstadd_back:\n");
	ft_print_list(*first);
	ft_lstadd_back(first, node_new);
	ft_print_list(*first);
	return (0);
}*/
