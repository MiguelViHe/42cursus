/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:22:03 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/10 20:21:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top(t_list	**s, t_list *e, void (*f)(t_list **), void (*u)(t_list **))
{
	int	size;
	int	movements;

	size = ft_lstsize(*s);
	if (e->position <= size / 2)
	{
		movements = e->position;
		while (movements--)
			f(s);
	}
	else
	{
		movements = size - e->position;
		while (movements--)
			u(s);
	}
}

/*static void	final_push_a(t_list **stacka, t_list **stackb)
{
	t_list	*min;
	int		len;
	int		movements;

	len = ft_lstsize(*stacka);
	min = lst_min(stacka);
	if (min->position <= len/2)
	{
		movements = min->position;
		while (movements--)
			do_ra(stacka);
	}
	else
	{
		movements = len - min->position;
		while (movements--)
			do_rra(stacka);
	}
	if (*stackb)
		do_pa(stacka, stackb);
}*/

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
			ft_printf("EnTOP1\n");
			while (*stackb)
				do_pa(stacka, stackb);
		}
		else if ((*stackb)->index > last->index)
			do_pa(stacka, stackb);
		else
		{
			last = last->prev;
			do_rra(stacka);
		}
		print_stack(stacka);
		print_stack(stackb);
	}
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
		print_stack(stacka);
		print_stack(stackb);
		move_to_b(stacka, stackb, elem);
		size--;
	}
}

void	sort_long_stack(t_list **stacka)
{
	t_list	*stackb;

	stackb = NULL;
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		do_pb(stacka, &stackb);
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		do_pb(stacka, &stackb);
	if (!is_sorted(stacka) && ft_lstsize(*stacka) > 3)
		sort_stack_b(stacka, &stackb);
	if (!is_sorted(stacka))
		three_args(stacka);
	top(&stackb, lst_max(&stackb), do_rb, do_rrb);
	ft_printf("EnTOP2\n");
	ft_printf("RESULTADO en B:\n");
	print_stack(stacka);
	print_stack(&stackb);
	sort_stack_a(stacka, &stackb);
	ft_printf("RESULTADO en A:\n");
	print_stack(stacka);
	print_stack(&stackb);
	top(stacka, lst_min(stacka), do_ra, do_rra);
	ft_printf("EnTOP3\n");
}
