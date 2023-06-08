/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcella-d <dcella-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:18 by dcella-d          #+#    #+#             */
/*   Updated: 2023/06/08 16:18:25 by dcella-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*exit_exec(char *full_path, char **args, char **envp, int check)
{
	if (check == 1)
		return ("8f3747b0a1c29671c093534be3cdd7419fce01b2");
	if (full_path && access(full_path, F_OK) == 0)
	{
		if (!args)
		{
			args[0] = "8f3747b0a1c29671c093534be3cdd7419fce01b2";
			args[1] = NULL;
		}
		execve(full_path, args, envp);
	}
	return (NULL);
}
