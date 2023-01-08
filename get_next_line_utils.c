/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:38:50 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/01/08 12:09:25 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*return_empty(char *str)
{
	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	*str = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	s_len;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = NULL;
	s_len = ft_strlen(s);
	i = 0;
	if (start > s_len)
		return (return_empty(str));
	if (len <= s_len)
		str = malloc(sizeof(char) * (len + 1));
	else
		str = malloc(sizeof(char) * (s_len - start));
	if (!str)
		return (NULL);
	while (s[start] && start < s_len && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[i + dest_len] = src[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2, int x)
{
	char	*str_final;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str_final = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_final)
		return (NULL);
	else
	{
		ft_strcpy(str_final, s1);
		/*while (s2[i] != '\0')
		{
			str_final[i + ft_strlen(str_final)] = s2[i];
			i++;
		}
		str_final[i + ft_strlen(str_final)] = '\0';
		printf("str_final dans strjoin: %s\n", str_final);*/
		ft_strcat(str_final, s2);
	}
	free (s1);
	if (x == 1)
		free (s2);
	return (str_final);
}
