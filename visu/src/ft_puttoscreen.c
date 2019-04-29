/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttoscreen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:48:41 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/29 21:21:12 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_puttext(t_visu *v,char *text,int x,int y)
{
	TTF_Font*		font;
	SDL_Color		fc;
	SDL_Color		bc;
	SDL_Rect		tx_locat;
	SDL_Surface* 	textSurface;

	font = TTF_OpenFont("assest/font/zorque.ttf",32);

	fc.a = 255;
	fc.b = 126;
	fc.g = 235;
	fc.r = 26;

	bc.a = 0;
	bc.b = 255;
	bc.g = 255;
	bc.r = 255;

	textSurface = TTF_RenderText_Shaded(font,text,fc,bc);
	tx_locat.x = x;
	tx_locat.y = y;
	tx_locat.w = 0;
	tx_locat.h = 0;
	SDL_BlitSurface(textSurface, NULL, v->win_surf, &tx_locat);
	SDL_UpdateWindowSurface(v->win);
	SDL_FreeSurface(textSurface);
	TTF_CloseFont(font);
}