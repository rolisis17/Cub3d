/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:34:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/03 15:47:49 by dcella-d         ###   ########.fr       */
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
	vars->map = map;
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
