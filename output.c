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

//функция которая ищет комнату по номеру итнрации гашей мурашки
//static char		*search_room(t_f_link *lst, int len)
//{
//	t_f_link *tmp;
//	int j;
//
//	j = 0;
//	tmp = lst;
//	while (j <= len && tmp != NULL)
//	{
//		if (j == len)
//			return (tmp->room_l);
//		tmp = tmp->next;
//		j++;
//	}
//	return (0);
//}

static void		ant_exit(t_ants *ants, t_gl *pr)
{
	t_ants *tmp;
	t_ants *ap;
	int i;

	i = 0;
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

static t_f_link		*search_room_list(t_f_link *link, long int who)
{
	t_f_link *tmp;

	tmp = link;
	while (tmp)
	{
		if (tmp->who == who)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int					one_room(t_link *lst, t_gl *pr)
{
	t_f_link *link;
	t_ants *ants;

	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
		return (0);
	link = lst->t_lk->next;
	ants = save_ants(ants, pr);

	while (ants->next)
	{
		if (ft_strcmp(link->room_l, pr->last->name_r) == 0)
			printf("L%ld-%s ", ants->who, pr->last->name_r);
		ants = ants->next;
	}
	return (0);
}


static void		substitution_output_help_two(t_ants **tmp,
				t_f_link **link)
{
	if ((*link)->access == 0 && (*tmp)->index == 0)
	{
		(*link)->access = 1;
		(*tmp)->index = 1;
		(*tmp)->was = (*link)->room_l;
		(*link)->who = (*tmp)->who;
		printf("L%ld-%s ", (*tmp)->who, (*link)->room_l);
	}
}

static void		substitution_output_help(t_ants **tmp,
				t_f_link **link, t_ants **ants,t_gl **pr)
{
	if ((*link)->access == 1 && (*tmp)->index == 1 && (*tmp)->who != -1)
	{
		(*link) = search_room_list((*link), (*tmp)->who);
		if ((*tmp)->next != NULL)
			(*link)->access = 0;
		(*tmp)->index = 0;
		(*link)->who = 0;
		(*link) = (*link)->next;
		(*link)->access = 1;
		(*tmp)->index = 1;
		(*tmp)->was = (*link)->room_l;
		(*link)->who = (*tmp)->who;
		printf("L%ld-%s ", (*tmp)->who, (*link)->room_l);
		ant_exit((*ants), (*pr));
		if ((*link)->next == NULL)
			(*tmp)->who = -1;
	}
}

//функция которая выводит все в правильном порядке !
int 		substitution_output(t_link *lst, t_gl *pr)
{
	t_f_link *link;
	t_f_link *l_tmp;
	t_ants *ants;
	t_ants *tmp;

	link = lst->t_lk->next;
	l_tmp = lst->t_lk->next;
	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
		return (0);
	link->access = 0;
	ants = save_ants(ants, pr);
	tmp = ants;
	while (pr->close != 1)
	{
		while (tmp)
		{
			if (link->access == 0 && tmp->index == 0)
				substitution_output_help_two(&tmp, &link);
			else if (link->access == 1 && tmp->index == 1 && tmp->who != -1)
				substitution_output_help(&tmp, &link, &ants, &pr);
			tmp = tmp->next;
			link = l_tmp;
		}
		printf("\n");
		tmp = ants;
	}
	return (0);
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






//int 		substitution_output(t_link *lst, t_gl *pr)
//{
//	t_f_link *link;
//	t_f_link *l_tmp;
//	t_ants *ants;
//	t_ants *tmp;
//
//	link = lst->t_lk->next;
//	l_tmp = lst->t_lk->next;
//	if (!(ants = (t_ants*)malloc(sizeof(t_ants))))
//		return (0);
//	link->access = 0;
//	ants = save_ants(ants, pr);
//	tmp = ants;
//	while (pr->close != 1)
//	{
//		while (tmp)
//		{
//			if (link->access == 0 && tmp->index == 0)
//			{
//				link->access = 1;
//				tmp->index = 1;
//				tmp->was = link->room_l;
//				link->who = tmp->who;
//				printf("L%ld-%s ", tmp->who, link->room_l);
//			}
//			else if (link->access == 1 && tmp->index == 1 && tmp->who != -1)
//			{
//				link = search_room_list(link, tmp->who);
//				if (tmp->next != NULL)
//					link->access = 0;
//				tmp->index = 0;
//				link->who = 0;
//				link = link->next;
//				link->access = 1;
//				tmp->index = 1;
//				tmp->was = link->room_l;
//				link->who = tmp->who;
//				printf("L%ld-%s ", tmp->who, link->room_l);
//				ant_exit(ants, pr);
//				if (link->next == NULL)
//					tmp->who = -1;
//			}
//			tmp = tmp->next;
//			link = l_tmp;
//		}
//		printf("\n");
//		tmp = ants;
//	}
//	return (0);
//}
//void			output(t_link *search)
//{
//
//	if (search->skipping_two == 1)
//	{
//		error();
//	}
//}

