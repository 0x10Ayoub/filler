/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 21:34:08 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/02 22:27:51 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void			ft_put_grid(t_visu *v)
{
	int			i;
	int			j;
	int			max;
	SDL_Rect	rect;
	Uint32		color;

	i = -1;
	max = ft_setrect(v, &rect);
	color = SDL_MapRGBA(v->win_surf->format, 55, 55, 55, 25);
	SDL_FillRect(v->win_surf, &rect, color);
	rect.h = 800 / max;
	rect.w = 800 / max;
	while (++i < v->hgrid)
	{
		j = -1;
		rect.x = 50;
		while (++j < v->wgrid)
		{
			rect.x += rect.h + 2;
			color = ft_setcolor(v, i, j, color);
			SDL_FillRect(v->win_surf, &rect, color);
		}
		rect.y += rect.h + 2;
	}
	SDL_UpdateWindowSurface(v->win);
}

void			ft_move(t_visu *v, int n)
{
	if (v->fram->next && n)
		v->fram = v->fram->next;
	else if (v->fram->prev)
		v->fram = v->fram->prev;
	ft_put_grid(v);
	SDL_Delay(10);
}

void			ft_handl_event(t_visu *v)
{
	SDL_Event	event;
	int			x;

	ft_settext(v);
	ft_puttext(v, 1000, 190, 20);
	while (1)
	{
		x = 0;
		while (SDL_PollEvent(&event) && !x)
		{
			if (event.type == SDL_KEYDOWN && MODE_KEY == SDLK_RIGHT)
				ft_move(v, 1);
			else if (event.type == SDL_KEYDOWN && MODE_KEY == SDLK_LEFT)
				ft_move(v, 0);
			x = 1;
		}
		if (event.type == SDL_KEYDOWN && MODE_KEY == SDLK_DOWN)
			ft_move(v, 1);
		else if (event.type == SDL_KEYDOWN && MODE_KEY == SDLK_UP)
			ft_move(v, 0);
		if (event.type == SDL_QUIT)
			break ;
	}
}

Uint32			ft_setcolor(t_visu *v, int i, int j, Uint32 color)
{
	if (v->fram->grid[i][j] == 'X')
		color = SDL_MapRGBA(v->win_surf->format, 200, 65, 100, 100);
	else if (v->fram->grid[i][j] == 'x')
		color = SDL_MapRGBA(v->win_surf->format, 200, 65, 200, 50);
	else if (v->fram->grid[i][j] == 'O')
		color = SDL_MapRGBA(v->win_surf->format, 100, 16, 195, 100);
	else if (v->fram->grid[i][j] == 'o')
		color = SDL_MapRGBA(v->win_surf->format, 255, 255, 195, 50);
	else if (v->fram->grid[i][j] == '.')
		color = SDL_MapRGBA(v->win_surf->format, 255, 255, 255, 100);
	return (color);
}

int				ft_setrect(t_visu *v, SDL_Rect *rect)
{
	int max;

	max = v->hgrid > v->wgrid ? v->hgrid : v->wgrid;
	max += ((max / 2) * 2);
	rect->y = 100;
	rect->h = v->hgrid * ((800 / max) + 2);
	rect->w = v->wgrid * ((800 / max) + 2);
	rect->x = 50 + (800 / max) + 2;
	return (max);
}
