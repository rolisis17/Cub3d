/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:21:05 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:22:23 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	move_player(t_vars *vars)
{
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + vars->dir_x * M_SPD)] \
	!= 49)
		vars->pos_x += vars->dir_x * M_SPD;
	if (vars->map[(int)(vars->pos_y + vars->dir_y * M_SPD)][(int)vars->pos_x] \
	!= 49)
		vars->pos_y += vars->dir_y * M_SPD;
}

void	move_player_back(t_vars *vars)
{
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x - vars->dir_x * M_SPD)] \
	!= 49)
		vars->pos_x -= vars->dir_x * M_SPD;
	if (vars->map[(int)(vars->pos_y - vars->dir_y * M_SPD)][(int)vars->pos_x] \
	!= 49)
		vars->pos_y -= vars->dir_y * M_SPD;
}

void	move_player_right(t_vars *vars)
{
	double	newdir_x;
	double	newdir_y;

	newdir_x = vars->dir_x * cos(M_PI_2) - vars->dir_y * sin(M_PI_2);
	newdir_y = vars->dir_x * sin(M_PI_2) + vars->dir_y * cos(M_PI_2);
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (newdir_x) * M_SPD)] \
	!= 49)
		vars->pos_x += (newdir_x) * M_SPD;
	if (vars->map[(int)(vars->pos_y + (newdir_y) * M_SPD)][(int)vars->pos_x] \
	!= 49)
		vars->pos_y += (newdir_y) * M_SPD;
}

void	move_player_left(t_vars *vars)
{
	double	newdir_x;
	double	newdir_y;

	newdir_x = vars->dir_x * cos(-M_PI_2) - vars->dir_y * sin(-M_PI_2);
	newdir_y = vars->dir_x * sin(-M_PI_2) + vars->dir_y * cos(-M_PI_2);
	if (vars->map[(int)vars->pos_y][(int)(vars->pos_x + (newdir_x) * M_SPD)] \
	!= 49)
		vars->pos_x += (newdir_x) * M_SPD;
	if (vars->map[(int)(vars->pos_y + (newdir_y) * M_SPD)][(int)vars->pos_x] \
	!= 49)
		vars->pos_y += (newdir_y) * M_SPD;
}
