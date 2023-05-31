/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:30:49 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 19:15:02 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_line_put2(t_vars *vars, t_line line, t_line line2)
{
	int	err;
	int	e2;

	err = (find_line2(line2.y1, line2.x1, line2.x1, -line2.y1)) / 2;
	while (1)
	{
		line2.radius = findradius(line);
		my_mlx_pixel_put(vars, line.x1, line.y1, tcolor(changecolor(&line, \
		&line2)));
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break ;
		e2 = err;
		if (e2 > -line2.x1)
		{
			err -= line2.y1;
			line.x1 += line2.x2;
		}
		if (e2 < line2.y1)
		{
			err += line2.x1;
			line.y1 += line2.y2;
		}
	}
}

void	my_mlx_line_put(t_vars *vars, t_dotfile *temp, t_dotfile *next)
{
	t_line	line;
	t_line	line2;

	line.size = temp->dot;
	line2.size = next->dot;
	line.cor = temp->cor;
	line2.cor = next->cor;
	line.x1 = temp->x;
	line.x2 = next->x;
	line.y1 = temp->y;
	line.y2 = next->y;
	line.radius = findradius(line);
	line2.x1 = abs(line.x2 - line.x1);
	line2.y1 = abs(line.y2 - line.y1);
	line2.x2 = find_line2(line.x1, line.x2, 1, -1);
	line2.y2 = find_line2(line.y1, line.y2, 1, -1);
	line2.radius = findradius(line2);
	my_mlx_line_put2(vars, line, line2);
}

void	drawfilelines(t_vars *vars)
{
	t_dotfile	*temp;
	t_dotfile	*temp2;

	temp = vars->file;
	temp2 = temp;
	ft_bzero(vars->img->addr, sizeof(vars->img->bpp) \
	* vars->calc.width * vars->calc.height);
	while (temp)
	{
		if (temp->next)
			my_mlx_line_put(vars, temp, temp->next);
		if (temp->down)
			my_mlx_line_put(vars, temp, temp->down);
		next_dot_node(&temp2, &temp);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

int	find_line2(int x1, int x2, int yes, int no)
{
	if (x1 < x2)
		return (yes);
	else
		return (no);
}

int	makecorratio(double cor, double cor2)
{
	if (cor > cor2)
		return (cor - cor2);
	if (cor < cor2)
		return (cor2 - cor);
	else
		return (cor);
}
