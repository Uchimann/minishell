/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CompareMetachars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:43:49 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:43:49 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
/*
	gonderilen karakter dizisi ile metakarakterleri kıyaslar
	eger var ise olan metakarakteri return eder.
*/
char	*compare_metachars(char *cmd_line)
{
	char	**meta_chars;

	if (!cmd_line)
		return (NULL);
	meta_chars = g_core.metachars; // globaldeki metachar tablosunu alıyor.
	while (meta_chars && *meta_chars)
	{
		if ((*cmd_line == **meta_chars && !*(*meta_chars + 1))  //cmd line'ın baktığın yeri metachar ise
			|| (*cmd_line == **meta_chars
				&& *(*meta_chars + 1) == *(cmd_line + 1)))
			return (*meta_chars); // hangi metachars ise onu gösteren pointer'ı return et
		meta_chars++;
	}
	return (NULL);
}
