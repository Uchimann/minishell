/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateFiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:42:11 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:42:11 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	create_files(t_core *g_core,t_cmdlist *node)
{
	t_filelist	*temp_file;

	if (!node)
		return ;
	run_heredocs(g_core,node); // heredoc içeriği oluşturulur. 
	if (g_core->exec_output || !node)
		return ;
	while (node)
	{
		temp_file = node->files;
		while (temp_file)
		{
			if (*temp_file->metachar == *SINGLE_GREAT) // > ise (yani çıkış dosyası oluşturulacaksa),  echo ismail > a.txt
				create_outfile(node, temp_file);
			else
				create_infile(g_core,node, temp_file); // > değilse (yani giriş dosyası okunacaksa), 
			if (temp_file->fd == SSTDERR) // (standart hata yönlendirmesi varsa)
			{
				g_core->exec_output = 1;
				break ; // iç içe döngü kırılır. 
			}
			temp_file = temp_file->next;
		}
		node = node->next;
	}
}
