/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:16:34 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/19 19:25:21 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

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

t_list	*generate_stack(int argc, char *argv[])
{
	t_list	*stack;
	
	if (argc < 2)
		ft_printf("imprimir error");
	else if (argc == 2)
		ft_printf("separar con split");
	else
		stack = fill_stack(argv);
	return (stack);
}