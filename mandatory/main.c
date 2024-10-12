/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:49:08 by mkerkeni          #+#    #+#             */
/*   Updated: 2024/10/12 21:06:48 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*str;

	if (ac != 2)
	{
		printf("Wrong number of arguments !\n");
		return (-1);
	}
	i = 0;
	fd = open("../file1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	while (i++ < atoi(av[1]))
	{
		printf("\n**************** appel %d **************\n\n", i);
		str = get_next_line(fd);
		printf("%s", str);
	}
	if (close(fd) == -1)
		printf("close() failed\n");
	return (0);
}
