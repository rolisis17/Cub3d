/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:02:22 by dcella-d          #+#    #+#             */
/*   Updated: 2023/03/27 13:12:08 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_flags(char uck, va_list args)
{
	if (uck == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (uck == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (uck == 'd' || uck == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (uck == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	if (uck == '%')
		return (ft_putchar('%'));
	if (uck == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef"));
	if (uck == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (uck == 'p')
		return (ft_putaddress(va_arg(args, unsigned long int), \
		"0123456789abcdef", 0));
	return (0);
}

/* • %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign */