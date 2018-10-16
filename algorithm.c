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

static int			*search_connection_left(t_link **tmp, t_link **search,
						t_link **tmp_sr)
{
//	(*tmp)->last = NULL;
	(*tmp_sr)->index = 1;
	(*tmp) = search_help((*tmp));
	if (!((*tmp)->next = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	(*tmp) = (*tmp)->next;
	(*tmp)->next = NULL;
	(*tmp)->last = NULL;
	(*tmp)->count = 1;
	(*tmp)->count += (*search)->count;
	(*tmp)->room_next = (*tmp_sr)->name_l_two;
//	(*search)->last = NULL;
	(*tmp)->last = (*search);
	return (0);
}

static int			*search_connection_right(t_link **tmp, t_link **search,
						t_link **tmp_sr)
{
//	(*tmp)->last = NULL;
	(*tmp_sr)->index = 1;
	(*tmp) = search_help((*tmp));
	if (!((*tmp)->next = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	(*tmp) = (*tmp)->next;
	(*tmp)->count = 1;
	(*tmp)->count += (*search)->count;
	(*tmp)->next = NULL;
	(*tmp)->last = NULL;
	(*tmp)->room_next = (*tmp_sr)->name_l_one;
//	(*search)->last = NULL;
	(*tmp)->last = (*search);
	return (0);
}

static	t_f_link		*search_connection_end(t_f_link **end, char
							**last_room, t_link **tmp)
{
	(*end) = check_end((*last_room), (*tmp));
	if ((*end) != NULL && (*end)->last_room == 1)
		return ((*end));
	return (NULL);
}

static t_f_link			*search_connection(t_link *sr, t_link *search,
											  char *last_room)
{
	t_link *tmp;
	t_link *tmp_sr;
	t_f_link *end;

	tmp = search;
	tmp_sr = sr;
	while (tmp_sr && tmp && end == NULL)
	{
		while (tmp_sr->next && tmp_sr->index == 1)
			tmp_sr = tmp_sr->next;
		if (tmp_sr->index == 1)
			return (NULL);
		if ((ft_strcmp(search->room_next, tmp_sr->name_l_one) == 0)
			&& tmp->last_room != 1)
		{
			search_connection_left(&tmp, &search, &tmp_sr);
			end = search_connection_end(&end, &last_room, &tmp);
//			end = check_end(last_room, tmp);
//			if (end != NULL && end->last_room == 1)
//				return (end);
		}
		else if ((ft_strcmp(search->room_next, tmp_sr->name_l_two) == 0)
				 && tmp->last_room != 1)
		{
			search_connection_right(&tmp, &search, &tmp_sr);
			end = check_end(last_room, tmp);
			if (end != NULL && end->last_room == 1)
				return (end);
		}
		if (tmp_sr->next && end == NULL)
			tmp_sr = tmp_sr->next;
//		else
//			return (NULL);
	}
	return (end);
}

t_link			*algorithm(t_gl *pr, t_room *map)
{
	t_link *search;
	t_link *tmp;
	t_f_link *search_tmp;

	if (!(search = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	search_tmp = NULL;
	initialization(&search);
	search->room_next = ft_strdup(pr->first->name_r);
	search->next = NULL;
//	free(search->room_next);
	tmp = search;
	while (tmp)
	{
		search_tmp = search_connection(pr->link, tmp, pr->last->name_r);
		if (search_tmp != NULL && search_tmp->last_room == 1)
			break ;
		tmp = tmp->next;
	}
	if (search_tmp == NULL)
		error();
	definition_short(search_tmp, pr, map);
	lst_file_del_el(&search_tmp);
	lst_file_del_el_two(&search);
	return (NULL);
}
