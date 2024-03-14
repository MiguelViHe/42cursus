/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:39:10 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/14 13:46:10 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h> //malloc
# include <unistd.h> //files
# include <fcntl.h>  //O_RDONLY
# include <stddef.h> //size_t

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		is_eol(char	*str);

#endif