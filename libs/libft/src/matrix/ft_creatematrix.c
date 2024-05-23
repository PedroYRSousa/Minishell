/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatematrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:48:11 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/02/17 10:49:19 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_creatematrix(size_t __sizeof)
{
	void	**matrix;

	matrix = ft_calloc(1, __sizeof);
	return (matrix);
}
