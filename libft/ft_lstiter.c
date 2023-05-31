/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:28:19 by dcella-d          #+#    #+#             */
/*   Updated: 2022/11/18 11:51:05 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	while (lst != NULL)
	{
		(f)(lst->content);
		lst = lst->next;
	}
}

/* void	*ft_function(void *something)
{
	char	*character = "B";
	something = character;
	printf("Na funcao %s\n", (char *)something);
	return (something);
}
 */

/* int	main()
{
	t_list *str = NULL;
	t_list *head = NULL;
	char	*character;
	character = "C";
	char	*character2;
	character2 = "A";
	head = ft_lstnew(character);
	str = ft_lstnew(character2);
	head->next = str;
	printf("%s\n", (char *)str->content);
	ft_lstiter(head, ft_function);
	printf("%s\n", (char *)head->content);
} */