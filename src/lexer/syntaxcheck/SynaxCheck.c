/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SynaxCheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icelebi <icelebi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:52:09 by icelebi           #+#    #+#             */
/*   Updated: 2023/10/25 19:52:09 by icelebi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	syntax_check(void)
{
	t_lexlist	*lex_list;
	int			syntax_error;

	lex_list = g_core.lex_table; // lext_list, hazırdaki listeyi işaret ediyor.
	while (lex_list) 
	{
		syntax_error = syntax_error_check(lex_list);
		if (syntax_error == -1)
			break ;
		else if (!syntax_error)
			continue ;
		if (g_core.lex_table)
			lex_list = lex_list->next;
		else
			lex_list = NULL;
	}
}

int	syntax_error_check(t_lexlist *lex_list) // 
{
	int	pipe_error;

	if (lex_list == g_core.lex_table && lex_list->type == SIGN_PIPE) // ilk node ise ve type'ı '|' ise
	{
		print_lex_error(lex_list);
		return (-1);
	}
	else if (lex_list->type != TEXT && lex_list->type != SIGN_PIPE) // text veya PIPE değilse yani "<, >, <<, >> ise"
	{
		if (!file_error_check(lex_list)) //sonraki node text ise 1 geliyor, yoksa veya değilse sıfır geliyor.
			return (-1);
	}
	else if (lex_list->type == SIGN_PIPE) // type'ı PIPE ise
	{
		pipe_error = pipe_error_check(lex_list);
		if (pipe_error < 0)
			return (0);
		else if (!pipe_error)
			return (-1);
	}
	return (1);
}
