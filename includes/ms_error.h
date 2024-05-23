/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 10:56:24 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 21:54:47 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MS_ERROR_H
# define MS_ERROR_H

void	show_warning_here_doc(int count_lines, char *eof);

void	show_error_syntax(char token);
void	show_error_execve(char *command);
void	show_error_command_error(char *path_name);
void	show_error_command_not_found(char *command);
void	show_error_command_is_directory(char *path_name);

#endif