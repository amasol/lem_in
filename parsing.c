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

int 	parsing(t_gl *pr, t_room *rm)
{
	int len = 0;
	if (!(pr->map = (char *)malloc(sizeof(char) * (len + 1))))
		return (1);
	free(pr->map);
	if (*pr->line == '#' && *(pr->line + 1) != '#')
		comment(pr);
	else if  (pr->ants == 0)
		ants_num(pr);
	else if ((*pr->line != '#' && *(pr->line + 1) != '#') && pr->start == 0)
		not_vld_word(pr);
	else if ((pr->ants > 1 && *pr->line != '#' ) && pr->start == 0)
		extra_lines(pr);
	if (*pr->line == '#' && *(pr->line + 1) == '#')
		check_start(pr);
	else if (pr->start == 1)
		save_room_s(pr, rm);
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
		pr->map = ft_strjoin(pr->map, pr->line);
		free(pr->map);
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
	{
		pr->map = ft_strjoin(pr->map, pr->line);
		free(pr->map);
	}
}

void			check_start(t_gl *pr) // запись что мы увидели старт!
{
	int i;

	i = 0;
	if (pr->line[i] == '#' && pr->line[i + 1] == '#')
	{
		i += 2;
		if (pr->line[i] == 's')
		{
			pr->start = 1;

			pr->map = ft_strjoin(pr->map, pr->line);
			free(pr->map);
		}
	}
}

void			save_room_s(t_gl *pr, t_room *rm)
{
	if (pr->line && pr->start == 1 && *pr->line != 'L') //находиться лик !!!!!!!!!!!!
	{
		int i;

		i = 0;
		rm->name_r = *ft_strsplit(pr->line, ' ');
		rm->tmp = ft_strstr(&pr->line[i], " ");
		while (rm->tmp[i] == ' ')
			i++;
		error_word(rm);
		rm->x = ft_atoi(&rm->tmp[i]);
		while (ft_isdigit(rm->tmp[i]))
			i++;
		while (rm->tmp[i] == ' ')
			i++;
		rm->y = ft_atoi(&rm->tmp[i]);
//		free(pr->line);
	}
	else if (pr->line && pr->start == 1 && *pr->line == 'L')
	{
		ft_putstr("Error validation\n");
		exit(1);
	}
}










