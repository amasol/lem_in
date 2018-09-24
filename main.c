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
	int i = 1;
	t_gl pr;

	pr.fd = open("test3", O_RDONLY);
	zero(&pr);
	while (get_next_line(pr.fd, &pr.line) > 0)
//	while ((get_next_line(pr.fd, &pr.line) > 0) && i <= 33)
	{
		save_map(&pr);
		if (*pr.line == '\0')
			error();
		parsing(&pr);
		free(pr.line);
		i++;
	}
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
}