/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: anamsell <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/15 18:37:54 by anamsell     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/15 19:36:48 by anamsell    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_lem	t;

	init(&t);
	while (get_next_line(0, t.&str))
	{
		if (t.str[0] == '#')
			commande(&t);
		else if (ft_isdigit(t.str[0]))
			num(&t);
		else
			break ;
	}
	resolve(&t);
}
