/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_manager.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/08 18:34:01 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/14 15:04:35 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

/*
 ** Check if the line is a start command.
 ** Returns 1 if it is a start command. Else 0.
*/

int		is_start(char *str)
{
	if (!is_cmd(str))
		return (0);
	return (ft_strcmp(str, "##start") == 0);
}

/*
 ** Check if the line is a end command.
 ** Returns 1 if it is a end command. Else 0.
*/

int		is_end(char *str)
{
	if (!is_cmd(str))
		return (0);
	return (ft_strcmp(str, "##end") == 0);
}
