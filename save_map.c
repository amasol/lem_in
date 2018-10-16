/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 02:53:04 by amasol            #+#    #+#             */
/*   Updated: 2018/09/24 02:53:05 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*save_map(t_gl *pr, t_room *map)
{
	t_room *map_save;

	map->next = NULL;
	map_save = map;
	if (map_save)
	{
		map_save->tmp = ft_strdup(pr->line);
		if (!(map_save->next = (t_room *)malloc(sizeof(t_room))))
			return (NULL);
		map_save = map_save->next;
		map_save->next = NULL;
	}
	return (map_save);
}

t_room		*create_map(t_room **rm)
{
	t_room	*map;

	if (!rm)
		return (NULL);
	if (!(map = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	map->next = *rm;
	*rm = map;
	return (map);
}
