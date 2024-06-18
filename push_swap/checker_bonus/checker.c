/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:22:13 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:27:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_rr(t_list **stka, t_list **stkb, char *line)
{
	if (line[2] == 'a')
		do_rra(stka, 0);
	else if (line[2] == 'b')
		do_rrb(stkb, 0);
	else if (line[2] == 'r')
		do_rrr(stka, stkb, 0);
}

static void	check_instruction(t_list **stka, t_list **stkb, char *line)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		do_ra(stka, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		do_rb(stkb, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		check_rr(stka, stkb, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		do_rr(stka, stkb, 0);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		do_pa(stka, stkb, 0);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		do_pb(stka, stkb, 0);
	else if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		do_sa(stka, 0);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		do_sb(stkb, 0);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		do_ss(stka, stkb, 0);
	else
	{
		free (line);
		ft_print_error();
	}
}

static void	check_stack(t_list **stka, t_list **stkb, char *line)
{
	while (line && *line != '\n')
	{
		check_instruction(stka, stkb, line);
		free(line);
		line = get_next_line(0);
	}
	if (*stkb)
		ft_printf("KO\n");
	else if (!is_sorted(stka))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main(int argc, char *argv[])
{
	t_list	*stka;
	t_list	*stkb;
	char	*line;

	if (argc > 1)
	{
		stkb = NULL;
		stka = generate_stack(argc, argv);
		if (!stka || is_duplicated(stka))
			ft_print_error();
		line = get_next_line(0);
		if (!line && !is_sorted(&stka))
			ft_printf("KO\n");
		else if (!line && is_sorted(&stka))
			ft_printf("OK\n");
		else
			check_stack(&stka, &stkb, line);
		free_stack(&stka);
		free_stack(&stkb);
		return (0);
	}
}
