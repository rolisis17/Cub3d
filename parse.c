/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:12:33 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:13:16 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	parse_file(int fd, char ***file, char ***path)
{
	*(path) = read_file(fd);
	if (check_walls(*(path)))
		return (1);
	*(file) = make_new_map(*(path), find_max_len(*(path)));
	if (parse_full(*(file)))
		return (1);
	return (0);
}

int	parse_full(char **file)
{
	int	f;

	f = -1;
	if (check_walls(file))
		return (1);
	while (file[++f])
		if (check_map(file[f], f))
			return (1);
	if (player_pos(0, -1, 0, NULL))
		return (1);
	return (0);
}

int	check_map(char *line, int row)
{
	int			f;
	static int	player;

	f = -1;
	while (line[++f])
	{
		if (line[f] != 48 && line[f] != 49)
		{
			if (line[f] != 'N' && line[f] != 'S' && line[f] != 'E' \
			&& line[f] != 'W')
				return (1);
			else
			{
				if (!player)
					player = player_pos(line[f], f, row, NULL);
				else
					return (1);
			}
		}
	}
	return (0);
}

int	check_walls(char **file)
{
	int	f;
	int	u;

	f = 0;
	u = word_count(file);
	while (!check_maps_start(file[f]))
		f++;
	if (search_line(file[f], '1') || search_line(file[u - 1], '1'))
		return (1);
	while (file[f])
	{
		if ((file[f][0] != '1' && file[f][0] != 32) \
		|| (file[f][ft_strlen(file[f]) - 1] != '1' \
		&& file[f][ft_strlen(file[f]) - 1] != 32))
			return (1);
		f++;
	}
	return (0);
}

int	search_line(char *line, int c)
{
	int	f;

	f = -1;
	while (line[++f])
		if (line[f] != c && line[f] != 32)
			return (1);
	return (0);
}
