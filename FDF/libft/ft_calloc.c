/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:54:18 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/16 13:00:59 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nmembp;

	nmembp = (void *) malloc(nmemb * size);
	if (!nmembp)
		return (NULL);
	ft_bzero(nmembp, nmemb * size);
	return (nmembp);
}
