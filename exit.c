/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:05:43 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/06 15:59:57 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_win(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	// close (vars->fd);
	free(vars);
	exit (0);
}

int	keys(int keycode, t_vars *vars)
{
	if (keycode == W)
		move_player(vars);
	// else if (keycode == A)
	// 	vars->calc.dgy--;
	// else if (keycode == S)
	// 	vars->calc.dgm++;
	// else if (keycode == D)
	// 	vars->calc.dgm--;
	else if (keycode == 65307)
	{
		free(vars);
		exit (0);
	}
	else if (keycode == LEFT)
		look_left(vars);
	else if (keycode == RIGHT)
		look_right(vars);
	// else
	// 	findkey(vars, keycode);
	// rotate_all(vars);
	// drawfilelines(vars);
	ft_bzero(vars->img->addr, sizeof(vars->img->bpp) * WIDTH * HEIGHT);
	projection(vars);
	return (1);
}

void	look_left(t_vars *vars)
{
	double old_dirx = vars->dir_x;
	double old_planex = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(R_SPD) - vars->dir_y * sin(R_SPD);
	vars->dir_y = old_dirx * sin(R_SPD) + vars->dir_y * cos(R_SPD);
	vars->plane_x = vars->plane_x * cos(R_SPD) - vars->plane_y * sin(R_SPD);
	vars->plane_y = old_planex * sin(R_SPD) + vars->plane_y * cos(R_SPD);
}

void	look_right(t_vars *vars)
{
	double old_dirx = vars->dir_x;
	double old_planex = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(-R_SPD) - vars->dir_y * sin(-R_SPD);
	vars->dir_y = old_dirx * sin(-R_SPD) + vars->dir_y * cos(-R_SPD);
	vars->plane_x = vars->plane_x * cos(-R_SPD) - vars->plane_y * sin(-R_SPD);
	vars->plane_y = old_planex * sin(-R_SPD) + vars->plane_y * cos(-R_SPD);
}

void	move_player(t_vars *vars)
{
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + vars->dir_x * 0.05)] != 49)
		vars->pos_x += vars->dir_x * 0.05;
	if (vars->map[(int)(vars->pos_y + vars->dir_y * 0.05)][(int)vars->pos_x] != 49)
		vars->pos_y += vars->dir_y * 0.05;
}
