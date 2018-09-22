/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 17:14:14 by amasol            #+#    #+#             */
/*   Updated: 2018/09/20 17:14:15 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			check_link(t_gl *pr)
{
	if (pr->go_link == 1)
	{
		pr->link = create_link(&(pr->link));
		save_link(pr, pr->link);
	}
}


void			check_room(t_gl *pr)
{
	if (pr->check_room == 1)
	{
		pr->rms = create_room(&(pr->rms));
		if (pr->start == 0 && pr->end == 0 && pr->go_link == 0)
			save_room(pr, pr->rms);
		else if (pr->start == 1 && pr->end == 0 && pr->go_link == 0)
		{
			save_room(pr, pr->rms);
			pr->first = pr->rms;
			pr->start = 0;
//			pr->dop_st = 1;
		}
		else if (pr->start == 0 && pr->end == 1)
		{
			save_room(pr, pr->rms);
			pr->last = pr->rms;
			pr->end = 0;
			pr->go_link = 1;
//			pr->dop_en = 1;
		}
	}
}

void			save_room(t_gl *pr, t_room *rm)
{
	char **tmp;
	int len;

	pr->i = 0;
	if (pr->line && *pr->line && *pr->line != 'L') // запись всех комнат !
	{
		pr->str_free = pr->map;
		num_spac(pr);
		if (pr->space > 2)
			error();
		pr->map = ft_strjoin(pr->map, pr->line);
		tmp = ft_strsplit(pr->line, ' ');
		len = arr_len(tmp);
		if (len > 3 || len < 3)
			error();
		rm->name_r = ft_strdup(tmp[0]);
		rm->x = ft_atoi(tmp[1]);
		rm->y = ft_atoi(tmp[2]);
		rm->tmp = tmp[1];
		error_word(rm);
		rm->tmp = tmp[2];
		error_word(rm);
		while (tmp[pr->i])
			free(tmp[pr->i++]);
		free(tmp);
	}
	free(pr->str_free);
	line_l(pr);
}

void			save_link(t_gl *pr, t_link *link)
{
	char **tmp;

	pr->i = 0;
	pr->link->tmp = (char *)malloc(sizeof(char));
	if (pr->line && *pr->line)
	{
		pr->str_free = pr->map;
		pr->map = ft_strjoin(pr->map, pr->line);
//		free(pr->map);
		pr->link->tmp = ft_strcat(link->tmp, pr->line);
		tmp = ft_strsplit(pr->line, '-');
		link->name_l_one = ft_strdup(tmp[0]);
		link->name_l_two = ft_strdup(tmp[1]);
		while (tmp[pr->i])
			free(tmp[pr->i++]);
		free(tmp);
//		free(pr->link->tmp);
	}
}

//int			link_line(char *tmp)
//{
//	int i;
//	int j;
//
//	i = 0;
//	j = 0;
//	while (tmp[i])
//	{
//		while (tmp[i] == '-')
//		{
//			i++;
//			j++;
//		}
//		i++;
//	}
//	return (j);
//}


//void			valid_double_link(t_gl *pr)
//{
//	while ()
//}




















