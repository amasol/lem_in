/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 04:43:04 by amasol            #+#    #+#             */
/*   Updated: 2018/09/24 04:43:05 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		algorithm(t_gl *pr)
{
	t_room *search_r;
	t_room *tmp;

	search_r = pr->rms;
	tmp = pr->first;
//	pr->queue = pr->link;
	while (search_r != NULL)
	{
//		save_connection(pr);
		tmp->name_r = search_connection(pr);
		search_r = search_r->next;
//		pr->queue= pr->queue->next;
	}
}

char		*search_connection(t_gl *pr)
{
	t_link *tmp_sr;
	t_link *tmp;

	tmp_sr = pr->link;
	tmp = pr->link;
	while (tmp_sr)
	{
		if ((ft_strcmp(pr->first->name_r, tmp_sr->name_l_one) == 0) && pr->link->skipping != 1)
		{
			pr->link->skipping = 1;
			pr->link = tmp;
			return (tmp_sr->name_l_two);
		}
		else if ((ft_strcmp(pr->first->name_r, tmp_sr->name_l_two) == 0) && pr->link->skipping != 1)
		{
			pr->link->skipping = 1;
			pr->link = tmp;
			return (tmp_sr->name_l_one);
		}
		tmp_sr = tmp_sr->next;
		pr->link = pr->link->next;
	}
	return (NULL);
}

//void			save_connection( t_gl *pr)
//{
//	pr->queue->next = (t_link *)malloc(sizeof(t_link));
//	pr->queue->step = pr->first->name_r;
//	pr->queue = pr->queue->next;
//}
