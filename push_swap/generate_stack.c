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

/*It builds every node of the list and add them at the end of the list.
It cheks all the posible errors and free all if something is wrong. Return
the built list*/
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
		*number = str_to_int(argv[i]);
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

/*Build the stack with the list given as parameter. It takes into acount
 if the list is between quotes (it uses split) or not, and then it uses
 fill_stack. It returns the built stack*/
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
