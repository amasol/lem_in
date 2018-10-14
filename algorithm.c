/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 04:43:04 by amasol            #+#    #+#             */
/*   Updated: 2018/09/24 04:43:05 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_link			*search_help(t_link *tmp)
{
	if (!tmp)
		return 0;
	while (tmp && tmp->next) //какая то фигня с выделением памяти !!! ломаеться 1 раз с 4...
		tmp = tmp->next;
	return (tmp);
}




static int			*search_connection_left(t_link **tmp, t_link **search,
						t_link **tmp_sr)
{
	(*tmp_sr)->index = 1;
	(*tmp) = search_help((*tmp));
	if (!((*tmp)->next = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	(*tmp) = (*tmp)->next;
	(*tmp)->count = 1;
	(*tmp)->count += (*search)->count;
	(*tmp)->next = NULL;
	(*tmp)->room_next = (*tmp_sr)->name_l_two;
	if (!((*tmp)->last = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	(*tmp)->last = (*search);
	return (0);
}



static int			*search_connection_right(t_link **tmp, t_link **search,
											   t_link **tmp_sr)
{
	(*tmp_sr)->index = 1;
	(*tmp) = search_help((*tmp));
	if (!((*tmp)->next = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	(*tmp) = (*tmp)->next;
	(*tmp)->count = 1;
	(*tmp)->count += (*search)->count;
	(*tmp)->next = NULL;
	(*tmp)->room_next = (*tmp_sr)->name_l_one;
	if (!((*tmp)->last = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	(*tmp)->last = (*search);
	return (0);
}

static t_f_link			*search_connection(t_link *sr, t_link *search,
							char *last_room)
{
	t_link *tmp;
	t_link *tmp_sr;
	t_f_link *end;

	tmp = search;
	tmp_sr = sr;
	while (tmp_sr && tmp)
	{
		while (tmp_sr->next && tmp_sr->index == 1)
			tmp_sr = tmp_sr->next;
		if (tmp_sr->index == 1)
			return (NULL);
		if ((ft_strcmp(search->room_next, tmp_sr->name_l_one) == 0)
					&& tmp->last_room != 1)
		{
			search_connection_left(&tmp, &search, &tmp_sr);
			end = check_end(last_room, tmp);
			if (end != NULL && end->last_room == 1)
				return (end);
		}
		else if ((ft_strcmp(search->room_next, tmp_sr->name_l_two) == 0)
					&& tmp->last_room != 1)
		{
			search_connection_right(&tmp, &search, &tmp_sr);
			end = check_end(last_room, tmp);
			if (end != NULL && end->last_room == 1)
				return (end);
		}
		if (tmp_sr->next)
			tmp_sr = tmp_sr->next;
		else
			return (NULL);
	}
	if (end->last_room != 1)
		error();
	return (NULL);
}



























t_link			*algorithm(t_gl *pr, t_room *map)
{
	t_link *search;
	t_f_link *search_tmp;
	t_link *ss;

	if (!(search = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	initialization(search);
	search->room_next = ft_strdup(pr->first->name_r);
	ss = pr->link;
	while (search)
	{
		search_tmp = search_connection(ss, search, pr->last->name_r);
		if (search_tmp != NULL && search_tmp->last_room == 1)
			break ;
		search = search->next;
	}
	if (search_tmp == NULL)
		error();
	definition_short(search_tmp, pr, map);
	return (NULL);
}

int			definition_short(t_f_link *search_tmp, t_gl *pr, t_room *map)
{
		output_map(map);
		if (ft_strcmp(search_tmp->next->room_l, pr->last->name_r) == 0)
			one_room(search_tmp, pr);
		else
			substitution_output(search_tmp, pr);
	return (0);
}







