/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:59:18 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 13:26:52 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "libft.h"

void	load_env(int argc, char **argv, char **envp)
{
	char	**split;

	(void)argc;
	(void)argv;
	while ((*envp))
	{
		split = ft_split((*envp), '=');
		if (split[0] && split[1])
			set_env(split[0], split[1]);
		ft_clear_matrix((void ***)&split);
		envp++;
	}
	set_env("?", "0");
	set_env(MS_PATH, "./bin");
	set_env("0", get_env("_"));
}
