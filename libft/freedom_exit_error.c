/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_exit_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 06:48:55 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/15 18:01:49 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	freedom_exit_error(const char *str, ...)
{
	va_list	args;
	int		i;

	i = -1;
	va_start(args, str);
	while (str[++i] != '|')
		ft_putchar_fd(str[i], 2);
	ft_putchar_fd('\n', 2);
	while (str[i])
	{
		if (str[i] == 's')
			freesplit(va_arg(args, char **));
		else if (str[i] == 'l')
			freelist(va_arg(args, t_store *));
		else if (str[i] == 'a')
			free_check(va_arg(args, void *));
		i++;
	}
	va_end(args);
	exit(1);
}
