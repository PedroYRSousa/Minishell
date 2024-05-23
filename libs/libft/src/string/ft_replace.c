/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:41:42 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/09 12:16:34 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	refill(char **output, char **src, size_t steps)
{
	while (steps > 0)
	{
		(*output) = ft_strcatchr((*output), (**src));
		(*src)++;
		steps--;
	}
}

char	*ft_nreplace(char *_src, char *_old, char *_new, size_t steps)
{
	char	*output;

	output = NULL;
	refill(&output, &_src, steps);
	while ((*_src))
	{
		if (ft_strncmp(_src, _old, ft_strlen(_old)) == 0)
		{
			while ((*_old))
			{
				_src++;
				_old++;
			}
			while ((*_new))
			{
				output = ft_strcatchr(output, (*_new));
				_new++;
			}
		}
		output = ft_strcatchr(output, (*_src));
		if (*_src)
			_src++;
	}
	return (output);
}

char	*ft_replace(char *_src, char *_old, char *_new)
{
	char	*output;

	output = NULL;
	while ((*_src))
	{
		if (ft_strncmp(_src, _old, ft_strlen(_old)) == 0)
		{
			while ((*_old))
			{
				_src++;
				_old++;
			}
			while ((*_new))
			{
				output = ft_strcatchr(output, (*_new));
				_new++;
			}
		}
		output = ft_strcatchr(output, (*_src));
		if (*_src)
			_src++;
	}
	return (output);
}
