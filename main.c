/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:49:08 by mkerkeni          #+#    #+#             */
/*   Updated: 2022/12/18 19:08:28 by mkerkeni         ###   ########.fr       */
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
		printf("open() failed\n");
	while (i < atoi(av[1]))
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
	close(fd);
	
	return (0);
}