/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/02 16:25:25 by mstiedl          ###   ########.fr       */
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
		// if (fd == -1 || parse_file(fd))
		// 	return (0);
		make_window();
		printf("seu cu");
	}
}

void	make_window(void)
{
	t_vars		*vars;
	t_img		img;
	
	vars = (t_vars *)malloc (sizeof(t_vars));
	if (!vars)
		exit (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "CUB3D");
	img.img = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.edn);
	vars->img = &img;
	data_init(vars);
	projection(vars);
	mlx_hook(vars->win, 2, 1L << 0, keys, vars);
	mlx_hook(vars->win, 17, 1L << 2, close_win, vars);
	mlx_loop(vars->mlx);
}

void	data_init(t_vars *vars)
{
	vars->data = (t_pro *)malloc (sizeof(t_pro));
	if (!vars->data)
		exit(EXIT_FAILURE);
	vars->data->pos_x = 5.0; //get_pos(); //dracsis making, put together
	vars->data->pos_y = 4.0; //get_pos(); //dracsis making, put together
	vars->data->dir_x = 0.0; //get_dir();
	vars->data->dir_y = 0.0; //get_dir(); // make based on NESW
	vars->data->map_w = 6; ///get_mapsize();
	vars->data->map_h = 5; //get_mapsize();
	vars->data->plane_x = 0.0;
	vars->data->plane_y = 0.66;
	// vars->data->time = 0;
	// vars->data->old_time = 0;
	// vars->data->distance 0.0;
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