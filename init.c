/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:11:27 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/16 15:55:32 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	texture_init(t_vars **vars, char **file)
{
	int	i;

	if (read_texture((*vars), file, "NO", 0) \
	|| read_texture((*vars), file, "EA", 1) \
	|| read_texture((*vars), file, "SO", 2) \
	|| read_texture((*vars), file, "WE", 3))
		return (1);
	(*vars)->mlx = mlx_init();
	i = -1;
	while (++i < 4)
	{
		(*vars)->wall[i].img = mlx_xpm_file_to_image((*vars)->mlx, \
		(*vars)->txt[i], &(*vars)->wall[i].w, &(*vars)->wall[i].h);
		if ((*vars)->wall[i].img == NULL)
			texture_error((*vars), file, i);
		(*vars)->wall[i].addr = mlx_get_data_addr((*vars)->wall[i].img, \
		&(*vars)->wall[i].bpp, &(*vars)->wall[i].len, &(*vars)->wall[i].edn);
	}
	return (0);
}

void	data_init(t_vars *vars, char **map, char **p)
{
	vars->map = map;
	player_pos(0, 0, 0, vars);
	vars->dir_x = get_dir(vars->dir, 0);
	vars->dir_y = get_dir(vars->dir, 1);
	vars->ceiling = create_trgb(0, ps(p, "C ", 0, vars), ps(p, "C ", 1, vars), \
	ps(p, "C ", 2, vars));
	vars->floor = create_trgb(0, ps(p, "F ", 0, vars), ps(p, "F ", 1, vars), \
	ps(p, "F ", 2, vars));
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

void	texture_error(t_vars *vars, char **file, int i)
{
	while (i >= 0)
	{
		if (vars->wall[i].img)
			mlx_destroy_image(vars->mlx, vars->wall[i].img);
		i--;
	}
	mlx_destroy_display(vars->mlx);
	freedom_exit_error("Error 666:TextureError|ssaa", file, \
vars->map, vars->mlx, vars);
}
