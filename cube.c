/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:41:00 by dcella-d         ###   ########.fr       */
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
			if (ft_putendl_fd("Error 404: Question map?", 2))
				return (1);
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
