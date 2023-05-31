/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calccoords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:45:11 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 19:13:49 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_coords(t_dotfile **file, t_calc ca)
{
	t_dotfile	*headx;
	t_dotfile	*heady;
	int			col;
	int			row;

	heady = (*file);
	headx = heady;
	col = count_list_length(headx) - 1;
	row = count_list_depth(headx) - 1;
	while (heady)
	{
		headx->x = ((ca.cx) - ((col * ca.ratio) / 2) + (ca.ratio * \
		(headx->col)));
		headx->y = ((ca.cy) - ((row * ca.ratio) / 2) + (ca.ratio * \
		(headx->row)));
		next_dot_node(&heady, &headx);
	}
}

void	put_calcs(t_vars *vars)
{
	vars->calc.width = 1920;
	vars->calc.height = 1080;
	vars->calc.ratio = 20;
	vars->calc.size = 3;
	vars->calc.th = (M_PI / 180);
	vars->calc.cx = (vars->calc.width / 2);
	vars->calc.cy = (vars->calc.height / 2);
	vars->calc.dgm = 50;
	vars->calc.dgy = 60;
	enumaretefile(&vars->file);
}

void	enumaretefile(t_dotfile **file)
{
	t_dotfile	*temp;
	t_dotfile	*temp2;
	int			len;
	int			dep;

	len = 0;
	dep = -1;
	temp = (*file);
	temp2 = temp;
	while (temp)
	{
		if (temp == temp2)
		{
			dep++;
			len = 0;
		}
		else
			len++;
		temp->col = len;
		temp->row = dep;
		temp->cor = findcolor(temp->dot);
		next_dot_node(&temp2, &temp);
	}
}

int	checkdot(int dot, int ck)
{
	static int	max;
	static int	min;
	int			sign;

	sign = 1;
	if (dot < min)
		min = dot;
	if (dot > max)
		max = dot;
	if (min < 0)
		sign = -1;
	if ((min * sign) > max)
		max = (min * sign);
	if ((min * sign) < max)
		min = max * -1;
	if (ck)
		return (min);
	return (max);
}

void	next_dot_node(t_dotfile **findow, t_dotfile **finex)
{
	if ((*finex)->next)
		(*finex) = (*finex)->next;
	else
	{
		if ((*findow)->down)
			(*findow) = (*findow)->down;
		else
			(*findow) = NULL;
		(*finex) = (*findow);
	}
}
