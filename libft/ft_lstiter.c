/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:27:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/31 11:27:42 by mvidal-h         ###   ########.fr       */
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

static void	ft_str_toupper(void *str)
{
	int		i;
	char	*aux;

	aux = (char *)str;
	i = 0;
	while (aux[i])
	{
		aux[i] = ft_toupper(aux[i]);
		i++;
	}
}*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
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
	printf("ft_lstiter:\n");
	ft_print_list(*first);
	ft_lstiter(*first, ft_str_toupper);
	printf("despues de iter:\n");
	ft_print_list(*first);
	return (0);
}*/
