/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:13:16 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/01/30 00:13:16 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

/*static void	del_content(void *content)
{
	free(content);
}*/

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}

/*int	main(void)
{
	char	*str = ft_strdup("Hola");
	t_list	*node;

	node = ft_lstnew(str);

	printf("ft_lstdelone:\n");
	printf("contenido de node = %s\n", (char *)node->content);
	if (node->next == NULL)
		printf("next de node es NULL\n");
	else
		printf("next de node distinto de NULL\n");
	ft_lstdelone(node, del_content);
	printf("despues de borrar:\n");
	printf("contenido de node = %s\n", (char *)node->content);
	return (0);
}*/
