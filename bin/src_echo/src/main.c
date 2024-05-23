/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 09:04:52 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 21:18:15 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static char	has_newline(char ***argv)
{
	if (ft_strcmp((**argv), "-n") == 0)
	{
		(*argv)++;
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	char	put_newline;

	put_newline = TRUE;
	argv++;
	if (argc > 1)
	{
		put_newline = has_newline(&argv);
		while ((*argv))
		{
			ft_putstr_fd((*argv), STDOUT_FILENO);
			if (*(argv + 1))
				ft_putchar_fd(' ', STDOUT_FILENO);
			argv++;
		}
	}
	if (put_newline)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
