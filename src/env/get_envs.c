/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_envs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:36:43 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 08:52:10 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

static char	*get_line(char *name, char *value);

char	**get_envs(void)
{
	char	*line;
	char	**envs;
	t_env	*_envs;

	_envs = (*get_instance_env());
	envs = (char **)ft_creatematrix(sizeof(char *));
	while (_envs)
	{
		line = get_line(_envs->name, _envs->value);
		envs = (char **)ft_addmatrix((void **)envs, (void *)line);
		free(line);
		_envs = _envs->next;
	}
	return (envs);
}

static char	*get_line(char *name, char *value)
{
	char	*line;
	char	*aux_line;

	aux_line = ft_strjoin(name, "=");
	line = ft_strjoin(aux_line, value);
	free(aux_line);
	return (line);
}
