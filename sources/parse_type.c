/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_type.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 15:26:36 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/06/25 16:44:25 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem_in.h"

int		is_ants(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		is_cmd(char *str)
{
	return (is_start(str) || is_end(str));
}

int		is_comment(char *str)
{
	int		len;

	if ((len = ft_strlen(str)) < 1 || is_cmd(str))
		return (0);
	if (str[0] != '#')
		return (0);
	return (1);
}

int		is_tub(char *str)
{
	int		digit;
	int		hash;
	int		i;

	digit = 0;
	hash = 0;
	i = -1;
	while (ft_isalnum(str[++i]) && str[i])
		digit = 1;
	if (str[i] == '-')
		hash = 1;
	while (ft_isalnum(str[++i]) && str[i])
		digit = 2;
	return (digit == 2 && hash == 1);
}

int		is_room(char *str)
{
	int		name;
	int		digit;
	int		spaces;
	int		i;

	name = 0;
	digit = 0;
	spaces = 0;
	i = -1;
	while (ft_isalnum(str[++i]) && str[i])
		name = 1;
	if (str[i] == ' ')
		spaces = 1;
	while (ft_isdigit(str[++i]) && str[i])
		digit = 1;
	if (str[i] == ' ')
		spaces = 2;
	while (ft_isdigit(str[++i]) && str[i])
		digit = 2;
	return (name == 1 && digit == 2 && spaces == 2);
}
