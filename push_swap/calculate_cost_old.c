/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:26:25 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/10 20:37:29 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*Calculates the cost of moving the element in the position "pos" to the 
top of the stack a*/
int	cost_to_top(t_list **stack, int pos)
{
	int		len;

	len = ft_lstsize(*stack);
	if (pos <= len / 2)
		return (pos);
	else
		return ((len - pos) * -1);
}

/*Calculates the cost of moving the previous element of the
index element to the top of the stack b*/
int	cost_to_pos(t_list	**stack, int ndx)
{
	t_list	*aux;
	t_list	*max;
	t_list	*min;
	int		len;
	int		costpos;

	aux = *stack;
	len = ft_lstsize(aux);
	min = lst_min(stack);
	max = lst_max(stack);
	if (ndx < min->index || ndx > max->index)
		costpos = cost_to_top(stack, max->position);
	else
	{
		aux = aux->next;
		while (aux && !(ndx > aux->index && ndx < aux->prev->index))
			aux = aux->next;
		if (aux == NULL)
			costpos = 0;
		else if (aux->position <= len / 2)
			costpos = aux->position;
		else
			costpos = (len - aux->position) * -1;
	}
	return (costpos);
}

static int	combinated_cost(int costop, int costpos)
{
	int	abs_costop;
	int	abs_costpos;

	abs_costop = ft_abs(costop);
	abs_costpos = ft_abs(costpos);
	if (costop * costpos <= 0)
		return (abs_costop + abs_costpos);
	else
	{
		if (abs_costop >= abs_costpos)
			return (abs_costpos + (abs_costop - abs_costpos));
		else
			return (abs_costop + (abs_costpos - abs_costop));
	}
}

/*Calculates the cost of moving each element, calculating the needed movements
in stack a and stack b and check if its possible to move both together */
void	calculate_cost(t_list **stacka, t_list **stackb)
{
	t_list	*aux;
	int		costa;
	int		costb;

	aux = *stacka;
	while (aux)
	{
		costa = cost_to_top(stacka, aux->position);
		costb = cost_to_pos(stackb, aux->index);
		aux->cost = combinated_cost(costa, costb) + 1;
		aux = aux->next;
	}
}
