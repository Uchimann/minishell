/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RunBuiltin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:30:00 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:30:00 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (str_compare(cmd, "echo"))
		return (ECHO);
	else if (str_compare(cmd, "cd"))
		return (CD);
	else if (str_compare(cmd, "pwd"))
		return (PWD);
	else if (str_compare(cmd, "export"))
		return (EXPORT);
	else if (str_compare(cmd, "unset"))
		return (UNSET);
	else if (str_compare(cmd, "env"))
		return (ENV);
	else if (str_compare(cmd, "exit"))
		return (EXIT);
	return (0);
}

void	run_builtin(t_core *g_core,t_cmdlist *cmd_node, int builtin, int *fd, int fd_index) //node, hangi işlem(echo), NULL, -1(single com.)
{
	if (fd)
		create_dup(g_core,cmd_node, fd, fd_index);
	if (builtin == ECHO)
		run_echo(cmd_node);
	else if (builtin == CD)
		run_cd(g_core,cmd_node);
	else if (builtin == PWD)
		run_pwd(cmd_node);
	else if (builtin == EXPORT)
		run_export(g_core,cmd_node);
	else if (builtin == UNSET)
		run_unset(g_core,cmd_node);
	else if (builtin == ENV)
		run_env(g_core,cmd_node);
	else if (builtin == EXIT)
		run_exit(g_core,cmd_node);
}
