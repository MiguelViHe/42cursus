/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 17:23:08 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top(t_list	**s, t_list *e, void (*f)(t_list **, int),
			void (*u)(t_list **, int))
{
	int	size;
	int	movements;

	size = ft_lstsize(*s);
	if (e->position <= size / 2)
	{
		movements = e->position;
		while (movements--)
			f(s, 1);
	}
	else
	{
		movements = size - e->position;
		while (movements--)
			u(s, 1);
	}
}

static void	sort_stack_a(t_list **stacka, t_list **stackb)
{
	t_list	*last;
	t_list	*min;

	last = ft_lstlast(*stacka);
	min = lst_min(stacka);
	while (*stackb)
	{
		if ((*stackb)->index < min->index)
		{
			top(stacka, min, do_ra, do_rra);
			while (*stackb)
				do_pa(stacka, stackb, 1);
		}
		else if ((*stackb)->index > last->index)
			do_pa(stacka, stackb, 1);
		else
		{
			last = last->prev;
			do_rra(stacka, 1);
		}
	}
}

/*Return the element with smallest cost in stack a*/
t_list	*choose_min_cost(t_list **stack)
{
	t_list	*aux;
	t_list	*min_cost;

	if (!*stack)
		return (NULL);
	aux = (*stack)->next;
	min_cost = *stack;
	while (aux)
	{
		if (aux->cost < min_cost->cost)
			min_cost = aux;
		aux = aux->next;
	}
	return (min_cost);
}

static void	sort_stack_b(t_list **stacka, t_list **stackb)
{
	t_list	*elem;
	int		size;

	size = ft_lstsize(*stacka);
	while (size > 3)
	{
		calculate_cost(stacka, stackb);
		elem = choose_min_cost(stacka);
		move_to_b(stacka, stackb, elem);
		size--;
	}
}

void	sort_long_stack(t_list **stacka)
{
	t_list	*stackb;

	stackb = NULL;
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		do_pb(stacka, &stackb, 1);
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		do_pb(stacka, &stackb, 1);
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		sort_stack_b(stacka, &stackb);
	if (!is_sorted(stacka))
		three_args(stacka);
	top(&stackb, lst_max(&stackb), do_rb, do_rrb);
	sort_stack_a(stacka, &stackb);
	top(stacka, lst_min(stacka), do_ra, do_rra);
}
