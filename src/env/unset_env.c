/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:06:45 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:00:40 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

void	unset_env(char *name)
{
	t_env	*envs;

	envs = (*get_instance_env());
	while (envs)
	{
		if (ft_strcmp(envs->name, name) == 0)
		{
			remove_env(envs);
			return ;
		}
		envs = envs->next;
	}
}
