/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:40:56 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:40:56 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*    fill_cmdtable da procceess nodelarımızın içleri dolduruldu. 
dosya işlemleride filelist oluşturuldu.
cmd değişkeni belirlendi
node'path ler belirlendi (ls -la)
infile outfile standart olarak belirlendi
*/

void	parser(t_core *g_core)
{
	g_core->cmd_table = NULL;
	create_cmdtable(g_core,g_core->lex_table); // içleri NULL olan standartları belirlenmiş, işlem sayısı kadar node oluşturuldu.
	fill_cmdtable(g_core); // şimdilik:   process node'larındaki node path leri dolduruyor. lexnodelardaki contentlerin dizinleri olan versiyonu ile güncelliyor. procceess nodelarımızdaki cmd değişkenini baş komut ile belirliyor.
	create_files(g_core,g_core->cmd_table); // echo ismail > a.txt için: node'umuzun outfile'ı filelistimizdeki fd oldu
}
