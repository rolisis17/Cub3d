/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/05/31 21:33:17 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	int	fd;

	fd = 0;
	if (av[2] && ac)
		return (1);
	if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1 || parse_file(fd))
			return (0);
		printf("seu cu");
	}
}

int	parse_file(int fd)
{
	char	**file;

	file = read_file(fd);
	if (check_walls(file))
		return (1);
	return (0);
}

char	**read_file(int fd)
{
	char	*line;
	char	**file;

	file = ft_calloc(sizeof(char **), 1);
	file[0] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		file = add_split(file, line);
		free (line);
	}
	return (file);
}

int	check_walls(char **file)
{
	int	f;
	int	u;

	f = -1;
	u = filelen(file);
	while (file[0][++f] && file[u][f])
	{
		if (file[0][f] != '1' || file[u][f] != '1')
			return (1);
	}
	f = -1;
	while (file[++f])
	{
		if (file[f][0] != '1' || file[f][ft_strlen(file[f])] != '1')
			return (1);
	}
	return (0);
}

int	filelen(char **file)
{
	int	f;

	f = -1;
	while (file[++f])
		printf("%s", file[f]);
	return (f);
}