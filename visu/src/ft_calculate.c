/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:34:08 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/26 22:26:04 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_put_grid(t_visu *v)
{
	int i;
	int j;
	SDL_Rect rect;
	Uint32 color;

	i = -1;
	if(v->wgrid > 60)
	{
	rect.h = 5 ;
	rect.w = 5 ;
	}else{
	rect.h = 10 + (v->wgrid/8);
	rect.w = 10 + (v->wgrid/8);
	}
	rect.y = 100;
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