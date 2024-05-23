/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:05:17 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 02:34:06 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && *s1 && *s2)
	{
		if ((unsigned char)(*s1) != (unsigned char)(*s2))
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		n--;
		s2++;
		s1++;
	}
	if (n != 0 && (unsigned char)(*s1) != (unsigned char)(*s2))
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
	return (0);
}
