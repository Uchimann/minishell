/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateFileList.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:40:20 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:40:20 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	create_new_filelist(t_cmdlist *node, t_lexlist **lex_list)
{
	char		*meta;
	char		*filename;
	t_filelist	*temp_filelist;

	if (((*lex_list)->type) == TEXT)
		return (0);
	meta = compare_metachars((*lex_list)->content); // meta char'ı gösteren ptr return ediliyor.
	filename = NULL;
	if ((*lex_list)->next)
		filename = (*lex_list)->next->content;
	if (*meta != *PIPE) // Meta PIPE değilse (yani < > << >> bunlardan biri ise)
	{
		temp_filelist = add_filelist(&(node->files), filename, meta); // file_list structında bir node oluşturur. fd si sıfır filename'i name, metacharı'ı vs belirlenir.
		temp_filelist->metachar = (*lex_list)->content; // metacharımız belirlenir.
	}
	(*lex_list) = (*lex_list)->next;
	if (*lex_list)
		(*lex_list) = (*lex_list)->next;
	return (1);
}

t_filelist	*add_filelist(t_filelist **file_list, char *filename, char *meta) // node->files (NULL),  a.txt , > geldi
{
	t_filelist	*temp_filelist;

	if (!*file_list) //file_list boşsa ona yer açıp onun başını gösteren ptr'yi gösteriyor temp_filelist
	{
		*file_list = (t_filelist *)malloc(sizeof(t_filelist));
		temp_filelist = *file_list;
	}
	else
	{
		temp_filelist = *file_list;
		while (temp_filelist->next)
			temp_filelist = temp_filelist->next;
		temp_filelist->next = (t_filelist *)malloc(sizeof(t_filelist));
		temp_filelist = temp_filelist->next;
	}
	temp_filelist->fd = 0;
	temp_filelist->filename = filename;
	temp_filelist->metachar = meta;
	temp_filelist->next = NULL;
	return (temp_filelist);
}
