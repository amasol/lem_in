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
	pr.end = 0;
	pr.start = 0;
//	while (get_next_line(pr.fd, &pr.line) > 0)
	pr.rms = NULL;
	while ((get_next_line(pr.fd, &pr.line) > 0) && i <= 14)
	{
		parsing(&pr);
		printf("%s\n",pr.map);
		free(pr.line);
		i++;
	}
//	while (1);
//	printf("%s\n", rm->name_r);
//	printf("%d\n", rm->x);
//	printf("%d\n", rm->y);
	return 0;
}
