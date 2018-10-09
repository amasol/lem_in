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

static void		check_end(t_gl *pr, t_link *search_tmp)
{
	if (ft_strcmp(pr->first->name_r, pr->last->name_r) == 0)
		search_tmp->step = 1;
}

static int			search_connection(t_gl *pr, t_link *search_tmp, t_f_link **f_l)
{
	t_link *tmp_sr;
	t_link *tmp;

	tmp_sr = pr->link;
	tmp = pr->link;
	while (tmp_sr && search_tmp->step != 1)
	{
		if ((ft_strcmp(pr->first->name_r, tmp_sr->name_l_one) == 0) && tmp_sr->skipping != 1)
		{
			tmp_sr->skipping = 1;
			search_tmp->start_let++;
			pr->first->name_r = tmp_sr->name_l_two;
			check_end(pr, search_tmp);
			pr->link = tmp;
			save_way(tmp_sr->name_l_two, f_l);
			return (search_tmp->start_let);
		}
		else if ((ft_strcmp(pr->first->name_r, tmp_sr->name_l_two) == 0) && tmp_sr->skipping != 1)
		{
			search_tmp->start_let++;
			tmp_sr->skipping = 1;
			pr->first->name_r = tmp_sr->name_l_one;
			check_end(pr, search_tmp);
			pr->link = tmp;
			save_way(tmp_sr->name_l_one, f_l);
			return (search_tmp->start_let);
		}
		tmp_sr = tmp_sr->next;
		pr->link = pr->link->next;
	}
	if (search_tmp->skipping == 0)
		search_tmp->skipping_two = 1;
	pr->link = tmp;
	return (search_tmp->start_let);
}



static int		create_search_connection(t_link *search_tmp)
{
	if (!(search_tmp->t_lk = (t_f_link *)malloc(sizeof(t_f_link))))
		return (0);
	return (0);
}

static void		initialization(t_link *search_tmp)
{
	search_tmp->step = 0;
	search_tmp->start_let = 0;
	search_tmp->skipping = 0;
	search_tmp->skipping_two = 0;
	search_tmp->search_short = 0;
}


t_link			*algorithm(t_gl *pr)
{
	t_link *search_tmp;
	t_link *tmp;
	t_f_link *f_l;
	char *str;

	if (!(search_tmp = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	tmp = search_tmp;
	str = ft_strdup(pr->first->name_r);
	while (search_tmp && search_tmp->start_let != -1)
	{
		initialization(search_tmp);
		create_search_connection(search_tmp);
		f_l = search_tmp->t_lk;
		search_tmp->t_lk->room_l = ft_strdup(pr->first->name_r);
		while (search_tmp->step != 1 && search_tmp->start_let != -1 && search_tmp ->skipping_two != 1)
		{
			search_tmp->start_let = search_connection(pr, search_tmp, &f_l);
			if (search_tmp->start_let == 0)
				search_tmp->start_let = -1;
		}
		if (search_tmp->start_let != -1 )
		{
			pr->first->name_r = str;
			if (!(search_tmp->next = (t_link *)malloc(sizeof(t_link))))
				return (NULL);
			search_tmp = search_tmp->next;
		}
	}
	definition_short(tmp, pr);
	return (search_tmp);
}

int			save_way(char *str, t_f_link **f_l)
{
	if (!((*f_l)->next = (t_f_link *)malloc(sizeof(t_f_link))))
		return (0);
	if ((*f_l)->next)
	{
		(*f_l) = (*f_l)->next;
		(*f_l)->room_l = ft_strdup(str);
	}
	return (0);
}

int			definition_short(t_link *search_tmp, t_gl *pr)
{
	t_link *tmp;
	t_link *result;

	tmp = search_tmp;
	if (tmp->next)
	{
		while (tmp->skipping_two == 1)
		{
			if (tmp->next == NULL)
			{
				error();
				return (1);
			}
			tmp = tmp->next;
		}
		result = search_short(tmp);
		if (result->step != 1)
			error();
		result->search_short = 1;
		substitution_output(result, pr);
	}
	return (0);
}

// функция котора ищет самый которкий пусть !
t_link		*search_short(t_link *search_tmp)
{
	t_link *search;
	t_link *found;

	search = search_tmp;
	found = search_tmp;
	if (search_tmp->start_let > search->next->start_let)
	{
		if (search->next->next == NULL)
			return (search_tmp);
	}
	while (search->next)
	{
		while (search->skipping_two == 1)
			search = search->next;
		if ((search->start_let > search->next->start_let &&
			search->next->skipping_two != 1)
			&& search->next->skipping_two != 1)
		{
			if (found->start_let > search->start_let)
				found = search->next;
		}

		search = search->next;
	}
	return (found);
}















// функция котора ищет самый которкий пусть !
//t_link		*search_short(t_link *search_tmp)
//{
//	t_link *search;
//	t_link *found;
//
//	search = search_tmp;
//	if (search_tmp->start_let > search->next->start_let)
//	{
//		if (search->next->next == NULL)
//			return (search_tmp);
//	}
//	while (search->next && search->skipping_two != 1)
//	{
//		if ((search->start_let > search->next->start_let)
//			&& search->next->skipping_two != 1)
//		{
//			if (found->start_let < search->next->start_let)
//				;
//			else
//				found = search->next;
//		}
//		else if ((search->start_let < search->next->start_let)
//				 && search->next->skipping_two != 1)
//			found = search;
//		search = search->next;
//	}
//	return (found);
//}

























// попытка оотсортировать листы !
//t_link		*search_short(t_link *search_tmp)
//{
//	t_link *search;
//	t_link *tmp;
//	t_link *tmp1;
//
//	search = search_tmp;
//	while (search->next)
//	{
//		while (search->skipping_two == 1)
//			search = search->next;
//		if (search->next->skipping_two == 1 && search->next->next == NULL)
//			break;
//		if (search->start_let > search->next->start_let)
//		{
//			tmp = search;
//			tmp1 = search->next;
//
//			tmp->next = tmp1->next;
//			tmp1->next = tmp;
//			search = tmp1;
//			search_tmp = search;
//		}
//		search = search->next;
//	}
//	return (search_tmp);
//}
//
//
//