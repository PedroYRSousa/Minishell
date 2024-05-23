/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 10:57:29 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 02:33:59 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*_src;

	if (!dst || !src)
		return (0);
	_src = (const char *)src;
	if (size > 0)
	{
		while (size-- > 1 && *_src)
			*(dst++) = *(_src++);
		*dst = '\0';
	}
	return (ft_strlen(src));
}
