/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GetLen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@42kocaeli.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:37:30 by hsozan            #+#    #+#             */
/*   Updated: 2023/02/19 13:37:30 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	c karakterine komutun ilk indisi atanir ve hangi tirnak
	tipi oldugu anlasilir(" ya da ').
	komut nulla gelene kadar(pdf tirnagin kapatilmis olup olmadıgini
	 kontrol etmemizi istemiyor)
	ya da baslangic karakterine gorene kadar count degiskeni arttilir.
	ve bu degisken return edilir.
*/
size_t	get_quotelen(char *cmd_line) // tek tırnak veya çift tırnak ise o tırnaktan sonrası kadarını ve tırnağı count'a ekliyor
{
	char	c;
	size_t	count;

	c = *cmd_line;
	count = 1; // zaten tırnak görüyor onu da uzunlıuğa ekliyor bir sonrakine bakarak while'a giriyor
	while (*(++cmd_line)) // yeni bır tırnak veya çifttırnak (girerken hangisi ile girdiysek) görene kadar count arttırıyor.
	{
		count++; 
		if (*cmd_line == c)
			break ;
	}
	return (count);
}

/*
	Bu fonksiyon her cagirildiginda kelime uzunlugunu alir.
	Ve uzunlugu donderir.
	Eger komutun indisi metakarakter ise metakarakterin
	genisligi count'a eklenir ve dongu sonlandirilir.
	Eger komutun indisinde tirnak isareti var ise get_quotelen
	fonksiyonundan tirnagin ve icinin ne kadar uzunkukta oldugu alinir
	ve ardindan counta eklenir.
	Eger komutun indisi metakarakter ya da tirnak degilse count arttirlir.
	orn:
	cat a.txt -> cat'in uzunlugu olan 3'u donderir
	<< "eof" cat -> <<'un uzunlugu olan 2'yi donderir
	"Ahmet$HOME"ls echo -> "Ahmet$HOME"ls'in uzunlugu olan 14'u gonderir
	gelen komut null'a gelene ya da bosluga gelene kadr donderilir.
*/
size_t	get_cmdlen(char *cmd_line)   // söz öbeğinin uzunluğunu ölçüyor boşiluk görene kadar veya NULL görene kadar ilerletiyor.
{
	size_t	count;
	size_t	quotelen;
	char	*is_meta;

	count = 0;
	while (cmd_line && *cmd_line && *cmd_line != ' ')
	{
		is_meta = compare_metachars(cmd_line);
		if (is_meta)  //eğer metachar ise metachar'ın uzunluğunu count'a ekle 
		{
			if (!count)
				count += ft_strlen(is_meta);
			break ;
		}
		if ((*cmd_line == *SINGLE_QUOTE || *cmd_line == *DOUBLE_QUOTE)) // baktığın yer tek tırnak veya çift tırnak ise
		{
			quotelen = get_quotelen(cmd_line); //tırnak ve sonrası kadar uzunluğunu aldık
			count += quotelen; // count'a ekledik
			cmd_line += quotelen; // pointer'ı quatelen kadar ilerlettik. (yani kapanan tırnağa kadar ilerledi veya null'a veya boşluğa kadar)
			continue ; // aşağıda tekrar ilerleme yapmasın diye en başa ilerlettik.
		}
		count++;
		cmd_line++;
	}
	return (count);
}
