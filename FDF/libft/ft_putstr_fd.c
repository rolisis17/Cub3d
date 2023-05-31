/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:42:06 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/21 11:46:50 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	f;

	f = -1;
	while (s[++f])
		ft_putchar_fd(s[f], fd);
}

/* int len;
len = 0;
int i = 0;
"Hello"
while(str[i])
{
	len += putchar(str[i]);
}  */