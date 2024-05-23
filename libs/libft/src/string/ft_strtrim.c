/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:11:22 by pyago-ra          #+#    #+#             */
/*   Updated: 2022/02/03 02:34:14 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_size(char *f_char, char *l_char)
{
	size_t	size;

	size = 0;
	while (f_char <= l_char)
	{
		f_char++;
		size++;
	}
	return (size);
}

static int	contains(char *str, char target)
{
	while (*str)
	{
		if (*str == target)
			return (TRUE);
		str++;
	}
	return (FALSE);
}

static char	*get_f_char(char *s1, char *set)
{
	while (*s1)
	{
		if (!contains(set, *s1))
			break ;
		s1++;
	}
	return (s1);
}

static char	*get_l_char(char *s1, char *set, char *first_caractere)
{
	while (s1 > first_caractere)
	{
		if (!contains(set, *s1))
			break ;
		s1--;
	}
	return (s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*f_char;
	char	*l_char;
	char	*new_str;
	int		index;

	if (!s1 || !set)
		return (NULL);
	f_char = get_f_char((char *)s1, (char *)set);
	l_char = get_l_char((char *)&s1[ft_strlen(s1) - 1], (char *)set, f_char);
	new_str = (char *)ft_calloc(get_size(f_char, l_char) + 1, sizeof(char));
	if (new_str)
	{
		index = 0;
		while (f_char <= l_char)
		{
			new_str[index] = *f_char;
			f_char++;
			index++;
		}
	}
	return (new_str);
}
