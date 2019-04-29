/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:34:08 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/29 22:00:24 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_put_grid(t_visu *v)
{
	int i;
	int j;
	int max;
	int h;
	SDL_Rect rect;
	Uint32 color;

	i = -1;
	max = v->hgrid > v->wgrid ? v->hgrid : v->wgrid;
	max += ((max/2) * 2);
	h = max;
	rect.y = 100;
	rect.h = v->hgrid  * ((800/max)+2);
	rect.w = v->wgrid  * ((800/max)+2);
	rect.x = 50+(800/max)+2;
	color = SDL_MapRGBA(v->win_surf->format, 55, 55, 55,25);
	SDL_FillRect(v->win_surf,&rect,color);
	rect.h = 800 / max;
	rect.w = 800 / max;
	while (++i < v->hgrid)
	{
		j = -1;
		rect.x = 50;
		while (++j < v->wgrid)
		{
			rect.x += rect.h + 2;
			if (v->fram->grid[i][j] == 'X')
				color = SDL_MapRGBA(v->win_surf->format, 200, 65, 100,100);
			if (v->fram->grid[i][j] == 'x')
				color = SDL_MapRGBA(v->win_surf->format, 200, 65, 200,50);
			else if (v->fram->grid[i][j] == 'O')
				color = SDL_MapRGBA(v->win_surf->format, 100, 16, 195,100);
			else if (v->fram->grid[i][j] == 'o')
				color = SDL_MapRGBA(v->win_surf->format, 255, 255, 195,50);
			else if (v->fram->grid[i][j] == '.')
				color = SDL_MapRGBA(v->win_surf->format, 255, 255, 255,100);
			SDL_FillRect(v->win_surf, &rect, color);
		}
		rect.y += rect.h + 2;
	}
	SDL_UpdateWindowSurface(v->win);
}