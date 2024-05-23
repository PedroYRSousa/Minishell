/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:37:47 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/02/18 13:38:40 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substrstr(char *start, char *end)
{
	char	*str;
	char	aux;

	if (!start || !end)
		return (NULL);
	aux = (*end);
	(*end) = '\0';
	str = ft_substr(start, 0, ft_strlen(start));
	(*end) = aux;
	return (str);
}
