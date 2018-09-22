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
	else if (pr->check_room == 1 && pr->com == 0 && pr->go_link == 0)			//поставить нормальную проверку на вхождение
		check_room(pr);
	else if (pr->go_link == 1 && pr->com == 0)
		check_link(pr);
//	else
//		error_st_end(pr);
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

void			check_start(t_gl *pr) // запись что мы увидели start && end && пропуск коментария если такие есть!!!
{
	int i;

	i = 0;
	if (pr->line[i] == '#' && pr->line[i + 1] == '#' && pr->line[i + 2] != '#')
	{
		pr->check_room = 1;
		if (ft_strcmp("##start", pr->line) == 0)
		{
			pr->start = 1;
			pr->map = ft_strjoin(pr->map, pr->line);
			free(pr->map);
		}
		else if (ft_strcmp("##end", pr->line) == 0)
		{
			pr->end = 1;
			pr->map = ft_strjoin(pr->map, pr->line);
			free(pr->map);
		}
		else if (pr->line[i] == '#' && pr->line[i + 1] == '#')
		{
			if (ft_isalpha(pr->line[i + 2]) || ft_isdigit(pr->line[i + 2]))
			{
				pr->com = 1;
				pr->map = ft_strjoin(pr->map, pr->line);
				free(pr->map);
			}
		}
	}
	else
		error();
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

t_link		*create_link(t_link **rm)
{
	t_link	*link;

	if (!rm)
		return (NULL);
	if (!(link = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	link->next = *rm;
	*rm = link;
	return (link);
}

int		comparison_line(t_gl *pr)
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
			if (ft_strcmp(first_tmp->name_r, tmp->name_r) == 0)
				error();
			if (first_tmp->x == tmp->x && first_tmp->y == tmp->y)
				error();
			tmp = tmp->next;
		}
		tmp = pr->rms;
		first_tmp = first_tmp->next;
	}
	return (0);
}

int		comparison_link(t_gl *pr)
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

int		comparison_link_dop(t_gl *pr)
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
