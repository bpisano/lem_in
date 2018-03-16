/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 12:49:24 by bpisano      #+#   ##    ##    #+#       */
/*   Updated: 2018/03/16 14:13:34 by bpisano     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "lem-in.h"

int		is_ants(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		is_command(char *str)
{

}


char	**read_file()
{
	int		i;
	char	**str;

	MALLCHECK(str = (char **)malloc(sizeof(char *)));
	i = 0;
	while (get_next_line(0) > 0)
	{
		str = ft_realloc(str, ++i + 1);
		str[i] = MALLCHECK(ft_strdup(line));
	}
	str[i] = NULL;
	return (str);
}

void	parse_data(t_data *data)
{
	char	**rooms;
	char	**tubs;
	char	**str;
	int		i;

	MALLCHECK(rooms = (char **)malloc(sizeof(char *)));
	MALLCHECK(tubs = (char **)malloc(sizeof(char *)));
	MALLCHECK(str = read_file());
	i = -1;
	while (str[++i])
	{
		if (is_ants(str[i]))
			data->ants = ft_atoi(str[i]);
		else if (is_command(str[i]))
			set_command(data, str[i], str[i + 1]);
		else if (is_comment(str[i]))
			i = i;
		else if (is_room(str[i]))
			add_room(data, str + i);
		else
			return ;
	}
}
