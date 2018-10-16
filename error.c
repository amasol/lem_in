/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:30:44 by amasol            #+#    #+#             */
/*   Updated: 2018/09/18 12:30:48 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		error(void)
{
	ft_putstr("Error validation\n");
	exit(1);
}

void		error_word(t_room *rm)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = rm->tmp;
	while (tmp[i])
	{
		if (ft_isalpha(tmp[i]))
			error();
		i++;
	}
	check_symbol(rm);
}

void		check_error(t_gl *pr)
{
	if (*pr->line == '#' && *(pr->line + 1) == '#'
			&& *(pr->line + 2) == '#')
		error();
}

void		check_symbol(t_room *rm)
{
	char	*tmp;

	tmp = rm->tmp;
	while (*tmp)
	{
		if (*tmp == '/' || *tmp == ':' || *tmp == ';'
			|| *tmp == '$' || *tmp == '%'
			|| *tmp == '[' || *tmp == ']' || *tmp == '=' || *tmp == '+'
			|| *tmp == '-' || *tmp == '(' || *tmp == ')' || *tmp == '&')
			error();
		tmp++;
	}
}
