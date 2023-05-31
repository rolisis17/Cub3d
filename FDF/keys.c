/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:51:45 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 16:06:01 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 100 && vars->calc.dgy <= 90)
		vars->calc.dgy++;
	else if (keycode == 97 && vars->calc.dgy >= -90)
		vars->calc.dgy--;
	else if (keycode == 119)
		vars->calc.dgm++;
	else if (keycode == 115)
		vars->calc.dgm--;
	else if (keycode == 65307)
		exit (0);
	else
		findkey(vars, keycode);
	rotate_all(vars);
	drawfilelines(vars);
	return (1);
}

void	findkey(t_vars *vars, int keycode)
{
	if (keycode == 114)
		put_calcs(vars);
	else if (keycode == 65363)
		vars->calc.cx -= 3;
	else if (keycode == 65361)
		vars->calc.cx += 3;
	else if (keycode == 65364)
		vars->calc.cy -= 3;
	else if (keycode == 65362)
		vars->calc.cy += 3;
	else if (keycode == 122)
		vars->calc.size += 1;
	else if (keycode == 120)
		vars->calc.size -= 1;
}

int	mouse_keys(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 4)
		vars->calc.ratio += 1;
	else if (button == 5 && vars->calc.ratio > 0)
		vars->calc.ratio -= 1;
	rotate_all(vars);
	drawfilelines(vars);
	return (1);
}

int	close_win2(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	close (vars->fd);
	exit (0);
}
