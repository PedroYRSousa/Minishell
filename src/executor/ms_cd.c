/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:25:12 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 10:53:53 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"
#include "block/command.h"
#include <stdio.h>
#include <unistd.h>

static void	show_cd_error_argv(void)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd("too many arguments\n", STDERR_FILENO);
}

static void	show_cd_error_home(void)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd("HOME not set\n", STDERR_FILENO);
}

static void	show_cd_error(char *path)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	perror(path);
}

void	ms_cd(t_command *com)
{
	char	*path;
	size_t	count_argv;

	if (com->fds.in == -1 && com->fds.out == -1)
	{
		count_argv = ft_count_matrix((void **)com->argv);
		if (count_argv > 2)
			return (show_cd_error_argv());
		if (count_argv == 1)
		{
			path = get_env("$HOME");
			com->is_home = TRUE;
		}
		else
			path = com->argv[1];
		if (ft_strcmp(path, "") == 0 && com->is_home)
			show_cd_error_home();
		else
		{
			if (chdir(path) != 0)
				show_cd_error(path);
			else
				set_env("PWD", getcwd(NULL, INT_SIZE_MAX));
		}
	}
}
