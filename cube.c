/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:02:50 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	main(int ac, char **av)
{
	char	**map;
	char	**path;
	int		fd;

	fd = 0;
	map = NULL;
	path = NULL;
	if (av[2] && ac)
		return (ft_putendl_fd("Wrong number of arguments", 2));
	if (av[1])
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1 || parse_file(fd, &map, &path))
		{
			if (map && path)
				freedom("s", map, path);
			if (printf("Error 404: SUCK ME!"))
				return (0);
		}
		else
			make_window(map, path);
		close(fd);
	}
}

void	make_window(char **map, char **path)
{
	t_vars		*vars;
	t_img		img;

	vars = (t_vars *)malloc (sizeof(t_vars));
	if (!vars)
		exit (0);
	data_init(vars, map, path);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "CUB3D");
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.edn);
	vars->img = &img;
	if (texture_init(vars, path))
		return ;
	projection(vars);
	freedom("s", path);
	mlx_hook(vars->win, 2, 1L << 0, keys, vars);
	mlx_hook(vars->win, 17, 1L << 2, close_win, vars);
	mlx_loop(vars->mlx);
}

int	read_texture(t_vars *vars, char **file, char *dir, int order)
{
	int		f;
	char	**split;

	f = 0;
	f = 0;
	while (file[f] && ft_strncmp(file[f], dir, 1) != 0)
		f++;
	if (!file[f])
		return (1);
	split = ft_split(file[f], 32);
	ft_strlcpy(vars->txt[order], split[1], ft_strlen(split[1]) + 1);
	freedom("s", split);
	return (0);
}

int	texture_init(t_vars *vars, char **file)
{
	int	i;

	if (read_texture(vars, file, "NO", 0) \
	|| read_texture(vars, file, "EA", 1) \
	|| read_texture(vars, file, "SO", 2) \
	|| read_texture(vars, file, "WE", 3))
		return (1);
	i = -1;
	while (++i < 4)
	{
		vars->wall[i].img = mlx_xpm_file_to_image(vars->mlx, vars->txt[i], \
		&vars->wall[i].w, &vars->wall[i].h);
		if (vars->wall[i].img == NULL)
			exit(EXIT_FAILURE);
		vars->wall[i].addr = mlx_get_data_addr(vars->wall[i].img, \
		&vars->wall[i].bpp, &vars->wall[i].len, &vars->wall[i].edn);
	}
	return (0);
}

void	data_init(t_vars *vars, char **map, char **p)
{
	vars->map = map;
	player_pos(0, 0, 0, vars);
	vars->dir_x = get_dir(vars->dir, 0);
	vars->dir_y = get_dir(vars->dir, 1);
	vars->ceiling = create_trgb(0, ps(p, "C ", 0), ps(p, "C ", 1), \
	ps(p, "C ", 2));
	vars->floor = create_trgb(0, ps(p, "F ", 0), ps(p, "F ", 1), \
	ps(p, "F ", 2));
	if (vars->dir == 'N' || vars->dir == 'S')
	{
		vars->plane_x = (0.66 * vars->dir_y) * -1;
		vars->plane_y = (0.66 * vars->dir_x) * -1;
	}
	else
	{
		vars->plane_x = (0.66 * vars->dir_y) * 1;
		vars->plane_y = (0.66 * vars->dir_x) * 1;
	}
	vars->time = 0;
	vars->old_time = 0;
}

int	ps(char **file, char *dir, int check)
{
	char	**split;
	char	*line;
	int		res[3];

	line = get_colour_file(file, dir);
	if (!line)
	{
		freedom("sa", file);
		exit(1);
	}
	split = ft_split(line, ',');
	res[0] = ft_atoi(split[0]);
	res[1] = ft_atoi(split[1]);
	res[2] = ft_atoi(split[2]);
	freedom("sa", split, line);
	return (res[check]);
}

char	*get_colour_file(char **file, char *dir)
{
	int		f;
	char	**split;
	char	*res;

	f = 0;
	while (file[f] && ft_strncmp(file[f], dir, 2) != 0)
		f++;
	if (!file[f] && ft_strncmp("C ", dir, 2) == 0)
		return ("0,255,255");
	else if (!file[f] && ft_strncmp("F ", dir, 2) == 0)
		return ("255,0,255");
	split = ft_split(file[f], 32);
	res = ft_strdup(split[1]);
	freedom("s", split);
	return (res);
}

int	parse_file(int fd, char ***file, char ***path)
{
	*(path) = read_file(fd);
	if (check_walls(*(path)))
		return (1);
	*(file) = make_new_map(*(path), find_max_len(*(path)));
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
		return (1);
	return (0);
}

int	check_map(char *line, int row)
{
	int			f;
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

char	**read_file(int fd)
{
	char	*line;
	char	**file;

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
