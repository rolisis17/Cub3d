/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:47:59 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/08 16:03:22 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	check_nl(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		return (1);
	return (0);
}

double	my_ternery(double a, double b, double yes, double no)
{
	if (a == b)
		return (yes);
	else
		return (no);
}

void	pixel_put(t_img *img, int x, int y, int colour)
{
	char	*dst;

	if (x > WIDTH || x < 0 || y < 0 || y > HEIGHT)
		return ;
	dst = img->addr + (y * img->len + x * (img->bpp / 8));
	*(unsigned int *)dst = colour;
}

unsigned int	get_colour(t_vars *vars, int f)
{
	return (*(unsigned int *)(vars->wall[f].addr + (vars->wall[f].tex_y * \
	vars->wall[f].len + vars->wall[f].tex_x * (vars->wall[f].bpp / 8))));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
