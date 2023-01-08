/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:31:43 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/01/08 12:33:38 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	size_t	s_len;

	i = 0;
	ptr = (char *)s;
	s_len = ft_strlen(s);
	while (ptr[i])
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i++;
	}
	if (c == '\0')
		return (ptr + s_len);
	return (0);
}

static int	get_index(char *str, char *ptr)
{
	int	i;

	i = 0;
	while (str[i] != *ptr)
		i++;
	return (i);
}

static char	*trim_buf(char	*buf, char *final, char *str)
{
	int		i;
	char	*after_nl;
	char	*before_nl;

	i = get_index(buf, ft_strchr(buf, '\n'));
	before_nl = ft_substr(buf, 0, i + 1);
	after_nl = ft_substr(buf, i + 1, ft_strlen(buf) - i);
	final = ft_strjoin(final, before_nl, 1);
	ft_strcpy(str, after_nl);
	free(after_nl);
	return (final);
}

static char	*trim_str(char *str, char *final)
{
	int		i;
	char	*after_nl;
	char	*before_nl;

	i = get_index(str, ft_strchr(str, '\n'));
	before_nl = ft_substr(str, 0, i + 1);
	after_nl = ft_substr(str, i + 1, ft_strlen(str) - i);
	final = ft_strjoin(final, before_nl, 1);
	ft_strcpy(str, after_nl);
	free(after_nl);
	return (final);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	str[BUFFER_SIZE + 1];
	char		*final;

	ret = 1;
	buf[0] = '\0';
	final = malloc(sizeof(char));
	final[0] = '\0';
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(final);
		return (0);
	}
	if (ft_strchr(str, '\n') != 0 && *str)
	{
		final = trim_str(str, final);
		return (final);
	}
	else
		final = ft_strjoin(final, str, 0);
	while (ret != 0 && ft_strchr(buf, '\n') == 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			str[0] = '\0';
			free(final);
			return (0);
		}
		buf[ret] = '\0';
		if (ft_strchr(buf, '\n') != 0)
		{
			final = trim_buf(buf, final, str);
			break ;
		}
		else
			final = ft_strjoin(final, buf, 0);
	}
	if (ret == 0 && strlen(final) == 0)
	{
		free(final);
		final = NULL;
	}
	else if (ret == 0 && ft_strchr(str, '\n') == 0)
		str[0] = '\0';
	return (final);
}
