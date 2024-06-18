/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:17:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/18 13:29:12 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h" 
//# include "printf/ft_printf.h"

void	do_sa(t_list **stacka, int print);
void	do_sb(t_list **stackb, int print);
void	do_ss(t_list **stacka, t_list **stackb, int print);
void	do_pa(t_list **stacka, t_list **stackb, int print);
void	do_pb(t_list **stacka, t_list **stackb, int print);
void	do_ra(t_list **stacka, int print);
void	do_rb(t_list **stackb, int print);
void	do_rr(t_list **stacka, t_list **stackb, int print);
void	do_rra(t_list **stacka, int print);
void	do_rrb(t_list **stackb, int print);
void	do_rrr(t_list **stacka, t_list **stackb, int print);
t_list	*generate_stack(int argc, char *argv[]);
t_list	*fill_stack(char *argv[], int start);
void	print_stack(t_list **first);
void	free_stack(t_list **stack);
void	free_array(char **words);
int		is_sorted(t_list **stack);
void	fill_index(t_list **stack);
void	fill_position(t_list **stack);
void	update_stacks_positions(t_list **stacka, t_list **stackb);
void	two_args(t_list **stack);
void	three_args(t_list **stack);
int		is_duplicated(t_list *stack);
int		is_arg_integer(char *arg);
int		is_limits_integer(long number);
void	ft_print_error(void);
void	sort_stack(t_list **stacka);
void	calculate_cost(t_list **stacka, t_list **stackb);
int		cost_to_top(t_list **stack, int pos);
int		cost_to_pos(t_list	**stack, int ndx);
t_list	*choose_min_cost(t_list **stack);
t_list	*lst_min(t_list **stack);
t_list	*lst_max(t_list **stack);
int		ft_abs(int number);
int		ft_biggest(int num1, int num2);
void	sort_long_stack(t_list **stacka);
void	top(t_list	**s, t_list *e, void (*f)(t_list **, int),
			void (*u)(t_list **, int));
void	move_to_b(t_list **stacka, t_list **stackb, t_list *elem);
void	opposite_movs(t_list **stacka, t_list **stackb, int costa, int costb);
void	same_mov(t_list **stacka, t_list **stackb, int costa, int costb);

#endif