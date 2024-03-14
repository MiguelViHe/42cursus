/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:14:13 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/03/12 20:05:46 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
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
