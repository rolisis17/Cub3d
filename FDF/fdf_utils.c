/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:51:12 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 12:44:10 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_line	combinetwodots(t_dir start, t_dir end)
{
	t_line	line;

	line.x1 = start.x;
	line.y1 = start.y;
	line.x2 = end.x;
	line.y2 = end.y;
	return (line);
}

t_dir	makeadot(int x, int y)
{
	t_dir	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > vars->calc.width || y < 0 || y > vars->calc.height)
		return ;
	dst = vars->img->addr + (y * vars->img->ll + x * (vars->img->bpp / 8));
	*(unsigned int *) dst = color;
}

void	free_vars(t_vars **vars)
{
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	mlx_destroy_display((*vars)->mlx);
	close ((*vars)->fd);
	if ((*vars)->mlx)
		free ((*vars)->mlx);
	if ((*vars)->file)
		free_file(&(*vars)->file);
	if ((*vars)->img)
	{
		mlx_destroy_image((*vars)->mlx, (*vars)->img);
		free ((*vars)->img->img);
		free ((*vars)->img);
	}
	exit (0);
}

void	free_file(t_dotfile **file)
{
	t_dotfile	*temp;
	t_dotfile	*tofree;

	temp = (*file);
	while (*file)
	{
		while (temp)
		{
			tofree = temp;
			temp = temp->next;
			free (tofree);
		}
		if ((*file)->down)
			(*file) = (*file)->down;
		else
			(*file) = NULL;
		temp = (*file);
	}
}
