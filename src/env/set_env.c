/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:06:45 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:31:22 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

void	set_env(char *name, char *value)
{
	t_env	*envs;

	envs = (*get_instance_env());
	while (envs)
	{
		if (ft_strcmp(envs->name, name) == 0)
		{
			free(envs->value);
			envs->value = ft_strdup(value);
			return ;
		}
		envs = envs->next;
	}
	add_env(name, value);
}
