/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error_execve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:45:58 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 21:23:08 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	show_error_execve(char *command)
{
	char	*default_msg;

	default_msg = "minishell: ";
	ft_putstr_fd(default_msg, STDERR_FILENO);
	perror(command);
}
