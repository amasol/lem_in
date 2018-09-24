/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 18:51:18 by amasol            #+#    #+#             */
/*   Updated: 2018/09/23 18:51:19 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_start_h_s(t_gl *pr)
{
	if (ft_strcmp("##start", pr->line) == 0)
	{
		if (pr->start_h == 1)
			error();
		pr->start_h = 1;
		pr->check_st_en = 1;
		pr->start += 1;
	}
}

void		check_start_h_e(t_gl *pr)
{
	if (ft_strcmp("##end", pr->line) == 0)
	{
		if (pr->end_h == 1)
			error();
		pr->end_h = 1;
		if (pr->check_st_en == 1)
			error();
		pr->end += 1;
	}
}

void		check_start_h_com(t_gl *pr)
{
	int i;

	i = 0;
	if (pr->line[i] == '#' && pr->line[i + 1] == '#')
	{
		if (ft_isalpha(pr->line[i + 2]) || ft_isdigit(pr->line[i + 2]))
			pr->com = 1;
	}
}

t_room		*create_room(t_room **rm)
{
	t_room *rms;

	if (!rm)
		return (NULL);
	if (!(rms = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	rms->next = *rm;
	*rm = rms;
	return (rms);
}

t_link		*create_link(t_link **rm)
{
	t_link	*link;

	if (!rm)
		return (NULL);
	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	link->next = *rm;
	*rm = link;
	return (link);
}
