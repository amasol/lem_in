/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:02:06 by amasol            #+#    #+#             */
/*   Updated: 2018/09/15 17:02:07 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		zero(t_gl *pr)
{
	pr->ants = 0;
	pr->start = 0;
	pr->end = 0;
	pr->go_link = 0;
	pr->rms = NULL;
	pr->link = NULL;
	pr->link_yes = 0;
	pr->first = NULL;
	pr->last = NULL;
	pr->ants_flag = 1;
	pr->space = 0;
	pr->close = 0;
	pr->end_of_file = 0;
	pr->start_let = 0;
	pr->end_let = 0;
	pr->check_map = 0;
}

static void		pass(t_gl *pr)
{
	if (*pr->line == '\0')
	{
		if (get_next_line(pr->fd, &pr->line) > 0)
		{
			if (*pr->line == '\0')
				pr->end_of_file = 1;
			else
				error();
		}
		else
			pr->end_of_file = 1;
	}
}

int			main(void)
{
	t_gl *pr;
	t_room *map;
	t_room *tmp;

	map = create_map(&(map));
	tmp = map;
	pr->fd = open("test1", O_RDONLY);
	zero(pr);
	while (get_next_line(pr->fd, &pr->line) > 0)
	{
		if (*pr->line == '\0')
			pass(pr);
		if (pr->end_of_file != 1)
		{
			map = save_map(pr, map);
			parsing(pr);
		}
//		free(pr->line);
	}
	if (pr->first == NULL || pr->last == NULL)
		error();
	comparison_link_dop(pr);
	comparison_line(pr);
	comparison_link(pr);
	error_st_end(pr);
	algorithm(pr, tmp);
//	cleaning_leaks(pr, map);
	return (0);
}


//void		cleaning_leaks(t_gl *pr, t_room *map)
//{
//	int i;
//
//	i = 0;
//	while (map)
//	{
//		free(map->tmp);
//		map = map->next;
//	}
//	free (map);
//}