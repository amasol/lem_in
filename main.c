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

int			main(void)
{
	t_gl pr;

	pr.fd = open("test1", O_RDONLY);
	zero(&pr);
	while (get_next_line(pr.fd, &pr.line) > 0)
	{
		save_map(&pr);
		if (*pr.line == '\0') //если файла нету то error, а если в конце просто пустые строки то это нормально !!!
			error();
//		else if (*pr.line == NULL)
//			close (1);
		parsing(&pr);
		free(pr.line);
	}
	if (pr.first == NULL || pr.last == NULL)
		error();
	comparison_link_dop(&pr);
	comparison_line(&pr);
	comparison_link(&pr);
	error_st_end(&pr);

	algorithm(&pr);

//	while (1);
	return 0;
}

void		zero(t_gl *pr)
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
}