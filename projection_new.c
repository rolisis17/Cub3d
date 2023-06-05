/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:52:14 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/05 22:20:30 by mstiedl          ###   ########.fr       */
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
		// printf("HERE\n");
		ray->camera_x = 2 * x / (double)WIDTH - 1;
		ray->raydir_x = vars->dir_x + vars->plane_x * ray->camera_x;
		ray->raydir_y = vars->dir_y + vars->plane_y * ray->camera_x;
		ray->map_x = (int)vars->pos_x;
		ray->map_y = (int)vars->pos_y;
		ray->delta_x = my_ternery(ray->raydir_x, 0, 1e30, fabs(1 / ray->raydir_x));
		ray->delta_y = my_ternery(ray->raydir_y, 0, 1e30, fabs(1 / ray->raydir_y));
		step_n_side(ray, vars);
		dda_algo(ray, vars);
		ray->wall_h = (int)(HEIGHT / ray->wall_dist);
		ray->wall_s = -ray->wall_h / 2 + HEIGHT / 2;
		ray->wall_e = ray->wall_h / 2 + HEIGHT / 2;
		if (ray->wall_s < 0)
			ray->wall_s = 0;
		if (ray->wall_e > HEIGHT)
			ray->wall_e = HEIGHT;
		// printf("x= %i, wall start= %i, wall end= %i\n", (int)x, ray->wall_s, ray->wall_e);
		draw_line(ray, vars, x);
		ray->hit = 0;
	}
	free(ray);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
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

void dda_algo(t_pro *ray, t_vars *vars)
{
	while (ray->hit == 0)
	{
		if (ray->side_distx < ray->side_disty)
		{
			ray->side_distx += ray->delta_x;
			// printf("MAP X: %i, step %i\n", ray->map_x, ray->step_x);
			ray->map_x += ray->step_x;
			// printf("MAP X: %i, step %i\n", ray->map_x, ray->step_x);
			ray->side = 0;
		}
		else
		{
			ray->side_disty += ray->delta_y;
			// printf("MAP Y: %i, step %i\n", ray->map_y, ray->step_y);
			ray->map_y += ray->step_y;
			// printf("MAP Y: %i, step %i\n", ray->map_y, ray->step_y);
			ray->side = 1;
		}
		// printf("MAP :%s\n", vars->map[ray->map_y]);
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
	int i;

	i = -1;
	while (++i <= HEIGHT)
	{
		if (i >= ray->wall_s && i <= ray->wall_e)
		{
			// printf("PIXELS %i\n", i);
			pixel_put(vars->img, x, i, 0x009900FF);
		}
	}
}

void	pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y < 0 || y > HEIGHT)
		return ;
	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

double	my_ternery(double a, double b, double yes, double no)
{
	if (a == b)
		return (yes);
	else
		return (no);
}