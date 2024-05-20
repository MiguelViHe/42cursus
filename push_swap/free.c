/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:45:42 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/20 20:07:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_content(void *content)
{
	free(content);
}

void	free_stack(t_list **stack)
{
	ft_lstclear(stack, del_content);
}

void	free_array(char **words)
{
	char **temp = words;

    while (*words)
    {
        free(*words);
        words++;
    }
    free(temp);
}
