/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 04:43:39 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 04:59:08 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "info.h"
#include "libft.h"
#include <unistd.h>

void	load_info(void)
{
	t_info	*info;

	info = get_instance_info();
	info->std_fd.in = dup(STDIN_FILENO);
	info->std_fd.out = dup(STDOUT_FILENO);
	info->std_fd.err = dup(STDERR_FILENO);
}
