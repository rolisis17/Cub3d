/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/03 19:33:43 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	char	**map;
	int	fd;

	fd = 0;
	if (av[2] && ac)
		return (1);
	if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1 || parse_file(fd, &map))
		{
			if (printf("Error 404: SUCK ME!"))
				return (0);
		}
		int f = -1;
		printf("THIS\n");
		while (map[++f])
			printf("%s\n", map[f]);
		make_window(map);
	}
}

void	make_window(char **map)
{
	t_vars		*vars;
	t_img		img;
	
	vars = (t_vars *)malloc (sizeof(t_vars));
	if (!vars)
		exit (0);
	data_init(vars, map);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "CUB3D");
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.edn);
	vars->img = &img;
	projection(vars);
	mlx_hook(vars->win, 2, 1L << 0, keys, vars);
	mlx_hook(vars->win, 17, 1L << 2, close_win, vars);
	mlx_loop(vars->mlx);
}

void data_init(t_vars *vars, char **map)
{
	vars->map = map;
	vars->dir_x = 0;
	vars->dir_y = 1;
	vars->plane_x = (0.66 * vars->dir_y) * 1;
	vars->plane_y = (0.66 * vars->dir_x) * 1;
	vars->pos_x = 5;
	vars->pos_y = 4;
	vars->time = 0;
	vars->old_time = 0;
}

// South = x -1, y 0 // maybe

int	parse_file(int fd, char ***file)
{
	char	**new;

	*(file) = read_file(fd);
	new = make_new_map(*(file), find_max_len(*(file)));
	int f = -1;
	while (new[++f])
		printf("%s\n", new[f]);
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
		file = add_split(file, line);
		free (line);
	}
	return (file);
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

//int	check_player() //need to check where is the player and if it is "N", "S", "W" or "O";
//int	map_len() //need to return the maps len.
