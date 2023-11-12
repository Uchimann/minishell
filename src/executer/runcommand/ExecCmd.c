/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecCmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:34:39 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:34:39 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	exec_command(t_core *g_core,t_cmdlist *cmd_node, int *fd, int fd_index) // node, NULL, -1
{
	char	*cmd;
	int		builtin_index;

	if (cmd_node && !cmd_node->cmd)
		return ;
	cmd = get_cmd(cmd_node->cmd); 
	builtin_index = is_builtin(cmd); // hangi komut olduğunun return'u geliyor
	if (builtin_index)
		run_builtin(g_core,cmd_node, builtin_index, fd, fd_index);
	else
		run_execve(g_core,cmd_node, fd, fd_index);
}

char	*get_cmd(char *cmd)
{
	int		command_len;

	command_len = 0;
	while (*cmd)
	{
		command_len++;
		if (*cmd == '/')
			command_len = 0;
		cmd++;
	}
	return (cmd - command_len);
}
