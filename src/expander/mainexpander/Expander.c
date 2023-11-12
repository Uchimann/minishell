/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:38 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:36:38 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	expander(t_core *g_core)
{
	if (g_core->exec_output == 2) // exec return değeri 2 ise burdan çıkıcak. 
		return ;
	expand_values_from_lexlist(g_core); // düğümlerdeki text olan tüm contentleri gerçek çıktıları ile güncelledik. < > gibi karakterlerin sağını kontrol ettik.
	clear_void_contents(g_core); // listede contenti NULL olan node'ları siler.
}
