/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_help.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:43:14 by amasol            #+#    #+#             */
/*   Updated: 2018/10/14 19:43:17 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ant_exit(t_ants *ants, t_gl *pr)
{
	t_ants *tmp;
	t_ants *ap;

	tmp = ants;
	while (tmp->next)
	{
		while (tmp->next)
			tmp = tmp->next;
		ap = tmp;
	}
	if (tmp->next == NULL)
		ap = tmp;
	if (ap->was)
	{
		if (ft_strcmp(ap->was, pr->last->name_r) == 0)
			pr->close = 1;
	}
}

int					one_room(t_f_link *lst, t_gl *pr)
{
	t_f_link *link;
	t_ants *ants;

	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
		return (0);
	link = lst->next;
	ants = save_ants(ants, pr);
	while (ants)
	{
		if (ft_strcmp(link->room_l, pr->last->name_r) == 0)
		{
			ft_putchar('L');
			ft_putnbr(ants->who);
			ft_putchar('-');
			ft_putstr(pr->last->name_r);
			ft_putchar(' ');
		}
		ants = ants->next;
	}
	return (0);
}

void			output_map(t_room *map)
{
	while (map)
	{
		ft_putstr(map->tmp);
		ft_putchar('\n');
//		free(map->tmp);
		map = map->next;
	}
}

static int		save_ants_h(t_ants **ants)
{
	if (!((*ants)->next = (t_ants *)malloc(sizeof(t_ants))))
		return (0);
	(*ants) = (*ants)->next;
	(*ants)->who = 0;
	return (0);
}

t_ants			*save_ants(t_ants *ants, t_gl *pr)
{
	t_ants *tmp;
	long int i;
	long int j;
	long int k;

	i = pr->ants;
	j = 0;
	k = 0;
	tmp = ants;
	ants->who = 1;
	while (i > j)
	{
		ants->end = 0;
		if (tmp->who == k && tmp->next->who != k)
			ants->who = k + 1;
		else if (ants->who == 0 && ants->next == NULL)
			ants->who = k + 1;
		if (i > j + 1)
			save_ants_h(&ants);
		k++;
		j++;
	}
	return (tmp);
}