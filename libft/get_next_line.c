/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 18:25:40 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:17:12 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int		ft_strlen_get(const char *str);
int				ft_check(char *to_check);
char			*ft_gnl_join(char *s1, char *s2);

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE + 1];
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
	{
		i = 0;
		while (buffer[i])
			buffer[i++] = '\0';
		return (NULL);
	}
	str = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		str = ft_gnl_join(str, buffer);
		if (ft_check(buffer))
			break ;
	}
	return (str);
}

static int	ft_strlen_get(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i + (str[i] == '\n'));
}

int	ft_check(char *to_check)
{
	int	i[3];

	i[0] = 0;
	i[1] = 0;
	i[2] = 0;
	while (to_check[i[1]])
	{
		if (i[0])
			to_check[i[2]++] = to_check[i[1]];
		if (to_check[i[1]] == '\n')
			i[0] = 1;
		to_check[i[1]++] = '\0';
	}
	return (i[0]);
}

char	*ft_gnl_join(char *s1, char *s2)
{
	char	*str;
	int		i[3];

	i[0] = ft_strlen_get(s1) + ft_strlen_get(s2);
	i[1] = 0;
	i[2] = -1;
	str = (char *)malloc(sizeof(char) * (i[0] + 1));
	if (!str)
		return (NULL);
	while (s1 && s1[i[1]])
	{
		str[i[1]] = s1[i[1]];
		i[1]++;
	}
	while (s2[++i[2]])
	{
		str[i[1]++] = s2[i[2]];
		if (s2[i[2]] == '\n')
			break ;
	}
	str[i[1]] = '\0';
	free(s1);
	return (str);
}

// char	*get_next_line(int fd)
// {
// 	char		*line;
// 	int			posnextline;
// 	static char	*keep;

// 	if (BUFFER_SIZE < 1 || fd < 0 || fd > FOPEN_MAX)
// 		return (NULL);
// 	if (gnl_check(keep) == 0)
// 		keep = full_line(fd, keep);
// 	if (!keep || keep[0] == '\0')
// 	{
// 		free (keep);
// 		keep = NULL;
// 		return (NULL);
// 	}
// 	posnextline = gnl_check(keep);
// 	line = makeline(keep, posnextline);
// 	if (posnextline > 0)
// 		keep = ft_strjoin_gnl(keep, keep + posnextline, -1);
// 	else
// 	{
// 		free (keep);
// 		keep = NULL;
// 	}	
// 	return (line);
// }

// char	*makeline(char *keep, int posnextline)
// {
// 	int		f;
// 	char	*line;

// 	f = -1;
// 	if (!keep)
// 		return (NULL);
// 	if (posnextline == 0)
// 		posnextline = ft_strlen_gnl(keep);
// 	line = ft_calloc_gnl(posnextline + 1, sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	while (keep[++f] && f < posnextline)
// 		line[f] = keep[f];
// 	return (line);
// }

// char	*full_line(int fd, char *keep)
// {
// 	int		f;
// 	char	*line;

// 	f = BUFFER_SIZE;
// 	line = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
// 	if (!line)
// 		return (NULL);
// 	while (f > 0)
// 	{
// 		if (gnl_check(line) > 0)
// 			break ;
// 		f = read(fd, line, BUFFER_SIZE);
// 		if (f < 0)
// 		{
// 			if (keep)
// 				free (keep);
// 			keep = NULL;
// 			break ;
// 		}
// 		line[f] = 0;
// 		keep = ft_strjoin_gnl(keep, line, 0);
// 	}
// 	free (line);
// 	return (keep);
// }

/* #include <fcntl.h>

int	main(void)
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *str5;
	int fd = open("fuc.txt", O_RDONLY);
	str = get_next_line(fd);
	str2 = get_next_line(-1);
	str3 = get_next_line(fd);
	str4 = get_next_line(-1);
	str5 = get_next_line(fd);
	printf("This is your ass: %s", str);
	free (str);
	printf("This is your ass: %s", str2);
	free (str2);
	printf("This is your ass: %s", str3);
	free (str3);
	printf("This is your ass: %s", str4);
	free (str4);
	printf("This is your ass: %s", str5);
	free (str5);
	close (fd);
	return (0);
} */