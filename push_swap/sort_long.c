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

/*Move a node to the top of the stack
It recieve as arguments the element to move and two funtions.
The functions are for diference if is the stack A or B*/
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

/*Once B is inversed sorted, it psuh every node in B to A controlling
that it is pushed to the correct position*/
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

/*Return the element with smallest cost in stack*/
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

/*Sort B in reversed order till just three nodes left in A
It calculates the cost in movements to take every node from A to its
position in B.
Then choose the node with min cost and move it to B stack*/
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

/*Sort the stack when it has more then three nodes.
First push two elements to B, 
then continue pushing elements to B till it is reversed sorted and just
three left in A.
Then push everything to A. Because of B is reversed sorted just have to
push to A one by one keeping the order in a till B is empty*/
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
