/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/06 20:44:36 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	char	**map;
	int	fd;

	fd = 0;
	map = NULL;
	if (av[2] && ac)
		return (1);
	if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1 || parse_file(fd, &map))
		{
			if (map)
				freedom("s", map);
			if (printf("Error 404: SUCK ME!"))
				return (0);
		}
		// printf("THIS\n");
		// int f = -1;
		// while (map[++f])
		// 	printf("%s\n", map[f]);
		make_window(map);
	}
	freedom("s", map);
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
	texture_init(vars);
	projection(vars);
	mlx_hook(vars->win, 2, 1L << 0, keys, vars);
	mlx_hook(vars->win, 17, 1L << 2, close_win, vars);
	mlx_loop(vars->mlx);
}

void	texture_init(t_vars *vars)
{
	int	i;
	char *textures[4];
	
	textures[0] = "./textures/North_Wall.xpm";
	textures[1] = "./textures/East_Wall.xpm";
	textures[2] = "./textures/South_Wall.xpm";
	textures[3] = "./textures/West_Wall.xpm";

	i = -1;
	vars->wall = (t_wall *)ft_calloc (sizeof(t_wall), 4);
	if (!vars->wall)
		exit (0);
	while (++i < 4)
	{
		vars->wall[i].img = mlx_xpm_file_to_image(vars->mlx, textures[i], &vars->wall[i].w, &vars->wall[i].h);
		if (vars->wall[i].img == NULL)
			exit(EXIT_FAILURE); // fix this shit
		vars->wall[i].img->addr = mlx_get_data_addr(vars->wall[i].img, &vars->wall[i].img->bpp, &vars->wall[i].img->len, &vars->wall[i].img->edn);	
	}
}

void data_init(t_vars *vars, char **map)
{
	vars->map = map;
	player_pos(0, 0, 0, vars);
	// vars->dir_x = 0;
	// vars->dir_y = -1;
	vars->dir_x = get_dir(vars->dir, 0);
	vars->dir_y = get_dir(vars->dir, 1);
	vars->roof = create_trgb(0, 0, 255, 255);
	vars->floor = create_trgb(0, 255, 0, 255);
	vars->plane_x = (0.66 * vars->dir_y) * 1;
	vars->plane_y = (0.66 * vars->dir_x) * 1;
	vars->time = 0;
	vars->old_time = 0;
}

// South = x -1, y 0 // maybe

int	parse_file(int fd, char ***file)
{
	*(file) = read_file(fd);
	if (check_walls(*(file)))
		return (1);
	*(file) = make_new_map(*(file), find_max_len(*(file)));
	int f = -1;
	while ((*file)[++f])
		printf("%s\n", (*file)[f]);
	if (parse_full(*(file)))
		return (1);
	return (0);
}

int	parse_full(char **file)
{
	int	f;

	f = -1;
	if (check_walls(file))
		return (1);
	while (file[++f])
		if (check_map(file[f], f))
			return (1);
	if (player_pos(0, -1, 0, NULL))
	{
		printf("FUCK\n");
		return (1);
	}
	return (0);
}

int	check_map(char *line, int row)
{
	int	f;
	static int	player;

	f = -1;
	while (line[++f])
	{
		if (line[f] != 48 && line[f] != 49)
		{
			if (line[f] != 'N' && line[f] != 'S' && line[f] != 'E' \
			&& line[f] != 'W')
				return (1);
			else
			{
				if (!player)
					player = player_pos(line[f], f, row, NULL);
				else
					return (1);
			}
		}
	}
	return (0);
}

int	player_pos(char dir, int pos_col, int pos_row, t_vars *vars)
{
	static char	one_dir;
	static int	col;
	static int	row;
	
	if (vars)
	{
		vars->pos_x = col;
		vars->pos_y = row;
		vars->dir = one_dir;
		return (0);
	}
	if (one_dir && pos_col == -1)
		return (0);
	if (!one_dir && dir && !vars)
		one_dir = dir;
	if (!col && pos_col && !vars)
		col = pos_col;
	if (!row &&pos_row && !vars)
		row = pos_row;
	return (1);
}

char	**read_file(int fd)
{
	char	*line;
	char	**file;

	// file = ft_calloc(sizeof(char **), 1);
	file = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (check_nl(line) && ft_strlen(line) > 1)
			line[ft_strlen(line) - 1] = '\0';
		if (file == NULL)
			file = ft_split(line, 1);
		else
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
	while (!check_maps_start(file[f]))
		f++;
	if (search_line(file[f], '1') || search_line(file[u - 1], '1'))
		return (1);
	while (file[f])
	{
		if ((file[f][0] != '1' && file[f][0] != 32) \
		|| (file[f][ft_strlen(file[f]) - 1] != '1' \
		&& file[f][ft_strlen(file[f]) - 1] != 32))
			return (1);
		f++;
	}
	return (0);
}

int	search_line(char *line, int c)
{
	int	f;

	f = -1;
	while (line[++f])
		if (line[f] != c && line[f] != 32)
			return (1);
	return (0);
}

//int	map_len() //need to return the maps len.
