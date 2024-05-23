/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:24:29 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 04:26:03 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include <unistd.h>

void	reset_fds(void)
{
	t_info	*info;

	info = get_instance_info();
	dup2(info->std_fd.in, STDIN_FILENO);
	dup2(info->std_fd.out, STDOUT_FILENO);
	dup2(info->std_fd.err, STDERR_FILENO);
	close(info->std_fd.in);
	close(info->std_fd.out);
	close(info->std_fd.err);
	info->std_fd.in = dup(STDIN_FILENO);
	info->std_fd.out = dup(STDOUT_FILENO);
	info->std_fd.err = dup(STDERR_FILENO);
}
