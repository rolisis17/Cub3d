/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:12:17 by dcella-d          #+#    #+#             */
/*   Updated: 2023/02/23 19:12:48 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_vars		*vars;
	t_data		img;

	if (ac == 2)
	{
		vars = (t_vars *)malloc (sizeof(t_vars));
		if (!vars)
			exit (0);
		vars->fd = open(av[1], O_RDONLY);
		vars->file = NULL;
		readdotfile(&vars->file, vars->fd);
		put_calcs(vars);
		put_coords(&vars->file, vars->calc);
		makeimg(&vars, &img);
		rotate_all(vars);
		drawfilelines(vars);
		mlx_hook(vars->win, 2, 1L << 0, close_win, vars);
		mlx_hook(vars->win, 17, 1L << 2, close_win2, vars);
		mlx_mouse_hook(vars->win, mouse_keys, vars);
		mlx_loop(vars->mlx);
		free_vars(&vars);
	}
}

void	makeimg(t_vars **vars, t_data *img)
{
	(*vars)->mlx = mlx_init();
	(*vars)->win = mlx_new_window((*vars)->mlx, (*vars)->calc.width, \
	(*vars)->calc.height, "FDF");
	img->img = mlx_new_image((*vars)->mlx, (*vars)->calc.width, \
	(*vars)->calc.height);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	(*vars)->img = img;
}
