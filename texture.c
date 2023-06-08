/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:02:38 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/08 16:03:13 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	texture_calc(t_pro *ray, t_vars *vars, int f)
{
	if (ray->side == 0)
		vars->wall[f].x = vars->pos_y + ray->wall_dist * ray->raydir_y;
	else
		vars->wall[f].x = vars->pos_x + ray->wall_dist * ray->raydir_x;
	vars->wall[f].x -= floor(vars->wall[f].x);
	vars->wall[f].tex_x = (int)(vars->wall[f].x * (double)vars->wall[f].w);
	if (ray->side == 0 && ray->raydir_x > 0)
		vars->wall[f].tex_x = vars->wall[f].w - vars->wall[f].tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		vars->wall[f].tex_x = vars->wall[f].w - vars->wall[f].tex_x - 1;
}