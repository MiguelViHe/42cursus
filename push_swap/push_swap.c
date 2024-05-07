/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:03:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/07 20:09:20 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	print_stack(t_list **first)
{
	t_list	*aux;

	if (first != NULL)
	{
		aux = *first;
		while (aux)
		{
			ft_printf("%d -> ", *(int *)aux->content);
			aux = aux->next;
		}
	}
	ft_printf("NULL\n");
}

t_list	*fill_stack(char *argv[]) //LIBERAR TODO CUANDO FALLA MALLOC
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
			return (NULL);
		*number = ft_atoi(argv[i]);
		new = ft_lstnew(number);
		if (!new)
			return (NULL);
		ft_lstadd_back(&stack, new);
		i++;
	}
	return (stack);
}

/*int	main(int argc, char *argv[])
{
	t_list	**stka = NULL;
	t_list	**stkb = NULL;
	int		k = 37;
	int		j = 4;
	int		i = 8;
	int		x = 1;
	int		y = 2;
	int		z = 3;
	t_list	*anode;
	t_list	*bnode = NULL;

	ft_printf("%s\n", argv[1]);

	anode = ft_lstnew(&k);
	stka = &anode;
	stkb = &bnode;
	ft_lstadd_back(stka, ft_lstnew(&j));
	ft_lstadd_back(stka, ft_lstnew(&i));
	ft_lstadd_back(stka, ft_lstnew(&x));
	ft_lstadd_back(stka, ft_lstnew(&y));
	ft_lstadd_back(stka, ft_lstnew(&z));
	//ft_printf("%d\n", *(int *)anode1->content);
	//ft_printf("%d\n", *(int *)bnode3->content);
	if (argc < 2)
		return (-1);
	//stka = fill_stack(argv);
	//stkb = fill_stack(argv);
	print_stack(stka);
	print_stack(stkb);
	push(stka, stkb);
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	print_stack(stka);
	print_stack(stkb);
	rotate(stka);
	print_stack(stka);
	print_stack(stkb);
	push(stka,stkb);
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	reverse(stkb);
	print_stack(stka);
	print_stack(stkb);
	return (0);
}*/

int	main(int argc, char *argv[])
{
	t_list	**stka;
	t_list	**stkb;

	if (argc < 2)
		return (-1);
	stka = (t_list **)malloc(sizeof(t_list *));
	stkb = (t_list **)malloc(sizeof(t_list *));
	*stka = fill_stack(argv);
	*stkb = NULL;
	print_stack(stka);
	print_stack(stkb);
	push(stka, stkb);
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	print_stack(stka);
	print_stack(stkb);
	rotate(stka);
	print_stack(stka);
	print_stack(stkb);
	push(stka, stkb);
	print_stack(stka);
	print_stack(stkb);
	swap(stka);
	reverse(stkb);
	print_stack(stka);
	print_stack(stkb);
	return (0);
}
