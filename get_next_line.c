/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:31:43 by mkerkeni          #+#    #+#             */
/*   Updated: 2022/12/22 17:58:15 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_index(char *str, char *ptr)
{
	int	i;

	i = 0;
	while (str[i] != *ptr)
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	static char	str;
	int			i;
	int			j;
	char		*final;

	i = 0;
	j = 0;
	//printf("contenu de str au debut du 2eme appel de fonction: %s\n", str);
	if (!str)
		str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	ret = read(fd, buf, BUFFER_SIZE);
	if (ret == 0)
		return (NULL);
	buf[ret] = '\0';
	final = malloc(sizeof(char) * BUFFER_SIZE + 1);
	//printf("contenu de str avant 2eme copie: %s\n", str);
	ft_strlcat(str, buf, BUFFER_SIZE + 1);
	//printf("Contenu de str apres copie de buf: %s\n\n", str);
	ft_strcpy(final, str);
	while (ft_strchr(str, '\n') == 0 && *str)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			return (NULL);
		buf[ret] = '\0';
		ft_strcpy(str, buf);
		if (ft_strchr(str, '\n') != 0)
		{
			j = get_index(str, ft_strchr(str, '\n'));
			final = ft_strjoin(final, ft_substr(str, 0, j+1));
			str = ft_substr(str, j+1, ft_strlen(str) - j);
			break;
		}
		final = ft_strjoin(final, str);
	}
	return (final);
}
