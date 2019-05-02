/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttoscreen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:48:41 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/30 20:29:00 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		ft_puttext(t_visu *v,char *text,int x,int y, int size)
{
	TTF_Font*		font;
	SDL_Color		fc;
	SDL_Color		bc;
	SDL_Rect		tx_locat;
	SDL_Surface* 	textSurface;

	font = TTF_OpenFont("assest/font/zorque.ttf",size);
	bc.a = 0;
	bc.b = 74;
	bc.g = 110;
	bc.r = 17;
	fc.a = SDL_ALPHA_TRANSPARENT;
	fc.b = 255;
	fc.g = 255;
	fc.r = 255;
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

void ft_putbar(t_visu *v)
{
	SDL_Rect rect;
	Uint32 colorx;
	Uint32 coloro;
	int dev;

	if(v->wgrid <= 20)
		dev = 50;
	else if(v->wgrid <= 40)
		 dev = 100;
	else
		dev = 500;
	rect.x = 50;
	rect.y = 750;
	rect.h = 30;
	rect.w = 500;
	coloro = SDL_MapRGBA(v->win_surf->format, 255, 255, 255,100);
	SDL_FillRect(v->win_surf, &rect, coloro);
	coloro = SDL_MapRGBA(v->win_surf->format, 100, 16, 195,100);
	rect.w = (v->co * 100) / dev;
	SDL_FillRect(v->win_surf, &rect, coloro);
	rect.y = 800;
	rect.w = 500;
	colorx = SDL_MapRGBA(v->win_surf->format, 255, 255, 255,100);
	SDL_FillRect(v->win_surf ,&rect, colorx);
	colorx = SDL_MapRGBA(v->win_surf->format, 200, 65, 100,100);
	rect.w = (v->cx * 100)/ dev;
	SDL_FillRect(v->win_surf ,&rect, colorx);
	SDL_UpdateWindowSurface(v->win);
}

void ft_putsidebar(t_visu *v)
{
	SDL_Rect rect;

	rect.x = 1000;
	rect.y = 100;
	rect.h = 500;
	rect.w = 500;
	ft_set_img(v->win);
	ft_puttext(v, v->str_p1, 1050, 120,20);
	ft_puttext(v, "vs", 1190, 150,20);
	ft_puttext(v, v->str_p2, 1250, 120,20);
	ft_puttext(v,"Winer :", 1000, 170,20);
	ft_puttext(v,"Left move forward", 1000, 300,15);
	ft_puttext(v,"Right move backward", 1000, 320,15);
	ft_puttext(v,"Up move 10x forward", 1000, 340,15);
	ft_puttext(v,"Down move 10x xbackward", 1000, 360,15);
}

SDL_Surface	*ft_set_img(SDL_Window *win)
{
	SDL_Surface *win_surf;
	SDL_Surface *img;
	SDL_Rect rec;

	rec.h = 300;
	rec.w = 300;
	rec.x = 900;
	rec.y = 90;
	win_surf = SDL_GetWindowSurface(win);
	img = SDL_LoadBMP ("assest/img/sb.bmp");
	SDL_BlitSurface(img, NULL, win_surf, &rec);
	SDL_UpdateWindowSurface(win);
	return (win_surf);
}