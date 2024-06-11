/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 13:16:34 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/11 10:39:23 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

t_list	*fill_stack(char *argv[], int start)
{
	int		i;
	long	*number;
	t_list	*stack;
	t_list	*new;

	stack = NULL;
	i = start;
	while (argv[i])
	{
		if (!is_arg_integer(argv[i]))
			return (free_stack(&stack), NULL);
		number = (long *)malloc(sizeof(long));
		if (!number)
			return (free_stack(&stack), NULL);
		*number = ft_atol(argv[i]);
		if (!is_limits_integer(*number))
			return (free(number), free_stack(&stack), NULL);
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
	char	**result;

	stack = NULL;
	if (argc == 2)
	{
		result = ft_split(argv[1], ' ');
		stack = fill_stack(result, 0);
		free_array(result);
	}
	else
		stack = fill_stack(argv, 1);
	return (stack);
}
