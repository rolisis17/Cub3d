/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:05:43 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/06 21:45:35 by dcella-d         ###   ########.fr       */
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
	else if (keycode == S)
		move_player_back(vars);
	else if (keycode == D)
		move_player_right(vars);
	else if (keycode == A)
		move_player_left(vars);
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
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (vars->dir_x) * 0.1)] == 48)
		vars->pos_x += (vars->dir_x) * 0.1;
	// printf("%f\n", vars->dir_y); // -1 front 0 right 0 left 1 back
	// printf("%f\n", vars->dir_x); // 0 front -1 right 1 left 0 back
	if (vars->map[(int)(vars->pos_y + (vars->dir_y) * 0.1)][(int)vars->pos_x] == 48)
		vars->pos_y += (vars->dir_y) * 0.1;
}

void	move_player_right(t_vars *vars)
{
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (vars->dir_x - 1) * 0.1)] == 48)
		vars->pos_x += (vars->dir_x - 1) * 0.1;
	// printf("%f\n", vars->dir_y); // -1 front 0 right 0 left 1 back
	// printf("%f\n", vars->dir_x); // 0 front -1 right 1 left 0 back
	if (vars->map[(int)(vars->pos_y + (vars->dir_y) * 0.1)][(int)vars->pos_x] == 48)
		vars->pos_y += (vars->dir_y) * 0.1;
}

void	move_player_left(t_vars *vars)
{
	int	newdir_x;
	int	newdir_y;

	newdir_x = vars->dir_x * cos(-M_PI_2) - vars->dir_y * sin(-M_PI_2);
	newdir_y = vars->dir_x * sin(-M_PI_2) + vars->dir_y * cos(-M_PI_2);
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (newdir_x) * 0.1)] == 48)
		vars->pos_x += (newdir_x) * 0.1;
	// printf("%f\n", vars->dir_y); // -1 front 0 right 0 left 1 back
	// printf("%f\n", vars->dir_x); // 0 front -1 right 1 left 0 back
	if (vars->map[(int)(vars->pos_y + (newdir_y) * 0.1)][(int)vars->pos_x] == 48)
		vars->pos_y += (newdir_y) * 0.1;
}

void	move_player_back(t_vars *vars)
{
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x - vars->dir_x * 0.1)] == 48)
		vars->pos_x -= vars->dir_x * 0.1;
	// printf("%f\n", vars->dir_y); // -1 front 0 right 0 left 1 back
	// printf("%f\n", vars->dir_x); // 0 front -1 right 1 left 0 back
	if (vars->map[(int)(vars->pos_y - vars->dir_y * 0.1)][(int)vars->pos_x] == 48)
		vars->pos_y -= vars->dir_y * 0.1;
}

// void	move_player(t_vars *vars, int key)
// {
// 	int	angle;
// 	int	newdir_x;
// 	int	newdir_y;

// 	angle = get_angle(key);
// 	newdir_x = vars->dir_x * cos(angle) - vars->dir_y * sin(angle);
// 	newdir_y = vars->dir_x * sin(angle) + vars->dir_y * cos(angle);
// 	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + newdir_x * 0.1)] == 48)
// 		vars->pos_x += newdir_x * 0.1;
// 	if (vars->map[(int)(vars->pos_y + newdir_y * 0.1)][(int)vars->pos_x] == 48)
// 		vars->pos_y += newdir_y * 0.1;
// }

// double	get_angle(int key)
// {
// 	if (key == W)
// 		return (0);
// 	if (key == S)
// 		return (M_PI);
// 	if (key == A)
// 		return (-M_PI_2);
// 	else
// 		return (M_PI_2);
// }

// void	move_player_right(t_vars *vars)
// {
// 	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + 0 * 0.1)] == 48)
// 		vars->pos_x += 0 * 0.1;
// 	if (vars->map[(int)(vars->pos_y + 1 * 0.1)][(int)vars->pos_x] == 48)
// 		vars->pos_y += 1 * 0.1;
// }
