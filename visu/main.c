/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:38:12 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/30 16:02:03 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

int main()
{
	SDL_Window *win;
	SDL_Surface *win_surf;
	SDL_Surface *imgsurface;

	if(!(win = ft_setwindow(1600,1050)))
			return(-1);
	win_surf = ft_setbackground(win,&imgsurface);
	SDL_Delay(1000);
	ft_handl_data(win,win_surf,1600,1050);
	SDL_FreeSurface(imgsurface);
	SDL_DestroyWindow(win);
	return (0);
}