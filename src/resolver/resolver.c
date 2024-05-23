/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyago_ra <yagosousa2512@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:31:00 by pyago_ra          #+#    #+#             */
/*   Updated: 2022/03/14 20:54:37 by pyago_ra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "info.h"
#include "libft.h"
#include "block.h"
#include "ms_error.h"
#include <dirent.h>
#include <sys/types.h>

static char	is_env(char **argv)
{
	if (argv && (*argv)
		&& ft_strcmp((*argv), "cd") != 0
		&& ft_strcmp((*argv), "exit") != 0
		&& ft_strcmp((*argv), "unset") != 0
		&& ft_strcmp((*argv), "export") != 0)
		return (ft_strchr((*argv), '/') == NULL);
	return (FALSE);
}

static char	*gen_file_path(char *file, char *path)
{
	char	*aux;
	char	*file_path;

	aux = ft_strjoin(path, "/");
	file_path = ft_strjoin(aux, file);
	free(aux);
	return (file_path);
}

static void	get_file_path(char *file, char *paths, char **file_path)
{
	int				index;
	struct dirent	*info;
	char			**_paths;
	DIR				*opened_dir;

	_paths = ft_split(paths, ':');
	index = 0;
	while (_paths[index])
	{
		opened_dir = opendir(_paths[index]);
		if (opened_dir)
		{
			info = readdir(opened_dir);
			while (info && !(*file_path))
			{
				if (ft_strcmp(info->d_name, file) == 0)
					(*file_path) = gen_file_path(file, _paths[index]);
				info = readdir(opened_dir);
			}
		}
		closedir(opened_dir);
		index++;
	}
	ft_clear_matrix((void ***)&(_paths));
}

static char	*resolve_name(char *file)
{
	char	*paths;
	char	*ms_paths;
	char	*file_path;

	paths = get_env(PATH);
	ms_paths = get_env(MS_PATH);
	file_path = NULL;
	get_file_path(file, ms_paths, &file_path);
	if (!file_path)
		get_file_path(file, paths, &file_path);
	return (file_path);
}

void	resolver(void)
{
	char	*file;
	t_block	*blocks;
	char	*file_path;

	blocks = (*get_instance_block());
	while (blocks && !get_instance_info()->canceled)
	{
		if (is_env(blocks->command->argv))
		{
			file = (*blocks->command->argv);
			file_path = resolve_name(file);
			if (!file_path)
			{
				show_error_command_not_found(file);
				blocks->is_valid = FALSE;
			}
			else
			{
				free(blocks->command->argv[0]);
				blocks->command->argv[0] = file_path;
			}
		}
		blocks = blocks->next;
	}
}
