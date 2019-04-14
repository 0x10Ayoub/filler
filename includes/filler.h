/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:19:52 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/14 20:17:08 by akhourba         ###   ########.fr       */
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
	int				isfirst;
	int				sx;
	int				sy;
	char			echar;
	char			pchar;
}				t_filler;

char			ft_getplayer();
void			ft_getsizemap(int *x, int *y);
unsigned char	**ft_mallocmap(int x, int y);
void			ft_initmap(unsigned char **map, int x, int y);
void			ft_getsizepiece(int *px, int *py);
void			ft_initpiece(unsigned char **piece, int x, int y);
int				ft_scanmap(unsigned char **map,int lx,int ly, char c);
int				ft_heatmap(unsigned char **map,int lx,int ly,int v);
int				ft_fullscan(t_filler *f);
int				**ft_malloc_xymap(int x, int y);
//test purpose
void ft_printmap(unsigned char **map,int ly,int lx,int fd);
#endif