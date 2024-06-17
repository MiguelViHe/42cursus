/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:03:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/17 13:21:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

int	main(int argc, char *argv[])
{
	t_list	*stka;

	if (argc > 1)
	{
		stka = generate_stack(argc, argv);
		if (!stka || is_duplicated(stka))
			ft_print_error();
		else if (!is_sorted(&stka))
		{
			sort_stack(&stka);
			free_stack(&stka);
		}
	}
}
