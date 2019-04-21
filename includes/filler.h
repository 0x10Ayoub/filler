/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:19:52 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/20 18:25:34 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"

typedef struct	s_filler
{
	unsigned char	**piece;
	unsigned char	**map;
	int				**xymap;
	int				lx;
	int				ly;
	int				px;
	int				py;
	int				tpos;
	int				ex;
	int				ey;
	int				setx;
	int				sety;
	int				mapos;
	char			echar;
	char			pchar;
	int				xbnd;
	int				ybnd;
}				t_filler;

char			ft_getplayer();
void			ft_getsizemap(t_filler *f);
unsigned char	**ft_mallocmap(int x, int y);
void			ft_initmap(unsigned char **map, int x, int y);
void			ft_getsizepiece(int *px, int *py);
void			ft_initpiece(unsigned char **piece, int x, int y);
int				ft_scanmap(int **map, int lx, int ly, int c);
int				ft_heatmap(int **map,int lx,int ly,int v);
int				ft_fullscan(t_filler *f);
int				**ft_malloc_xymap(int x, int y);
void			ft_map_to_xy(t_filler *f);
int				ft_checkpalce(t_filler *f, int posx,int posy);
int				ft_place(t_filler *f);
void			ft_play(t_filler *f);
void			ft_printxymap(int **map,int lx,int ly,int fd);
void			ft_setoffset(t_filler *f);
void			ft_setbounds(t_filler *f);
void ft_printmapoffset(unsigned char **map,t_filler *f);
//test purpose
void ft_printmap(unsigned char **map,int ly,int lx,int fd);
#endif