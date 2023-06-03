/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:32:23 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/03 13:45:58 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	projection(t_vars *vars)
{
	int		x;
	float	ray_angle;
	
	x = -1;
	while (++x < WIDTH)
	{
		ray_angle = vars->data->plane_x - atan2(x - WIDTH / 2, WIDTH / 2);
		while (ray_angle < 0)
			ray_angle += 2 * M_PI;
		while (ray_angle >= 2 * M_PI)
			ray_angle -= 2 * M_PI;
		raycast(ray_angle, vars);
	}
}

void	raycast(float ray_angle, t_vars *vars)
{
	t_ray *ray;
	
	ray = (t_ray *)malloc (sizeof(t_ray));
	if (!ray)
		exit (EXIT_FAILURE);
	ray->hit = 0;
	ray->ray_x = vars->data->pos_x;
	ray->ray_y = vars->data->pos_y;
	ray->raydir_x = cos(ray_angle);
	ray->raydir_y = sin(ray_angle);
	while (!ray->hit)
	{
		ray->ray_x += ray->raydir_x;
		ray->ray_y += ray->raydir_y;
		printf("HERE\nvalue x:%i\nvalue y:%i\n", (int)ray->ray_x, (int)ray->ray_y);
		if (ray->ray_x < 0 || ray->ray_x >= vars->data->map_w || ray->ray_y < 0 || ray->ray_y >= vars->data->map_h)
		{
			ray->hit = 1;
			ray->distance = 1000.0;
		}
		else if (vars->map[(int)ray->ray_x][(int)ray->ray_y] == '1') // not working because dont have a map.
		{
			ray->hit = 1;
			ray->distance = sqrt((ray->ray_x - vars->data->pos_x) * (ray->ray_x - vars->data->pos_x) + \
			(ray->ray_y - vars->data->pos_y) * (ray->ray_y - vars->data->pos_y));
		}
	}
	draw_wall(ray->distance, vars, ray->ray_x);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

void	draw_wall(float distance, t_vars *vars, float x)
{
	t_wall *wall;

	wall = (t_wall *)malloc (sizeof(t_wall));
	if (!wall)
		exit (EXIT_FAILURE);
	wall->wall_h = (int)(HEIGHT / distance);
	wall->wall_s = -wall->wall_h / 2 + HEIGHT / 2;
	wall->wall_e = wall->wall_h / 2 + HEIGHT / 2;
	if (wall->wall_s < 0)
		wall->wall_s = 0;
	if (wall->wall_e >= HEIGHT)
		wall->wall_e = HEIGHT -1;
	printf("x= %i, wall start= %i, wall end= %i\n", (int)x, wall->wall_s, wall->wall_e);
	draw_line(vars->img, x, wall->wall_s, wall->wall_e);
	
}

void	draw_line(t_img *img, float x, int start, int end)
{
	int i;

	i = -1;
	while (++i < HEIGHT)
	{
		if (i >= start && i <= end)
			pixel_put(img, x, i, 0x00FFFC00);
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

int	my_ternery(int a, int b, int yes, int no)
{
	if (a > b)
		return (yes);
	else
		return (no);
}