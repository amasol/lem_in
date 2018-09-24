/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amasol <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:00:02 by amasol            #+#    #+#             */
/*   Updated: 2018/09/15 17:00:08 by amasol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	parsing(t_gl *pr)
{
	pr->com = 0;
	if (pr->line)
		check_error(pr);
	if (*pr->line == '#' && *(pr->line + 1) != '#')
		comment(pr);
	else if  (pr->ants == 0)
		ants_num(pr);
	else if ((*pr->line != '#' && *(pr->line + 1) != '#')
			&& pr->check_room == 0) //переделать ! так как зайдет если будет написана каше после считываения комнат !
		not_vld_word(pr);
	else if ((pr->ants > 1 && *pr->line != '#' ) &&  pr->check_room == 0)
		extra_lines(pr);
	if (*pr->line == '#' && *(pr->line + 1) == '#')
		check_start(pr);
	else if (pr->check_room == 1 && pr->com == 0 && pr->go_link == 0)			//поставить нормальную проверку на вхождение
		check_room(pr);
	else if (pr->go_link == 1 && pr->com == 0)
		check_link(pr);
//	free(pr->rms->name_r);
	return (1);
}

void			ants_num(t_gl *pr) // записываем кол-во марашек !!!!
{
	int i;

	i = 0;
	while (pr->line[i] != '\0')
	{
		if (ft_isalpha(pr->line[i]))
		{
			ft_putstr("Error validation\n");
			exit(1);
		}
		i++;
	}
	i = 0;
	if (pr->line[i])
	{
		pr->ants = ft_atoi(pr->line);
		if (pr->ants < 0 || pr->ants == 0)
		{
			ft_putstr("Error validation\n");
			exit(1);
		}
	}
}

void			comment(t_gl *pr) // пропускаем коментарии
{
	if (*pr->line == '#' && *(pr->line + 1) != '#')
		pr->com = 1;
}

void			check_start(t_gl *pr) // запись что мы увидели start && end && пропуск коментария если такие есть!!!
{
	int i;

	i = 0;
	if (pr->line[i] == '#' && pr->line[i + 1] == '#' && pr->line[i + 2] != '#')
	{
		pr->check_room = 1;
		if (ft_strcmp("##start", pr->line) == 0)
			check_start_h_s(pr);
		else if (ft_strcmp("##end", pr->line) == 0)
			check_start_h_e(pr);
		else if (pr->line[i] == '#' && pr->line[i + 1] == '#')
			check_start_h_com(pr);
		if (pr->start > 1 || pr->end > 1)
			error();
	}
	else
		error();
}


