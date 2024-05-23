/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:30:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 10:46:18 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "info.h"
#include "libft.h"
#include "block.h"
#include "syntax.h"
#include "parser.h"
#include "resolver.h"
#include "expansor.h"
#include "executor.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

static void	ms_std_exit(void);
static char	minishell(void);
static char	*get_input(void);
static void	handle_signal(int sig);

int	main(int argc, char **argv, char **envp)
{
	load_info();
	load_env(argc, argv, envp);
	signal(SIGQUIT, handle_signal);
	while (TRUE)
	{
		signal(SIGINT, handle_signal);
		get_instance_info()->canceled = FALSE;
		if (!minishell())
			break ;
		reset_fds();
	}
	ms_std_exit();
	return (EXIT_SUCCESS);
}

static void	ms_std_exit(void)
{
	clear_env();
	clear_info();
	clear_blocks();
	rl_clear_history();
}

static char	minishell(void)
{
	char	*input;

	input = get_input();
	if (input)
	{
		if (syntax(input))
		{
			parser(input);
			exec_here_doc();
			expansor();
			exec_redirections();
			resolver();
			executor();
			clear_blocks();
		}
	}
	else
	{
		if (!input)
			printf("exit\n");
		return (FALSE);
	}
	free(input);
	return (TRUE);
}

static char	*get_input(void)
{
	char	*input;
	char	*pwd;

	pwd = ft_strjoin(get_env("PWD"), "$ ");
	input = readline(pwd);
	if (input)
	{
		if (strlen(input) > 0)
			add_history(input);
	}
	free(pwd);
	return (input);
}

static void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", rl_on_new_line());
		rl_redisplay();
	}
}
