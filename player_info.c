/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstiedl <mstiedl@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:52:02 by mstiedl           #+#    #+#             */
/*   Updated: 2023/06/05 18:05:12 by mstiedl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_dir(int arg)
{
	if (arg == 0 && (player_dir == 'N' || player_dir == 'S'))
		return (0);
	if (arg == 1 && (player_dir == 'E' || player_dir == 'W'))
		return (0);
	if (arg == 0 && player_dir == 'E')
		return (1);
	if (arg == 0 && player_dir == 'W')
		return (-1);
	if (arg == 1 && player_dir == 'S')
		return (1);
	if (arg == 1 && player_dir == 'N')
		return (-1);
}