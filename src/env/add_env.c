/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 07:03:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 10:05:33 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	add_env(char *name, char *value)
{
	t_env	*aux;
	t_env	*new_env;

	new_env = create_env(name, value);
	if (!(*get_instance_env()))
		(*get_instance_env()) = new_env;
	else
	{
		aux = (*get_instance_env());
		while (aux->next)
			aux = aux->next;
		aux->next = new_env;
	}
}
