/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:03:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/01 19:10:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	print_stack(t_list* first)
{
	t_list	*aux;

	aux = first;
	while (aux)
	{
		ft_printf("%d->", *(int *)aux->content);
		aux = aux->next;
	}
	ft_printf("NULL\n");
}

t_list	**fill_stack(char *argv[])
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
	
	if (argc < 2)
		return (-1);
	stka = fill_stack(argv);
	print_stack(*stka);
	return (0);
}