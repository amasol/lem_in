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

	pr.fd = open("test", O_RDONLY);
	pr.ants = 0;
	pr.start = 0;
	pr.end = 0;
	pr.go_link = 0;
//	while (get_next_line(pr.fd, &pr.line) > 0)
	pr.rms = NULL;
	pr.link = NULL;
	while ((get_next_line(pr.fd, &pr.line) > 0) && i <= 30)
//	while (get_next_line(pr.fd, &pr.line) > 0)
	{
		if (*pr.line == '\0')
			error();
		parsing(&pr);
//		printf("%s\n",pr.map);
		free(pr.line);
		i++;
	}
	comparison_link_dop(&pr);
	comparison_line(&pr);
	comparison_link(&pr);
	error_st_end(&pr);
//	valid_st_end(&pr);
//	while (1);
//	printf("%s\n", rm->name_r);
//	printf("%d\n", rm->x);
//	printf("%d\n", rm->y);
	return 0;
}
