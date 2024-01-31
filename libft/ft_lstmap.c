/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:08:29 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/31 14:08:29 by mvidal-h         ###   ########.fr       */
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
}

static void	*ft_toupper_str(void *str)
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
	return (str);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*prev;
	t_list	*first;

	first = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		if (first == NULL)
			first = new;
		else
		{
			prev->next = new;
		}
		prev = new;
		lst = lst->next;
	}
	return (first);
}

/*int	main(void)
{
	char	*str = ft_strdup("Hola");
	char	*str2 = ft_strdup("Mundo");
	char	*str3 = ft_strdup("cruel");
	t_list	*node;
	t_list	*node2;
	t_list	*node3;
	t_list	**first;
	t_list	*result;

	node = ft_lstnew(str);
	node2 = ft_lstnew(str2);
	node3 = ft_lstnew(str3);
	node->next = node2;
	node2->next = node3;
	first = &node;
	printf("ft_lstmap:\n");
	ft_print_list(*first);
	result = ft_lstmap(*first, ft_toupper_str, del_content);
	printf("despues de map:\n");
	ft_print_list(result);
	printf("despues de clear:\n");
	ft_lstclear(&result, del_content);
	ft_print_list(result);
	return (0);
}*/
