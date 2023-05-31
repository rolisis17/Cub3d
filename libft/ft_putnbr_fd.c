/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:50:57 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/21 11:48:45 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n1;

	n1 = n;
	if (n1 < 0)
	{
		ft_putchar_fd ('-', fd);
		n1 *= -1;
	}
	if (n1 > 9)
	{
		ft_putnbr_fd (n1 / 10, fd);
		ft_putchar_fd ((n1 % 10) + 48, fd);
	}
	else
		ft_putchar_fd (n1 % 10 + 48, fd);
}

/* int main()
{
	ft_putnbr_fd(1212334324, 1);
} */