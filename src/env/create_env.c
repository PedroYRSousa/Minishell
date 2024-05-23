/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 07:03:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 09:05:04 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

t_env	*create_env(char *name, char *value)
{
	t_env	*new_env;

	new_env = (t_env *)ft_calloc(1, sizeof(t_env));
	new_env->name = ft_strdup(name);
	new_env->value = ft_strdup(value);
	return (new_env);
}
