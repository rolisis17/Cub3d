/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:14:10 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/02 16:19:45 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	**make_new_map(char **file, int max_len)
{
	char	**new;
	char	*line;
	int		f;

	f = -1;
	new = ft_calloc(sizeof(char **), 1);
	new[0] = NULL;
	while (file[++f])
	{
		line = make_new_line(file[f], max_len);
		new = add_split(new, line);
		free(line);
	}
	// freedom("s", file);
	return (new);
}

int	find_max_len(char **file)
{
	int	max_len;
	int	f;

	f = -1;
	max_len = 0;
	while (file[++f])
		if (ft_strlen(file[f]) > max_len)//printf("%d\n", ft_strlen(file[f])) && 
			max_len = ft_strlen(file[f]);
	return (max_len);
}

char	*make_new_line(char *line, int max_len)
{
	int			f;

	f = -1;
	while (line[++f])
	{
		if (line[f] == 32)
			line[f] = 49;
	}
	if (ft_strlen(line) < max_len)
		return (strpp(line, max_len, 49));
	return (line);
}

char	*strpp(char *line, int len, int c)
{
	char *res;
	int	f;

	f = ft_strlen(line);
	if (f < len)
	{
		res = (char *) malloc(len + 1 * sizeof(char));
		if (!res)
			return (NULL);
		ft_strlcpy(res, line, f + 1);
		while (f < len)
			res[f++] = c;
		res[f] = '\0';
		return (res);
	}
	res = ft_strdup(line);
	freedom("a", line);
	return (line);
}

int	check_nl(char *line)
{
	if (line[ft_strlen(line) - 1] == '\n')
		return (1);
	return (0);
}
