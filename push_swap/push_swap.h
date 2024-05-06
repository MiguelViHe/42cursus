/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:17:04 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/05/06 18:16:27 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h" 
# include "printf/ft_printf.h"

void swap(t_list **stack);
void rotate(t_list **stack);
void reverse(t_list **stack);
void push(t_list **stackx, t_list **stacky);
void print_stack(t_list **first);

#endif