/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:52:21 by amasol            #+#    #+#             */
/*   Updated: 2018/10/14 19:52:24 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link			*search_help(t_link *tmp)
{
	if (!tmp)
		return (0);
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

int				definition_short(t_f_link *search_tmp, t_gl *pr, t_room *map)
{
	if (search_tmp->last_room != 1)
		error();
	output_map(map);
	if (ft_strcmp(search_tmp->next->room_l, pr->last->name_r) == 0)
		one_room(search_tmp, pr);
	else
		substitution_output(search_tmp, pr);
	return (0);
}

void			initialization(t_link **search)
{
	(*search)->last_room = 0;
	(*search)->index = 0;
	(*search)->count = 0;
	(*search)->line = 0;
}

t_f_link		*end_algorithm(t_link *search, t_f_link *end_link)
{
	t_f_link *tmp;

	if (!(end_link = (t_f_link *)malloc(sizeof(t_f_link))))
		return (0);
	end_link->next = NULL;
	tmp = end_link;
	while (search)
	{
		if (search->room_next)
			end_link->room_l = ft_strdup(search->room_next);
		if (search->last)
		{
			if (!(end_link->next = (t_f_link *)malloc(sizeof(t_f_link))))
				return (NULL);
			end_link = end_link->next;
			end_link->next = NULL;
		}
		search = search->last;
	}
	return (tmp);
}

t_f_link		*check_end(char *last_room, t_link *search_tmp)
{
	t_f_link *end_link;

	if (ft_strcmp(search_tmp->room_next, last_room) == 0)
	{
		end_link = end_algorithm(search_tmp, end_link);
		ft_list_reverse(&end_link);
		end_link->last_room = 1;
		return (end_link);
	}
	return (0);
}
