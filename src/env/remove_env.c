/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:12:18 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:31:05 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include <stdlib.h>

void	remove_env(t_env *target)
{
	t_env	*env;
	t_env	*aux;

	aux = NULL;
	if ((*get_instance_env()) == target)
	{
		aux = (*get_instance_env());
		(*get_instance_env()) = (*get_instance_env())->next;
	}
	else
	{
		env = (*get_instance_env());
		while (env && env->next != target)
			env = env->next;
		aux = env->next;
		env->next = aux->next;
	}
	if (aux)
	{
		free(aux->name);
		free(aux->value);
		free(aux);
	}
}
