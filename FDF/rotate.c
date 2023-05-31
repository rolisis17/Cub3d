/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:51:45 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 19:13:59 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotatelistmid(t_vars *vars)
{
	t_dotfile		*headx;
	t_dotfile		*heady;
	static double	x_rot;
	static double	y_rot;

	heady = vars->file;
	headx = heady;
	while (heady)
	{
		x_rot = ((headx->x - vars->calc.cx) * cos(vars->calc.th * \
		vars->calc.dgm) - (headx->y - vars->calc.cy) * \
		sin(vars->calc.th * vars->calc.dgm) + vars->calc.cx);
		y_rot = ((headx->y - vars->calc.cy) * cos(vars->calc.th * \
		vars->calc.dgm) + (headx->x - vars->calc.cx) * sin(vars->calc.th * \
		vars->calc.dgm) + vars->calc.cy);
		headx->x = x_rot;
		headx->y = y_rot;
		next_dot_node(&heady, &headx);
	}
}

void	rotatelisty(t_vars *vars)
{
	t_dotfile			*headx;
	t_dotfile			*heady;
	t_calc				ca;
	static double		y_rot;

	ca = vars->calc;
	heady = vars->file;
	headx = heady;
	while (heady)
	{
		y_rot = (((headx->y - ca.cy) * cos(ca.th * ca.dgy)) + ca.cy);
		headx->y = (y_rot - ca.cy) - (ca.size * headx->dot * \
		ca.dgy / 90) + ca.cy;
		next_dot_node(&heady, &headx);
	}
}

double	findradius(t_line line)
{
	static double	radius;

	radius = sqrt((line.x2 - line.x1) * (line.x2 - line.x1) \
	+ (line.y2 - line.y1) * (line.y2 - line.y1));
	return (radius);
}

void	rotate_all(t_vars *vars)
{
	put_coords(&vars->file, vars->calc);
	rotatelistmid(vars);
	rotatelisty(vars);
}
