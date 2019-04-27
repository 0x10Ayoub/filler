/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:38:12 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/27 11:17:17 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
int main()
{
	SDL_Window *win;
	SDL_Surface *win_surf;
	SDL_Surface *imgsurface;
	SDL_Event event;
	open("nout",O_RDONLY);
	if(!(win = ft_setwindow(1600,1050)))
			return(-1);
	win_surf = ft_setbackground(win,&imgsurface);
	SDL_Delay(1000);
	ft_handl_data(win,win_surf,1600,1050);
	while (1) {
		if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
		{
			ft_putchar_fd ('5', 2);
			break;
		}
	}
	SDL_FreeSurface(imgsurface);
	SDL_DestroyWindow(win);
	return (0);
}