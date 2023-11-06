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

void	parser(void)
{
	g_core.cmd_table = NULL;
	create_cmdtable(g_core.lex_table); // içleri NULL olan standartları belirlenmiş, işlem sayısı kadar node oluşturuldu.
	fill_cmdtable(); // şimdilik:   process node'larındaki node path leri dolduruyor. lexnodelardaki contentlerin dizinleri olan versiyonu ile güncelliyor. procceess nodelarımızdaki cmd değişkenini baş komut ile belirliyor.
	create_files(g_core.cmd_table);
}
