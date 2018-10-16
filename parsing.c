/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:00:02 by amasol            #+#    #+#             */
/*   Updated: 2018/09/15 17:00:08 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		comment(t_gl *pr)
{
	if (*pr->line == '#' && *(pr->line + 1) != '#')
		pr->com = 1;
}

int				parsing(t_gl *pr)
{
	pr->com = 0;
	pr->ants_flag = 0;
	if (pr->line)
		check_error(pr);
	if (*pr->line == '#' && *(pr->line + 1) != '#')
		comment(pr);
	else if (pr->ants == 0)
		ants_num(pr);
	if (*pr->line == '#' && *(pr->line + 1) == '#')
		check_start(pr);
	else if (pr->com == 0 && pr->go_link == 0 && pr->ants_flag == 0)
		check_room(pr);
	if (pr->go_link == 1 && pr->com == 0)
		check_link(pr);
	return (1);
}

void			ants_num(t_gl *pr)
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
	i = 0;
	if (pr->line[i])
	{
		pr->ants_flag = 1;
		pr->ants = ft_atoi(pr->line);
		if (pr->ants < 0 || pr->ants == 0)
		{
			ft_putstr("Error validation\n");
			exit(1);
		}
	}
}

void			check_start(t_gl *pr)
{
	int i;

	i = 0;
	if (pr->line[i] == '#' && pr->line[i + 1] == '#'
			&& pr->line[i + 2] != '#')
	{
		if (ft_strcmp("##start", pr->line) == 0)
			check_start_h_s(pr);
		else if (ft_strcmp("##end", pr->line) == 0)
			check_start_h_e(pr);
		else if (pr->line[i] == '#' && pr->line[i + 1] == '#')
			check_start_h_com(pr);
	}
	else
		error();
}
