/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:05:43 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/02 21:23:28 by mstiedl          ###   ########.fr       */
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
	// if (keycode == 100 && vars->calc.dgy <= 90)
	// 	vars->calc.dgy++;
	// else if (keycode == 97 && vars->calc.dgy >= -90)
	// 	vars->calc.dgy--;
	// else if (keycode == 119)
	// 	vars->calc.dgm++;
	// else if (keycode == 115)
	// 	vars->calc.dgm--;
	if (keycode == 65307)
	{
		free(vars);
		exit (0);
	}
	// else
	// 	findkey(vars, keycode);
	// rotate_all(vars);
	// drawfilelines(vars);
	return (1);
}