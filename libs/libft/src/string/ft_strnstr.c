/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 07:19:01 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 02:34:08 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size_l;

	size_l = ft_strlen(little);
	if (size_l == 0)
		return ((char *)big);
	if (size_l > ft_strlen(big))
		return (NULL);
	while (*big && len)
	{
		if (size_l > ft_strlen(big) || len < size_l)
			return (NULL);
		if (ft_strncmp(big, little, size_l) == 0 && len >= size_l)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
