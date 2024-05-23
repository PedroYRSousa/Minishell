/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:57:17 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/05 11:52:01 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

# include "fd.h"

typedef struct s_info
{
	t_fd	std_fd;
	char	canceled;
}	t_info;

void	load_info(void);
void	reset_fds(void);
void	clear_info(void);
t_info	*get_instance_info(void);

#endif