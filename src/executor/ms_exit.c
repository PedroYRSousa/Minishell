/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:25:12 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 11:00:08 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "info.h"
#include "block.h"
#include "libft.h"
#include <stdio.h>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>

static void	show_cd_error_argv(void)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd("too many arguments\n", STDERR_FILENO);
}

static void	show_exit_error_numeric(char *arg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
}

static void	ms_std_exit(int wstatus)
{
	ft_putstr_fd("exit\n", STDERR_FILENO);
	clear_env();
	clear_info();
	clear_blocks();
	rl_clear_history();
	exit(wstatus);
}

static char	is_valid(char *arg)
{
	while ((*arg))
	{
		if (!ft_isdigit((*arg)))
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

void	ms_exit(t_command *com)
{
	int		wstatus;
	size_t	count_argv;

	if (com->fds.in == -1 && com->fds.out == -1)
	{
		count_argv = ft_count_matrix((void **)com->argv);
		if (count_argv == 1)
			wstatus = 0;
		else
		{
			if (is_valid(com->argv[1]))
			{
				if (count_argv > 2)
					return (show_cd_error_argv());
				wstatus = ft_atoi(com->argv[1]);
			}
			else
			{
				show_exit_error_numeric(com->argv[1]);
				wstatus = 2;
			}
		}
		ms_std_exit(wstatus);
	}
}
