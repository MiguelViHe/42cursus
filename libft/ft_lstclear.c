/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 08:37:36 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/30 08:37:36 by mvidal-h         ###   ########.fr       */
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
}

static void	del_content(void *content)
{
	free(content);
}*/

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}

/*int	main(void)
{
	char	*str = ft_strdup("Hola");
	char	*str2 = ft_strdup("Mundo");
	char	*str3 = ft_strdup("maravilloso");
	t_list	*node;
	t_list	*node2;
	t_list	*node3;
	t_list	**first;

	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node3 = ft_lstnew(str3);
	node->next = node2;
	node2->next = node3;
	first = &node;
	printf("ft_lstclear:\n");
	ft_print_list(*first);
	ft_lstclear(first, del_content);
	printf("despues de borrar:\n");
	ft_print_list(*first);
	return (0);
}*/

