/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:38:12 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/29 22:29:56 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
# define MODE_key event.key.keysym.sym
int main()
{
	SDL_Window *win;
	SDL_Surface *win_surf;
	SDL_Surface *imgsurface;
	SDL_Event event;
	SDL_KeyboardEvent keven;
	open("nout",O_RDONLY);
	if(!(win = ft_setwindow(1600,1050)))
			return(-1);
	win_surf = ft_setbackground(win,&imgsurface);
	//SDL_Delay(1000);
	ft_handl_data(win,win_surf,1600,1050);
	//SDL_EnableUNICODE( 1 );
	while (1) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT)
			break;
		if(event.type ==SDL_KEYDOWN && MODE_key == SDLK_LEFT)
		{
			dprintf(2,"here we go");
		}
	}
	SDL_FreeSurface(imgsurface);
	SDL_DestroyWindow(win);
	return (0);
}