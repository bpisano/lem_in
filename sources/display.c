/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 19:38:28 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/08 20:23:00 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Free the parsing data and display an error message.
*/

void	handle_error(t_parse *p)
{
	free(p->rooms);
	free(p->tubs);
	ft_putstr("ERROR\n");
}
