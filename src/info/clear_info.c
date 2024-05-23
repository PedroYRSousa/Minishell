/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:26:58 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 04:30:00 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include <unistd.h>

void	clear_info(void)
{
	t_info	*info;

	info = get_instance_info();
	dup2(info->std_fd.in, STDIN_FILENO);
	dup2(info->std_fd.out, STDOUT_FILENO);
	dup2(info->std_fd.err, STDERR_FILENO);
	close(info->std_fd.in);
	close(info->std_fd.out);
	close(info->std_fd.err);
}
