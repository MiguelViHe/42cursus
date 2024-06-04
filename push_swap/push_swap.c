/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:03:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/04 14:25:23 by mvidal-h         ###   ########.fr       */
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

/*int	main(int argc, char *argv[])
{
	t_list	**stka;
	t_list	**stkb;
	int		size;

	if (argc < 2)
		return (-1);
	stka = (t_list **)malloc(sizeof(t_list *));
	stkb = (t_list **)malloc(sizeof(t_list *));
	*stka = fill_stack(argv);
	*stkb = NULL;
	fill_index(stka);
	fill_position(stka);
	print_stack(stka);
	print_stack(stkb);
	ft_printf("\n");
	print_inverse_stack(stka);
	print_inverse_stack(stkb);
	ft_printf("\n");
	size = ft_lstsize(*stka);
	if (size == 2)
		two_args(stka);
	else if (size == 3)
		three_args(stka);
	//do_pb(stka, stkb);
	//do_pb(stka, stkb);
	do_rra(stka);
	ft_printf("\n");
	print_stack(stka);
	print_stack(stkb);
	ft_printf("\n");
	print_inverse_stack(stka);
	print_inverse_stack(stkb);
	//print_stack(stkb);
	free_stack(stka);
	free_stack(stkb);
	free(stka);
	free(stkb);
	return (0);
}*/

int	main(int argc, char *argv[])
{
	t_list	**stka;

	stka = (t_list **)malloc(sizeof(t_list *));
	*stka = generate_stack(argc, argv);
	if (!stka || is_duplicated(*stka))
		ft_printf("Error\n");
	else if (!is_sorted(stka))
		sort_stack(stka);
	free(stka);
}
