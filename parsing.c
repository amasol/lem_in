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
	int len;

	len = 0;
	pr->com = 0;
	if (!(pr->map = (char *)malloc(sizeof(char) * (len + 1))))
		return (1);
	free(pr->map);
	if (*pr->line == '#' && *(pr->line + 1) != '#')
		comment(pr);
	else if  (pr->ants == 0)
		ants_num(pr);
	else if ((*pr->line != '#' && *(pr->line + 1) != '#') && pr->check_room == 0) //переделать ! так как зайдет если будет написана каше после считываения комнат !
		not_vld_word(pr);
	else if ((pr->ants > 1 && *pr->line != '#' ) &&  pr->check_room == 0)
		extra_lines(pr);
	if (*pr->line == '#' && *(pr->line + 1) == '#')
		check_start(pr);
	else if (pr->check_room == 1 && pr->com == 0)			//поставить нормальную проверку на вхождение
		check_room(pr);
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
		pr->com = 1;
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
		pr->check_room = 1;
		i += 2;
		if (pr->line[i] == 's')
		{
			pr->start = 1;

			pr->map = ft_strjoin(pr->map, pr->line);
			free(pr->map);
		}
		else if (pr->line[i] == 'e')
		{

		}
		else
			error();
	}
}

t_room		*create_room(t_room **rm)
{
	t_room *rms;

	if (!rm)
		return (NULL);
	if (!(rms = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	rms->next = *rm;
	*rm = rms;
	return (rms);
}

