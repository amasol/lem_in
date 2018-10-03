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

t_link			*algorithm(t_gl *pr)
{
	t_link *search_tmp;
	t_link *tmp;
	char *str;

	if (!(search_tmp = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	tmp = search_tmp;
	str = ft_strdup(pr->first->name_r);
	while (search_tmp && search_tmp->start_let != -1)
	{
		search_tmp->step = 0;
		search_tmp->start_let = 0;
		search_tmp->skipping = 0;
		search_tmp->skipping_two = 0;
		search_tmp->way = ft_strsplit(pr->first->name_r, '\0');
		while (search_tmp->step != 1 && search_tmp->start_let != -1 && search_tmp ->skipping_two != 1)
		{
			search_tmp->start_let = search_connection(pr, search_tmp);
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
	definition_short(tmp);
	return (search_tmp);
}

int			search_connection(t_gl *pr, t_link *search_tmp)
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
			save_way(search_tmp, tmp_sr->name_l_two);
			return (search_tmp->start_let);
		}
		else if ((ft_strcmp(pr->first->name_r, tmp_sr->name_l_two) == 0) && tmp_sr->skipping != 1)
		{
			search_tmp->start_let++;
			tmp_sr->skipping = 1;
			pr->first->name_r = tmp_sr->name_l_one;
			check_end(pr, search_tmp);
			pr->link = tmp;
			save_way(search_tmp, tmp_sr->name_l_one);
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

void		check_end(t_gl *pr, t_link *search_tmp)
{
	if (ft_strcmp(pr->first->name_r, pr->last->name_r) == 0)
		search_tmp->step = 1;
}

int			save_way(t_link *search_tmp, char *str)
{
//	int i;
//
//	i = 0;
	if (!(search_tmp->way = (char **)malloc(sizeof(char *))))
		return (0);
	search_tmp->way = ft_strsplit(str, '\0');
//	while (search_tmp->way[i])
//	{
//		printf("%s\n", search_tmp->way[i]);
//		i++;
//	}
	return (0);
}

void	definition_short(t_link *search_tmp)
{
	t_link *tmp;
//	t_link *result;

	tmp = search_tmp;
	if (tmp) // тут должно быть кол-во наших путей, что бы было равное кол-во итераций!!!
	{
		while (tmp->skipping_two == 1)
			tmp = tmp->next;
		search_short(tmp);
//		result = search_short(tmp);
//		if (tmp->start_let == result->start_let)
			
	}
}


//t_link		*search_short(t_link *search_tmp)
void		search_short(t_link *search_tmp)
{
	t_link *search;
	t_link *step;
//	t_link *stack;
	t_link *tmp;
	t_link *pmt;

//	stack = (t_link *)malloc(sizeof(t_link));
//	stack->next = (t_link *)malloc(sizeof(t_link));

	search = search_tmp;
	step = search_tmp;
	if (step->next)
		step = step->next;
	while (search->next)
	{
		while (search->start_let > step->start_let && step->start_let != -1)
		{
			tmp = search;
			pmt = step;
			search = step;
			search->next = tmp;
//			search = pmt->next;
			step = pmt->next;
		}
//		if (search != step)
//			step = search_tmp;
		step = step->next;
	}
}




//сделать так что бы я мог отличать по возростающему 1 2 3 величину наших путей !!!
//t_link		*search_short(int start_let, t_link *search_tmp)
//{
//	t_link *search;
//
//	search = search_tmp;
//	search->search_short = 0;
//	search = search->next;
//	if (start_let == search->start_let)
//	{
//		search->search_short = 1;
//		return (search);
//	}
//	if (start_let > search->start_let)
//	{
//		search->search_short = 1;
//		return (search);
//	}
//	while (start_let < search->start_let)
//		search = search->next;
//	return (NULL);
//}





















