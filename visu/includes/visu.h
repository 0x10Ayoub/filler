/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 21:05:07 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/27 13:01:38 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include "libft.h"
typedef		struct	s_fram
{
	unsigned char **grid;
	struct s_fram *next;
	struct s_fram *prev;
}					t_fram;

typedef		struct	s_text
{
	char			*string;
	SDL_Color		fg;
	SDL_Color		bg;
	int				x;
	int				y;
	unsigned int	size;
}					t_text;

typedef		struct s_visu
{
	int hgrid;
	int wgrid;
	int	h;
	int w;
	int	isread;
	int fd;
	t_text tx;
	t_fram *fram;
	SDL_Window *win;
	SDL_Surface *win_surf;

}					t_visu;
SDL_Window		*ft_setwindow(int w, int h);
SDL_Surface		*ft_setbackground(SDL_Window *win, SDL_Surface **img);
void			ft_handl_data(SDL_Window *win, SDL_Surface *win_surf, int w, int h);
void			ft_getsizegrid(t_visu *v);
unsigned char	**ft_mallocgrid(int w, int h);
int				ft_initgrid(t_visu *v, int w, int h);
void			ft_getskippiece(t_visu *v);
void			ft_put_grid(t_visu *v);
void			ft_puttext(t_visu *v,char *text,int x,int y);
#endif