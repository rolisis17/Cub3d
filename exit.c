/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:05:43 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/08 16:21:37 by dcella-d         ###   ########.fr       */
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
	int	i;

	i = -1;
	while (++i < 4)
		if (vars->wall[i].img)
			mlx_destroy_image(vars->mlx, vars->wall[i].img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_display(vars->mlx);
	freedom("saa", vars->map, vars->mlx, vars);
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
	double	old_dirx;
	double	old_planex;

	old_dirx = vars->dir_x;
	old_planex = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(R_SPD) - vars->dir_y * sin(R_SPD);
	vars->dir_y = old_dirx * sin(R_SPD) + vars->dir_y * cos(R_SPD);
	vars->plane_x = vars->plane_x * cos(R_SPD) - vars->plane_y * sin(R_SPD);
	vars->plane_y = old_planex * sin(R_SPD) + vars->plane_y * cos(R_SPD);
}

void	look_left(t_vars *vars)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = vars->dir_x;
	old_planex = vars->plane_x;
	vars->dir_x = vars->dir_x * cos(-R_SPD) - vars->dir_y * sin(-R_SPD);
	vars->dir_y = old_dirx * sin(-R_SPD) + vars->dir_y * cos(-R_SPD);
	vars->plane_x = vars->plane_x * cos(-R_SPD) - vars->plane_y * sin(-R_SPD);
	vars->plane_y = old_planex * sin(-R_SPD) + vars->plane_y * cos(-R_SPD);
}
