/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:52 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/02/21 09:31:47 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	*get_pwd(void)
{
	size_t	size;
	char	*pwd;

	pwd = NULL;
	while (!pwd)
	{
		pwd = getcwd(NULL, size);
		size++;
	}
	return (pwd);
}

int	main(void)
{
	ft_putendl_fd(get_pwd(), STDOUT_FILENO);
}
