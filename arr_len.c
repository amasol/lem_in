/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 19:38:09 by amasol            #+#    #+#             */
/*   Updated: 2018/09/20 19:38:17 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 		arr_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			num_spac(t_gl *pr)
{
	int i;

	i = 0;
	pr->space = 0;
	while (pr->line[i])
	{
		while (pr->line[i] == ' ')
		{
			pr->space++;
			i++;
		}
		i++;
	}
	return (pr->space);
}

void		check_xy(char *tmp)
{
	int i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
			i++;
		else
			error();
	}
}

int		check_link_no_room(t_gl *pr)
{
	num_spac(pr);
	if (pr->space < 2)
	{
		pr->go_link = 1;
		return (1);
	}
	return (0);
}