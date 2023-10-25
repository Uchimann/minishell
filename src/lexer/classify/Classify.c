/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:59 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:36:59 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"
/*
	olusturulmus lexer bagli listesinde ki her nodeda bulunan 
	sozcuklerin tipi belirlenir.
	bu olusturulan tiplerin karsiliklari "lexer.h"'da define edilmistir
	oradan karsiliklari gorulebilir ve kontrol islemleri
	orda define edilmis degiskenler uzerinden yapilabilir.
*/

void	classify(t_lexlist *lex_table)
{
	char	*metachars;

	if (!lex_table)
		return ;
	while (lex_table)
	{
		metachars = compare_metachars(lex_table->content); // baktığımız düğümdeki contenti gönderiyoruz metacahr ise hangi metachar olduğunu alıyoruz. (ptr alıyor)
		if (metachars) //pointer'ın gösterdiği yerde birşey var ise
			lex_table->type = (*metachars - 1) * ft_strlen(metachars); //baktığımız yerdeki node'un type'ı == (metachar'ın uzuluğu * metacharın ascci değeri) oldu.
		else														   // buradaki -1 olayı >> de ascii kodunu ikiyle çarptığımızda pipe karakteriyle çelişiyor olmasından dolayı tüm metakarakterleri 1 eksiltiyoruz.
			lex_table->type = 0;
		lex_table = lex_table->next;
	}
}
