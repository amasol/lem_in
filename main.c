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
//	pr->way = 0;
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
	t_link *search;

	pr->fd = open("test1", O_RDONLY);
	zero(pr);
	while (get_next_line(pr->fd, &pr->line) > 0)
	{
		if (*pr->line == '\0')
			pass(pr);
		if (pr->end_of_file != 1)
		{
			save_map(pr);
			parsing(pr);
		}
//		free(pr.line);
	}
	if (pr->first == NULL || pr->last == NULL)
		error();
	comparison_link_dop(pr);
	comparison_line(pr);
	comparison_link(pr);
	error_st_end(pr);

//	search = algorithm(&pr);
	algorithm(pr);
//	output(search);
	return (0);
}
