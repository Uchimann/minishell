/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FillCmdTable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:40:37 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:40:37 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	fill_cmdtable(void)
{
	t_cmdlist	*temp_cmdtable;
	t_lexlist	*temp_lexlist;

	if (!g_core.cmd_table)
		return ;
	temp_cmdtable = g_core.cmd_table;
	temp_lexlist = g_core.lex_table;
	while (temp_cmdtable)
	{
		fill_cmdnode(temp_cmdtable, &temp_lexlist);
		if (temp_lexlist && *temp_lexlist->content == *PIPE)
			temp_lexlist = temp_lexlist->next;
		temp_cmdtable = temp_cmdtable->next;
	}
}

void	fill_cmdnode(t_cmdlist *node, t_lexlist **lex_list)
{
	char	**path_holder;
	int		is_begin;

	node->path = create_path(*lex_list); // node'un path'ine yer açtık Pıpe olan lexnode'unu görene kadar.
	path_holder = node->path; // patholder açılan path yerlerinin başını gösteriyor.
	is_begin = 0;
	while (*lex_list && (*lex_list)->type != SIGN_PIPE) // baktığımız yerin tipi PIPE değilse
	{
		if (create_new_filelist(node, lex_list)) // node text ise sıfır geliyor. metachar ise sağına bakıyor file_list oluşturuyor. (özellikleriyle beraber).
			continue ;                // filename'ı a.txt vs oldu. a.txt yi de atlatıp onun sağına geçiyor artık > a.txt , kısmının sağındaki şeyi gösteriyor
		if (!(is_begin++) && (*lex_list)->content) // ilk elemansa? ve TEXT ise buraya girer. Contentimiz komut ise lexcontenti, komutun dizini ile değiştirir.
			expand_cmd(&((*lex_list)->content));
		if ((*lex_list)->content)
			*(path_holder++) = (*lex_list)->content;
		*lex_list = (*lex_list)->next;
	}
	if (node->path)
		node->cmd = node->path[0];
}
