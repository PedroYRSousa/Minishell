/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:56:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/15 10:43:28 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

void	ms_cd(t_command *com);
void	ms_exit(t_command *com);
void	ms_unset(t_command *com);
void	ms_export(t_command *com);

void	executor(void);

void	exec_here_doc(void);
void	exec_redirections(void);

#endif