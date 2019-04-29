/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:50:23 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/29 22:32:35 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	ft_skip(int ln)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < ln && get_next_line(0, &line))
		free(line);
}

void	ft_handl_data(SDL_Window *win, SDL_Surface *win_surf, int w, int h)
{
	char	*line;
	t_visu	v;

	v.h = h;
	v.w = w;
	v.win = win;
	v.win_surf = win_surf;
	v.fd = 0;
	ft_skip(9);
	v.isread = 1;
	ft_getsizegrid(&v);
	ft_puttext(&v, "filler battle", 600, 50);
	v.fram = malloc(sizeof(t_fram));
	v.fram->grid = ft_mallocgrid(v.wgrid, v.hgrid);
	while (ft_initgrid(&v, v.wgrid, v.hgrid) && v.isread == 1)
	{
		ft_getskippiece(&v);
		ft_put_grid(&v);
		SDL_Delay(100 - v.wgrid);
	}
}

void		ft_getsizegrid(t_visu *v)
{
	char	*table;
	int		i;

	i = 8;
	v->isread = get_next_line(v->fd, &table);
	v->hgrid = ft_atoi(&table[i]);
	i++;
	while (table[i] != ' ' && table[i] != '\0')
		i++;
	v->wgrid = ft_atoi(&table[i]);
}

int			ft_initgrid(t_visu *v, int w, int h)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	v->isread = get_next_line(v->fd, &line);
	free(line);
	//dprintf(2,"%s","initgri");
	while (++i < h)
	{
		j = -1;
		v->isread = get_next_line(v->fd, &line);
		//dprintf(2,"%s",line);
		//dprintf(2,"\n");
		while (++j < w)
			v->fram->grid[i][j] = line[4 + j];
		free(line);
	}
	//dprintf(2,"\n");
	return (1);
}