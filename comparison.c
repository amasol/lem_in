/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 19:07:45 by amasol            #+#    #+#             */
/*   Updated: 2018/09/23 19:07:45 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_cmp(t_room *tmp, t_room *first_tmp)
{
	if (ft_strcmp(first_tmp->name_r, tmp->name_r) == 0)
		error();
	if (first_tmp->x == tmp->x && first_tmp->y == tmp->y)
		error();
}

int				comparison_line(t_gl *pr)
{
	t_room *tmp;
	t_room *first_tmp;

	tmp = pr->rms->next;
	first_tmp = pr->rms;
	while (first_tmp)
	{
		while (first_tmp && tmp)
		{
			if (tmp == first_tmp)
			{
				if (tmp->next)
					tmp = tmp->next;
				else
					return (0);
			}
			check_cmp(tmp, first_tmp);
			tmp = tmp->next;
		}
		tmp = pr->rms;
		first_tmp = first_tmp->next;
	}
	return (0);
}

int				comparison_link(t_gl *pr)
{
	t_room *tmp;
	t_link *first_tmp;
	int i;

	first_tmp = pr->link;
	while (first_tmp)
	{
		i = 0;
		tmp = pr->rms;
		while (first_tmp && tmp)
		{
			if (ft_strcmp(first_tmp->name_l_one, tmp->name_r) == 0
				|| ft_strcmp(first_tmp->name_l_two, tmp->name_r) == 0)
				i++;
			tmp = tmp->next;
		}
		if (i < 2)
			error();
		first_tmp = first_tmp->next;
	}
	return (0);
}

int				comparison_room_link(t_gl *pr, char *tmp)
{
	t_room *first_tmp;

	first_tmp = pr->rms;
	while (first_tmp)
	{
		while (first_tmp && tmp)
		{
			if (ft_strcmp(first_tmp->name_r, tmp) == 0)
			{
				if (pr->link->one == 0)
				{
					pr->link->one = 1;
					pr->link->name_l_one = ft_strdup(tmp);
				}
				else if (pr->link->two == 0)
				{
					pr->link->two = 1;
					pr->link->name_l_two = ft_strdup(tmp);
				}
				return (1);
			}
			first_tmp = first_tmp->next;
		}
	}
	return (0);
}

int				comparison_link_dop(t_gl *pr)
{
	t_link *check;
	t_link *go;


	check = pr->link;
	while (check)
	{
		go = pr->link;
		while (go && check)
		{
			if (go == check)
				go = go->next;
			else if (ft_strcmp(check->tmp, go->tmp) == 0)
				error();
			if (go && go->next)
				go = go->next;
			else
				break;
		}
		check = check->next;
	}
	return (0);
}
