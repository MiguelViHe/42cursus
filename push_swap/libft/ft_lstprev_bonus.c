/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:54:33 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/27 12:51:43 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstprev(t_list *lst, t_list *find_prev)
{
	t_list	*current;

	if (lst == NULL || find_prev == NULL)
		return (NULL);
	current = lst;
	while (current)
	{
		if (current->next == find_prev)
			return (current);
		current = current->next;
	}
	return (NULL);
}
