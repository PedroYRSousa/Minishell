/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcatchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:41:42 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/02/18 14:56:39 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatchr(char *src, char new)
{
	size_t	index;
	char	*aux;

	if (src)
		aux = (char *)ft_calloc(ft_strlen(src) + 2, sizeof(char));
	else
		aux = (char *)ft_calloc(2, sizeof(char));
	index = 0;
	while (src && src[index])
	{
		aux[index] = src[index];
		index++;
	}
	if (src)
		free(src);
	aux[index] = new;
	return (aux);
}
