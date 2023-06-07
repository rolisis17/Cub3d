/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:05:43 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/07 15:54:56 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	close_win(t_vars *vars)
{
	free_vars(vars);
	exit (0);
}

void	free_vars(t_vars *vars)
{
	// int i;

	// i = 4;
	mlx_destroy_window(vars->mlx, vars->win);
	// while (i--)
	// 	vars->wall[i]->img
	// do i need to destroy image of walls and shit?
	freedom("saa", vars->map, vars->wall, vars);
}

int	keys(int keycode, t_vars *vars)
{
	if (keycode == W)
		move_player(vars);
	else if (keycode == S)
		move_player_back(vars);
	else if (keycode == D)
		move_player_right(vars);
	else if (keycode == A)
		move_player_left(vars);
	else if (keycode == 65307)
	{
		free_vars(vars);
		exit (0);
	}
	else if (keycode == LEFT)
		look_left(vars);
	else if (keycode == RIGHT)
		look_right(vars);
	ft_bzero(vars->img->addr, sizeof(vars->img->bpp) * WIDTH * HEIGHT);
	projection(vars);
	return (1);
}

void	look_right(t_vars *vars)
{
	double old_dirx = vars->dir_x;
	double old_planex = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(R_SPD) - vars->dir_y * sin(R_SPD);
	vars->dir_y = old_dirx * sin(R_SPD) + vars->dir_y * cos(R_SPD);
	vars->plane_x = vars->plane_x * cos(R_SPD) - vars->plane_y * sin(R_SPD);
	vars->plane_y = old_planex * sin(R_SPD) + vars->plane_y * cos(R_SPD);
}

void	look_left(t_vars *vars)
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
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + vars->dir_x * M_SPD)] != 49)
		vars->pos_x += vars->dir_x * M_SPD;
	if (vars->map[(int)(vars->pos_y + vars->dir_y * M_SPD)][(int)vars->pos_x] != 49)
		vars->pos_y += vars->dir_y * M_SPD;
}

void	move_player_back(t_vars *vars)
{
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x - vars->dir_x * M_SPD)] != 49)
		vars->pos_x -= vars->dir_x * M_SPD;
	if (vars->map[(int)(vars->pos_y - vars->dir_y * M_SPD)][(int)vars->pos_x] != 49)
		vars->pos_y -= vars->dir_y * M_SPD;
}

void	move_player_right(t_vars *vars)
{
	double	newdir_x;
	double	newdir_y;
	
	newdir_x = vars->dir_x * cos(M_PI_2) - vars->dir_y * sin(M_PI_2);
	newdir_y = vars->dir_x * sin(M_PI_2) + vars->dir_y * cos(M_PI_2);
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (newdir_x) * M_SPD)] != 49)
		vars->pos_x += (newdir_x) * M_SPD;
	if (vars->map[(int)(vars->pos_y + (newdir_y) * M_SPD)][(int)vars->pos_x] != 49)
		vars->pos_y += (newdir_y) * M_SPD;
}

void	move_player_left(t_vars *vars)
{
	double	newdir_x;
	double	newdir_y;

	newdir_x = vars->dir_x * cos(-M_PI_2) - vars->dir_y * sin(-M_PI_2);
	newdir_y = vars->dir_x * sin(-M_PI_2) + vars->dir_y * cos(-M_PI_2);
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (newdir_x) * M_SPD)] != 49)
		vars->pos_x += (newdir_x) * M_SPD;
	if (vars->map[(int)(vars->pos_y + (newdir_y) * M_SPD)][(int)vars->pos_x] != 49)
		vars->pos_y += (newdir_y) * M_SPD;
}
