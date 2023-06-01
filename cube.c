/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/01 21:11:12 by dcella-d         ###   ########.fr       */
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
		make_window();
		// projection();
		printf("seu cu");
	}
}

// void	projection(void)
// {
	
// }

void	make_window(void)
{
	t_vars		*vars;
	
	vars = (t_vars *)malloc (sizeof(t_vars));
	if (!vars)
		exit (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, \
	HEIGHT, "CUB3D");
	mlx_hook(vars->win, 2, 1L << 0, keys, vars);
	mlx_hook(vars->win, 17, 1L << 2, close_win, vars);
	mlx_loop(vars->mlx);
}

int	parse_file(int fd)
{
	char	**file;
	char	**new;

	file = read_file(fd);
	new = make_new_map(file, find_max_len(file));
	// int f = -1;
	// while (new[++f])
	// 	printf("%s\n", new[f]);
	printf("%d\n", word_count(new));
	if (check_walls(new))
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
		if (check_nl(line))
			line[ft_strlen(line) - 1] = '\0';
		printf("%d\n", ft_strlen(line));
		file = add_split(file, line);
		free (line);
	}
	return (file);
}

char	**make_new_map(char **file, int max_len)
{
	char	**new;
	char	*line;
	int		f;

	f = -1;
	new = ft_calloc(sizeof(char **), 1);
	new[0] = NULL;
	while (file[++f])
	{
		line = make_new_line(file[f], max_len);
		printf("%s\n", line);
		if (new[0] == NULL)
			new[0] = line;
		else
			new = add_split(new, line);
		// if (word_count(new) > 1)
	}
	f = -1;
	// while (new[++f])
	// 	printf("%s\n", new[f]);
	return (new);
}

int	find_max_len(char **file)
{
	int	max_len;
	int	f;

	f = -1;
	while (file[++f])
		if (ft_strlen(file[f]) > max_len)//printf("%d\n", ft_strlen(file[f])) && 
			max_len = ft_strlen(file[f]);
	return (max_len);
}

char	*make_new_line(char *line, int max_len)
{
	char		*res;
	int			f;

	f = -1;
	res = NULL;
	// printf ("%d\n%d,\n", ft_strlen(line), max_len);
	printf("%s\n", line);
	while (line[++f])
	{
		// printf("%c", line[f]);
		if (line[f] == 32)
			line[f] = 49;
	}
	// printf("%s\n", line);
	if (ft_strlen(line) < max_len)
	{
		res = strpp(line, max_len, 49);
		return (res);
	}
	return (line);
	// free (line);
}

char	*strpp(char *line, int len, int c)
{
	char *res;
	int	f;

	f = ft_strlen(line);
	if (f < len)
	{
		res = ft_calloc(len + 1, 1);
		ft_strlcpy(res, line, f + 1);
		while (res[++f])
			res[f] = c;
		res[f] = '\0';
		return (res);
	}
	return (line);
}

int	check_nl(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		return (1);
	return (0);
}

int	check_walls(char **file)
{
	int	f;
	int	u;

	f = 0;
	u = word_count(file);
	if (search_line(file[0], '1') || search_line(file[u - 1], '1'))
		return (1);
	while (file[++f + 1])
	{
		if (file[f][0] != '1' || file[f][ft_strlen(file[f]) - 1] != '1')
			return (1);
	}
	return (0);
}

int	search_line(char *line, int c)
{
	int	f;

	f = -1;
	while (line[++f])
		if (line[f] != c)
			return (1);
	return (0);
}