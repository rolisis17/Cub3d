/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:52:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/08 16:02:49 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	projection(t_vars *vars)
{
	int		x;
	t_pro	*ray;

	x = -1;
	ray = (t_pro *)malloc (sizeof(t_pro));
	if (!ray)
		exit (EXIT_FAILURE);
	while (++x < WIDTH)
	{
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		ray->raydir_x = vars->dir_x + vars->plane_x * ray->camera_x;
		ray->raydir_y = vars->dir_y + vars->plane_y * ray->camera_x;
		ray->map_x = (int)vars->pos_x;
		ray->map_y = (int)vars->pos_y;
		ray->delta_x = my_ternery(ray->raydir_x, 0, 1e30, \
		fabs(1 / ray->raydir_x));
		ray->delta_y = my_ternery(ray->raydir_y, 0, 1e30, \
		fabs(1 / ray->raydir_y));
		step_n_side(ray, vars);
		dda_algo(ray, vars);
		wall_calc(ray);
		draw_line(ray, vars, x);
	}
	free(ray);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	wall_calc(t_pro *ray)
{
	ray->wall_h = (int)(HEIGHT / ray->wall_dist);
	ray->wall_s = -ray->wall_h / 2 + HEIGHT / 2;
	ray->wall_e = ray->wall_h / 2 + HEIGHT / 2;
	if (ray->wall_s < 0)
		ray->wall_s = 0;
	if (ray->wall_e > HEIGHT)
		ray->wall_e = HEIGHT;
}

void	step_n_side(t_pro *ray, t_vars *vars)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->side_distx = (vars->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_distx = (ray->map_x + 1.0 - vars->pos_x) * ray->delta_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_disty = (vars->pos_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_disty = (ray->map_y + 1.0 - vars->pos_y) * ray->delta_y;
	}
}

void	dda_algo(t_pro *ray, t_vars *vars)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (vars->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->wall_dist = ray->side_distx - ray->delta_x;
	else
		ray->wall_dist = ray->side_disty - ray->delta_y;
}

void	draw_line(t_pro *ray, t_vars *vars, int x)
{
	int		i;
	int		f;
	double	step;

	i = -1;
	f = get_face(ray);
	texture_calc(ray, vars, f);
	step = 1.0 * vars->wall[f].h / ray->wall_h;
	vars->wall[f].pos = (ray->wall_s - HEIGHT / 2 + ray->wall_h / 2) * step;
	while (++i <= HEIGHT)
	{
		if (i >= ray->wall_s && i <= ray->wall_e)
		{
			vars->wall[f].tex_y = (int)vars->wall[f].pos;
			vars->wall[f].pos += step;
			pixel_put(vars->img, x, i, get_colour(vars, f));
		}
		else if (i < HEIGHT / 2 && i < ray->wall_s)
			pixel_put(vars->img, x, i, vars->ceiling);
		else if (i < HEIGHT && i > ray->wall_e)
			pixel_put(vars->img, x, i, vars->floor);
	}
}
