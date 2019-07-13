/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:50:23 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/02 22:13:34 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_skip(int ln, t_visu *v)
{
	int		i;
	char	*line;
	char	*tmp;

	i = -1;
	while (++i < ln && get_next_line(0, &line))
	{
		if (i == 6 || i == 8)
		{
			if ((tmp = ft_strrchr(line, '/')))
			{
				++tmp;
				tmp = ft_strsub(tmp, 0, ft_strlenc(tmp, '.'));
			}
			else
				tmp = ft_strdup("No one?");
			if (i == 6)
				v->str_p1 = tmp;
			else
				v->str_p2 = tmp;
		}
		if (line[0] == 'P' || line[1] == 'l')
			break ;
		free(line);
	}
}

void		ft_handl_data(SDL_Window *win, SDL_Surface *win_surf, int w, int h)
{
	t_visu	v;
	t_fram	*fram;

	v.h = h;
	v.cx = 0;
	v.co = 0;
	v.w = w;
	v.win = win;
	v.win_surf = win_surf;
	ft_skip(9, &v);
	v.isread = 1;
	fram = NULL;
	ft_putsidebar(&v);
	ft_getsizegrid(&v);
	v.txt = "filler battle";
	ft_puttext(&v, 600, 50, 30);
	while (ft_initgrid(&v, v.wgrid, v.hgrid) && v.isread == 1)
	{
		ft_getskippiece(&v);
		ft_put_grid(&v);
		ft_lst_add(&fram, v.fram);
		ft_putbar(&v);
	}
	v.fram = fram;
	ft_handl_event(&v);
}

void		ft_getsizegrid(t_visu *v)
{
	char	*table;
	int		i;

	i = 8;
	v->isread = get_next_line(0, &table);
	v->hgrid = ft_atoi(&table[i]);
	if (v->hgrid <= 0 || v->hgrid > 100)
	{
		v->hgrid = 0;
		return ;
	}
	i++;
	while (table[i] != ' ' && table[i] != '\0')
		i++;
	v->wgrid = ft_atoi(&table[i]);
	free(table);
}

int			ft_initgrid(t_visu *v, int w, int h)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	v->isread = get_next_line(0, &line);
	free(line);
	v->fram = malloc(sizeof(t_fram));
	v->fram->grid = ft_mallocgrid(v->wgrid, v->hgrid);
	while (++i < h)
	{
		j = -1;
		v->isread = get_next_line(0, &line);
		while (++j < w)
			v->fram->grid[i][j] = line[4 + j];
		free(line);
	}
	return (1);
}
