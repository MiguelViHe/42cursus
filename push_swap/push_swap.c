/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:03:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/08 20:19:10 by mvidal-h         ###   ########.fr       */
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
			ft_printf("%d -> ", *(int *)aux->content);
			aux = aux->next;
		}
	}
	ft_printf("NULL\n");
}

t_list	*fill_stack(char *argv[])
{
	int		i;
	int		*number;
	t_list	*stack;
	t_list	*new;

	stack = NULL;
	i = 1;
	while (argv[i])
	{
		number = (int *)malloc(sizeof(int));
		if (!number)
			return (free_stack(&stack), NULL);
		*number = ft_atoi(argv[i]);
		new = ft_lstnew(number);
		if (!new)
			return (free(number), free_stack(&stack), NULL);
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_list	**stka;
	t_list	**stkb;

	if (argc < 2)
		return (-1);
	stka = (t_list **)malloc(sizeof(t_list *));
	stkb = (t_list **)malloc(sizeof(t_list *));
	*stka = fill_stack(argv);
	*stkb = NULL;
	print_stack(stka);
	print_stack(stkb);
	do_pb(stka, stkb);
	print_stack(stka);
	print_stack(stkb);
	do_sa(stka);
	print_stack(stka);
	print_stack(stkb);
	do_ra(stka);
	print_stack(stka);
	print_stack(stkb);
	do_pb(stka, stkb);
	print_stack(stka);
	print_stack(stkb);
	do_sa(stka);
	do_rrb(stkb);
	print_stack(stka);
	print_stack(stkb);
	free_stack(stka);
	print_stack(stka);
	print_stack(stkb);
	free_stack(stkb);
	print_stack(stka);
	print_stack(stkb);
	free(stka);
	free(stkb);
	return (0);
}
