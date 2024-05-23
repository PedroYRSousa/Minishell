/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:25:30 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 10:38:32 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "util.h"
#include "libft.h"
#include "block/command.h"

static void	show_export_error(char *name)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
}

static void	get_value(char *src, char **value)
{
	src++;
	(*value) = ft_strdup(src);
}

static void	get_name_value(char **src, char **name, char **value)
{
	char	aux;
	char	*start;

	start = (*src);
	while ((**src) && (**src) != '=')
	{
		skip_quotes(src);
		if ((**src) && (**src) != '=')
			(*src)++;
	}
	aux = (**src);
	(**src) = '\0';
	(*name) = ft_strdup(start);
	(**src) = aux;
	if (ft_strchr((*name), '=') != NULL)
	{
		show_export_error((*name));
		free((*name));
		(*name) = NULL;
	}
	else
	{
		get_value((*src), value);
		set_env((*name), (*value));
	}
}

static void	show_export(void)
{
	char	**aux;
	char	**envs;

	envs = get_envs();
	aux = envs;
	while ((*aux))
	{
		ft_putstr_fd("declare -x ", STDERR_FILENO);
		ft_putendl_fd((*aux), STDERR_FILENO);
		aux++;
	}
	ft_clear_matrix((void ***)&envs);
}

void	ms_export(t_command *com)
{
	char	*name;
	char	*value;
	char	**argv;
	char	*aux_arg;

	argv = com->argv + 1;
	if (ft_count_matrix((void **)com->argv) > 1)
	{
		while ((*argv))
		{
			aux_arg = (*argv);
			if (ft_strchr(aux_arg, '=') != NULL)
			{
				get_name_value(&aux_arg, &name, &value);
				if (name)
				{
					free(value);
					free(name);
				}
			}
			argv++;
		}
	}
	else
		show_export();
}
