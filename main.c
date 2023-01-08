/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:49:08 by mkerkeni          #+#    #+#             */
/*   Updated: 2023/01/08 12:52:48 by mkerkeni         ###   ########.fr       */
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
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("open() failed\n");
		return (0);
	}
	while (i < atoi(av[1]))
	{
		printf("\n**************** appel %d **************\n\n", i);
		str = get_next_line(fd);
		printf("%s", str);
		i++;
	}
	close(fd);
	if (close(fd) == -1)
		printf("close() failed\n");
	//system("leaks a.out");
	return (0);
}
