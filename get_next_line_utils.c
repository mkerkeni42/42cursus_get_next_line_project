/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:38:50 by mkerkeni          #+#    #+#             */
/*   Updated: 2022/12/18 18:03:26 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

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
		return (0);
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

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize == 0 || dst_len >= dstsize)
		return (src_len + dstsize);
	while (src[i] && i < dstsize - 1 - dst_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*str_final;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!str1 || !str2)
		return (NULL);
	str_final = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_final)
		return (NULL);
	else
	{
		ft_strcpy(str_final, str1);
		ft_strcat(str_final, str2);
	}
	return (str_final);
}
