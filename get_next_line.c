/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmeta <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 22:45:31 by salmeta           #+#    #+#             */
/*   Updated: 2019/09/19 22:45:33 by salmeta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_end_of_doc(char **line, char **str, int res, char **buf)
{
	if (!res && **str)
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
		return (1);
	}
	ft_strdel(str);
	ft_strdel(buf);
	return ((res > 0) ? 1 : res);
}

static char	*gnl_strndup(const char *s1, size_t n)
{
	size_t  i;
	char	*s2;

	i = 0;
	if (!(s2 = (char*)malloc(n + 1)))
		return (NULL);
	while (s1 && s1[i] && i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	while (i <= n)
		s2[i++] = '\0';
	return (s2);
}

static char	*gnl_strnjoin(char **s1, char const *s2)
{
	int		sum;
	char	*str;

	if (*s1 == 0 || s2 == 0)
		return (NULL);
	sum = ft_strlen(*s1) + ft_strlen(s2);
	if (!(str = ft_memalloc(sum + 1)))
		return (NULL);
	ft_strcpy(str, *s1);
	ft_strdel(s1);
	return (ft_strcat(str, s2));
}

static char	*gnl_strchr(const char *s1, int c)
{
	int i;
	int j = 0;
	char *s2 = NULL;

	i = 0;
	while (s1[i] && s1[i] != c)
		i++;
	if (s1[i] == c)
	{
		s2 = (char*)malloc(ft_strlen(&s1[i]) + 1);
		while (s1[i])
			s2[j++] = s1[i++];
		s2[j] = '\0';
		return s2;
		//return ((char *) &s1[i]);
	}
	return (NULL);
}

int	get_next_line(const int fd, char **line)
{
	int			res;
	char		*buf;
	char        *tmp;
	static char	*str = NULL;

	if (fd < 0 || !line || BUFF_SIZE < 1 || (!(buf = ft_strnew(BUFF_SIZE))))
		return (-1);
	if (!str)
		str = ft_memalloc(BUFF_SIZE);
	while (!(tmp = gnl_strchr(str, '\n'))) //(!(tmp = ft_strchr(str, '\n')))
	{
		if ((res = read(fd, buf, BUFF_SIZE)) < 1)
			return (check_end_of_doc(line, &str, res, &buf));
		buf[res] = '\0';
		if (!(str = gnl_strnjoin(&str, buf)))
			return (-1);
	}
	*line = gnl_strndup(str, tmp - str);

	//ft_strncpy(str, tmp + 1, BUFF_SIZE); утечек нет, есть ошибки в тестах
	str = gnl_strndup(tmp + 1, BUFF_SIZE);
	ft_strdel(&buf);
	ft_strdel(&tmp);
	return (1);
}