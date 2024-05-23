/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:25:47 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 22:07:46 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "block/command.h"

static void	show_error_unset_invalid_arg(char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("unset: `", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
}

static char	is_valid(char *arg)
{
	if (ft_strchr(arg, '/') != NULL)
		return (FALSE);
	return (TRUE);
}

void	ms_unset(t_command *com)
{
	char	**aux;

	aux = com->argv;
	aux++;
	while ((*aux))
	{
		if (!is_valid((*aux)))
			show_error_unset_invalid_arg((*aux));
		else if (com->fds.in == -1 && com->fds.out == -1)
			unset_env((*aux));
		aux++;
	}
}
