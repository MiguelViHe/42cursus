/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:22:13 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/06/14 12:55:28 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	t_list	*stka;

	if (argc > 1)
	{
		stka = generate_stack(argc, argv);
		if (!stka || is_duplicated(stka))
			ft_print_error();
	}
}