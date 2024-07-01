/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/27 12:54:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Free the content of a node of the stack*/
static void	del_content(void *content)
{
	free(content);
}

/*Free the stack freeing also the content*/
void	free_stack(t_list **stack)
{
	ft_lstclear(stack, del_content);
}

/*Free the array created for split, when the list of numbers is between
 quotes*/
void	free_array(char **words)
{
	char	**temp;

	temp = words;
	while (*words)
	{
		free(*words);
		words++;
	}
	free(temp);
}
