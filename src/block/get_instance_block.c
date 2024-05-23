/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instance_block.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 10:52:22 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/04 10:52:52 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "block.h"

t_block	**get_instance_block(void)
{
	static t_block	*__instance;

	return (&__instance);
}
