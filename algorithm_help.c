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

void		initialization(t_link *search)
{
	search->step = 0;
	search->start_let = 0;
	search->skipping_two = 0;
	search->search_short = 0;
	search->last_room = 0;
	search->index = 0;
	search->count = 0;
	search->line = 0;
}

t_f_link		*end_algorithm(t_link *search)
{
	t_f_link *end;
	t_f_link *tmp;

	if (!(end = (t_f_link *)malloc(sizeof(t_f_link))))
		return (0);
	tmp = end;
	end->next = NULL;
	while (search != NULL)
//	while (search)
	{
		end->room_l = ft_strdup(search->room_next);
		if (!(end->next = (t_f_link *)malloc(sizeof(t_f_link))))
			return (NULL);
		end = end->next;
		search = search->last;
	}
	return (tmp);
}

void	reverse(t_f_link **list)
{
	t_f_link		*tmp;

	ft_list_reverse(list);
	tmp = (*list);
	(*list) = (*list)->next;
	free(tmp);
}

t_f_link		*check_end(char *last_room, t_link *search_tmp)
{
	t_f_link *end_link;

	if (ft_strcmp(search_tmp->room_next, last_room) == 0)
	{
		end_link = end_algorithm(search_tmp);
		reverse(&end_link);
		end_link->last_room = 1;
		return (end_link);
	}
	return (0);
}
