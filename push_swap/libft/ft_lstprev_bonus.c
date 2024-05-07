/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprev_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:54:33 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/07 20:12:29 by mvidal-h         ###   ########.fr       */
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
			return (current); //Puede ser NULL si el nodo buscado es el primero.
		current = current->next;
	}
	return (NULL); // Si no se encuentra el nodo previo
}
