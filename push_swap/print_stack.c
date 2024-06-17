/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:20:43 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/17 13:21:47 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **first)
{
	t_list	*aux;

	if (first != NULL)
	{
		aux = *first;
		while (aux)
		{
			ft_printf("[%d ,i%d", *(int *)aux->content, aux->index);
			ft_printf(", p%d", aux->position);
			ft_printf(", c%d]-> ", aux->cost);
			aux = aux->next;
		}
	}
	ft_printf("NULL\n");
}

void	print_inverse_stack(t_list **first)
{
	t_list	*aux;

	if (first != NULL)
	{
		aux = ft_lstlast(*first);
		while (aux)
		{
			ft_printf("[%d ,i%d", *(int *)aux->content, aux->index);
			ft_printf(", p%d", aux->position);
			ft_printf(", c%d]-> ", aux->cost);
			aux = aux->prev;
		}
	}
	ft_printf("NULL\n");
}
