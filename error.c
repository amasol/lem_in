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

void		extra_lines(t_gl *pr)
{
	int i;

	i = 0;
	while (pr->line[i] != '\0')
	{
		if (ft_isalpha(pr->line[i]))
		{
			ft_putstr("Error validation\n");
			exit(1);
		}
		i++;
	}
}

void		not_vld_word(t_gl *pr)
{
	int i;

	i = 0;
	if (*pr->line != '#' && *(pr->line + 1) != '#')
	{
		while (pr->line[i] != '\0')
		{
			if (ft_isalpha(pr->line[i]) || pr->ants > 1)
			{
				ft_putstr("Error validation\n");
				exit(1);
			}
			i++;
		}
	}
}

void		error()
{
	ft_putstr("Error validation\n");
	exit(1);
}

void		error_check(t_gl *pr)
{
	int i;

	i = 0;
	if (pr->line[i] == '#' && pr->line[i + 1] == '#')
	ft_putstr("Error validation\n");
	exit(1);
}

void		error_word(t_room *rm)
{
	int i;
	char *tmp;

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

void		line_l(t_gl *pr)
{
	if (pr->line && *pr->line == 'L')
	{
		ft_putstr("Error validation\n");
		exit(1);
	}
}

int			error_st_end(t_gl *pr)
{
	if (pr->first == NULL || pr->last == NULL)
		error();
	return (0);
}