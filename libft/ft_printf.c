/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:09:56 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:12:10 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start (args, str);
	count += ft_count(str, args);
	va_end (args);
	return (count);
}

/* int	main()
{
	void	*fu;
	fuck = "fu";
	int res = ft_printf("Poarr %c\n", 'a');
	int res2 = ft_printf("Poarr %s\n", "Carai irmao");
	int res3 = ft_printf("Poarr %d\n", 12342);
	int res4 = ft_printf("Poarr %u\n", -12341);
	int res5 = ft_printf("void pointer: %s\n", fu);
	int res6 = printf("void pointer: %s\n", fu);
	printf("%d\n", res);
	printf("%d\n", res2);
	printf("%d\n", res3);
	printf("%d\n", res4);
	printf("%d\n", res5);
	printf("%d\n", res6);
} */