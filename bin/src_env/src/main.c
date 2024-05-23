/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:52 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 09:55:00 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	while ((*envp))
	{
		ft_putendl_fd((*envp), STDOUT_FILENO);
		envp++;
	}
}
