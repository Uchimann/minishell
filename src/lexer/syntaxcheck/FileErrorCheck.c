/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileErrorCheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:38:19 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:38:19 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	file_error_check(t_lexlist *lex_list) // bir sonraki node'un type'ı text ise 1 döndürüyor sonraki düğüm yoksa veya text değilse 0 return ediyor
{
	if (!lex_list->next || (lex_list->next && lex_list->next->type != TEXT)) // next yoksa veya nextin type'ı TEXT değilse
	{
		if (lex_list->next) //next varsa
		{
			print_error("-bash: syntax error near unexpected token '",
				lex_list->next->content, "'\n");
			g_core.exec_output = 2;
			free_lexer_without_heredoc(lex_list);
			return (0);
		}
		else //next yoksa
		{
			print_error("-bash: syntax error near unexpected token '",
				"newline", "'\n");
			g_core.exec_output = 2;
			free_lexer_without_heredoc(lex_list);
			return (0);
		}
	}
	return (1);
}
