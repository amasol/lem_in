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

void		save_map(t_gl *pr)
{
	t_room *map_save;

	//как правильно почистить ft_strdup!!!!!!!!!!!!!!!!
	pr->map = create_map(&(pr->map));
	map_save = pr->map;
	if (map_save)
	{
		map_save->tmp = ft_strdup(pr->line);
//		free(pr->map->tmp);
	}
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
	if (!(map->tmp = (char *)malloc(sizeof(char))))
		return (NULL);
	return (map);
}
