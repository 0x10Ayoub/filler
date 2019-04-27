/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 18:00:29 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/27 11:15:12 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

SDL_Window	*ft_setwindow(int w, int h)
{
	SDL_Window *win;

	if (SDL_Init(SDL_INIT_VIDEO) != 0 || TTF_Init() == -1)
	{
		ft_printf("error %s", SDL_GetError());
		return (NULL);
	}
	win = SDL_CreateWindow(
		"Filler battle",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		w,
		h,
		SDL_WINDOW_OPENGL);
	if (win == NULL)
	{
		printf("Could not create window: %s\n", SDL_GetError());
		return (NULL);
	}
	return (win);
}

SDL_Surface	*ft_setbackground(SDL_Window *win, SDL_Surface **img)
{
	SDL_Surface *win_surf;

	win_surf = SDL_GetWindowSurface(win);
	*img = SDL_LoadBMP ("assest/img/tetris.bmp");
	SDL_BlitSurface(*img, NULL, win_surf, NULL);
	SDL_UpdateWindowSurface(win);
	return (win_surf);
}
