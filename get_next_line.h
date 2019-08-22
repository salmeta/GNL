/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:13:30 by salmeta           #+#    #+#             */
/*   Updated: 2019/08/17 13:52:21 by salmeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# define ENDL '\n'
# define END '\0'

# include <unistd.h>
#include <libft/libft.h>

# define BUFF_SIZE 32

int    get_next_line(const int fd, char **line);

#endif

