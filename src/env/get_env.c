/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:01:54 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:00:35 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

char	*get_env(char *name)
{
	t_env	*envs;

	envs = (*get_instance_env());
	while (envs)
	{
		if ((*name) == '$')
			name++;
		if (ft_strcmp(envs->name, name) == 0)
			return (envs->value);
		envs = envs->next;
	}
	return ("");
}
