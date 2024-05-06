/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:03:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/06 18:26:26 by mvidal-h         ###   ########.fr       */
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

t_list	**fill_stack(char *argv[]) //LIBERAR TODO CUANDO FALLA MALLOC
{
	int		i;
	int		*number;
	t_list	**stacka;
	t_list	*first;

	stacka = NULL;
	i = 1;
	while (argv[i])
	{
		number = (int *)malloc(sizeof(int));
		if (!number)
			return (NULL);
		*number = ft_atoi(argv[i]);
		if (stacka == NULL)
		{
			first = ft_lstnew(number);
			if (!first)
				return (NULL);
			stacka = &first;
		}
		else
			ft_lstadd_back(stacka, ft_lstnew(number));
		i++;
	}
	return (stacka);
}

int	main(int argc, char *argv[])
{
	t_list	**stka;
	t_list	**stkb;
	
	if (argc < 2)
		return (-1);
	stka = fill_stack(argv);
	stkb = NULL;
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	print_stack(stka);
	print_stack(stkb);
	rotate(stka);
	print_stack(stka);
	print_stack(stkb);
	rotate(stka);
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	print_stack(stka);
	print_stack(stkb);
	reverse(stka);
	print_stack(stka);
	print_stack(stkb);
	reverse(stka);
	print_stack(stka);
	print_stack(stkb);
	reverse(stka);
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	print_stack(stka);
	print_stack(stkb);
	rotate(stka);
	print_stack(stka);
	print_stack(stkb);
	reverse(stka);
	print_stack(stka);
	print_stack(stkb);
	push(stka, stkb);
	print_stack(stka);
	print_stack(stkb);
	return (0);
}