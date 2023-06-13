/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:02:38 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/13 19:56:54 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	texture_calc(t_pro *ray, t_vars *vars, int f)
{
	if (ray->side == 0)
		vars->wall[f].x = vars->pos_y + ray->wall_dist * ray->raydir_y;
	else
		vars->wall[f].x = vars->pos_x + ray->wall_dist * ray->raydir_x;
	vars->wall[f].x -= floor(vars->wall[f].x);
	vars->wall[f].tex_x = (int)(vars->wall[f].x * (double)vars->wall[f].w);
	if (ray->side == 0 && ray->raydir_x > 0)
		vars->wall[f].tex_x = vars->wall[f].w - vars->wall[f].tex_x - 1;
	if (ray->side == 1 && ray->raydir_y < 0)
		vars->wall[f].tex_x = vars->wall[f].w - vars->wall[f].tex_x - 1;
}

int	read_texture(t_vars *vars, char **file, char *dir, int order)
{
	int		f;
	char	**split;

	f = 0;
	f = 0;
	while (file[f] && ft_strncmp(file[f], dir, 1) != 0)
		f++;
	if (!file[f])
		return (1);
	split = ft_split(file[f], 32);
	ft_strlcpy(vars->txt[order], split[1], ft_strlen(split[1]) + 1);
	freedom("s", split);
	return (0);
}

int	ps(char **file, char *dir, int check)
{
	char	**split;
	char	*line;
	int		res[3];

	line = get_colour_file(file, dir);
	if (!line)
	{
		freedom("sa", file);
		exit(1);
	}
	split = ft_split(line, ',');
	res[0] = ft_atoi(split[0]);
	res[1] = ft_atoi(split[1]);
	res[2] = ft_atoi(split[2]);
	freedom("sa", split, line);
	return (res[check]);
}

char	*get_colour_file(char **file, char *dir)
{
	int		f;
	char	**split;
	char	*res;

	f = 0;
	while (file[f] && ft_strncmp(file[f], dir, 2) != 0)
		f++;
	if (!file[f] && ft_strncmp("C ", dir, 2) == 0)
		return (ft_strdup("0,255,255"));
	else if (!file[f] && ft_strncmp("F ", dir, 2) == 0)
		return (ft_strdup("255,0,255"));
	split = ft_split(file[f], 32);
	res = ft_strdup(split[1]);
	freedom("s", split);
	return (res);
}
