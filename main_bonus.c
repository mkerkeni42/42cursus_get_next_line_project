/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:21:19 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/01/09 10:19:41 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	int		fd[1024];
	char	*str1;
	char	*str2;

	if (ac != 2)
	{
		printf("Wrong number of arguments !\n");
		return (-1);
	}
	i = 0;
	fd[0] = open("file.txt", O_RDONLY);
	fd[1] = open("rien.txt", O_RDONLY);
	if (fd[0] == -1 || fd[1] == -1)
		printf("open() failed\n");
	while (i++ < atoi(av[1]))
	{
		str1 = get_next_line(-1);
		str2 = get_next_line(fd[1]);
		printf("%s\n%s\n", str1, str2);
	}
	if (close(fd[0]) == -1 || close(fd[1]) == -1)
		printf("close() failed\n");
	return (0);
}
