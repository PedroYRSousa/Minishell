/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:47:07 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 21:32:12 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "fd.h"
# include "block/command/redirection.h"

typedef struct s_command
{
	t_fd			fds;
	char			**argv;
	char			is_home;
	t_redirection	*redirections;
}	t_command;

t_command	*create_command(char *start, char *end);
void		add_argument(t_command *command, char **ref);
void		add_redirection(t_command *command, char **ref);

#endif