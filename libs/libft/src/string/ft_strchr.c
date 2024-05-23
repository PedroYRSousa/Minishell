/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 08:16:42 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 02:33:46 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (c % 256))
			return ((char *)s);
		s++;
	}
	if (*s == (c % 256))
		return ((char *)s);
	return (NULL);
}
