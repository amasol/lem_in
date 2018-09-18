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
	t_room rm;
	t_gl pr;

	pr.fd = open("test", O_RDONLY);
	pr.ants = 0;
	pr.start = 0;
//	while (get_next_line(pr.fd, &pr.line) > 0)
	while ((get_next_line(pr.fd, &pr.line) > 0) && i <= 7)
	{
		parsing(&pr, &rm);
		free(pr.line);
		i++;
	}
	return 0;
}
