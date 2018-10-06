/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 19:08:39 by amasol            #+#    #+#             */
/*   Updated: 2018/10/02 19:08:41 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*search_room(t_f_link *lst, int len)
{
	t_f_link *tmp;
	int j;

	j = 0;
	tmp = lst;
	while (j <= len && tmp != NULL)
	{
		if (j == len)
			return (tmp->room_l);
		tmp = tmp->next;
		j++;
	}
	return (0);
}


int 		substitution_output(t_link *lst, t_gl *pr)
{
	t_f_link *link;
	t_ants *ants;
	t_ants *tmp;
//	long int i;
	char *str;

	link = lst->t_lk->next;
	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
		return (0);
//	lst->index = 0;
//	i = pr->ants;

	link->access = 0;
	ants = save_ants(ants, pr);
	tmp = ants;
	while (tmp)
	{
		while (tmp)
		{
			if (link->access == 0 && tmp->index == 0)
			{
				link->access = 1;
				tmp->index = 1;
				printf("L%ld-%s ", tmp->who, link->room_l);
			}
			printf("\n");
			tmp = tmp->next;
		}
		tmp = ants;
	}





//	while (tmp)
//	{
//		if (tmp->index >= 0 && str != NULL)
//		{
//			str = search_room(link, tmp->index);
//			if (str == NULL)
//				break ;
//			printf("L%ld-%s ", tmp->who, str);
//			tmp->index++;
//		}
//		printf("\n");
//		tmp = tmp->next;
//	}
	return (0);
}

void			output(t_gl *pr, t_link *search)
{
	t_link *tmp;

	tmp = search;
	if (pr || search || tmp)
		;
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
		ants->was = 0;
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
