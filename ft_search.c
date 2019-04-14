/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:39:50 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/14 20:17:40 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_fullscan(t_filler *f)
{
	int i;
	int max;

	max = f->lx > f->ly ? f->lx  : f->ly;
	i = 0;
	ft_putchar_fd(f->echar,3);
	ft_scanmap(f->map,f->lx,f->ly,ft_toupper(f->echar));
	while( i < max){
		ft_heatmap(f->map,f->lx,f->ly,i);
		i++;
	}
	return (0);
}

int		ft_scanmap(unsigned char **map, int lx, int ly, char c)
{
	int i;
	int j;
	
	i = -1;
	ft_putendl_fd("-----------------",3);
	while (++i < ly)
	{
		j = -1;
		while (++j < lx)
		{
			if (map[i][j] == '.' && 
			((j + 1 < lx && map[i][j + 1] == c)
			|| (i + 1 < ly && map[i + 1][j]== c)
			|| (j - 1 >=0 && map[i][j - 1] == c)
			|| (i - 1 >=0 && map[i - 1][j] == c)
			|| (i - 1 >= 0 && j-1 >= 0 && map[i - 1][j - 1] == c)
			|| (i + 1 < ly && j + 1 < lx && map[i + 1][j + 1] == c)
			|| (i - 1 >= 0 && j + 1 < lx && map[i - 1][j + 1] == c)
			|| (i + 1 < ly && j - 1 >= 0 && map[i + 1][j - 1] == c)))
			map[i][j] = '1';
				ft_putchar_fd(map[i][j], 3);
		}
		ft_putchar_fd('\n', 3);
	}
	return (0);
}

int		ft_heatmap(int **map,int lx,int ly,int v)
{
	int i;
	int j;
	i = -1;
	ft_putendl_fd("-----------------",3);
	while (++i < ly)
	{
		j = -1;
		while (++j < lx)
		{
			if (map[i][j] == '.' && 
			((j + 1 < lx && map[i][j + 1] == '0' + v)
			|| (i + 1 < ly && map[i + 1][j]== '0' + v)
			|| (j - 1 >= 0 && map[i][j - 1] == '0' + v )
			|| (i - 1 >= 0 && map[i - 1][j] == '0' + v)
			|| (i - 1 >= 0 && j-1 >=0 && map[i - 1][j - 1] == '0' + v)
			|| (i + 1 < ly && j + 1 < lx && map[i + 1][j + 1] == '0' + v)
			|| (i - 1 >= 0 && j + 1 < lx && map[i - 1][j + 1] == '0' + v )
			|| (i + 1 < ly && j - 1 >= 0 && map[i + 1][j - 1] == '0' + v)))
			map[i][j] = '1' + v;
				ft_putchar_fd(map[i][j],3);
		}
		ft_putchar_fd('\n',3);
	}
	return (0);
}

int ft_get_start_position(t_filler *f)
{
	int i;
	int j;
	unsigned char **map;

	i = -1;
	j = -1;
	map = f->map;
	f->echar = f->pchar == 'O' ? 'x' : 'o';
	f->echar = f->isfirst ? ft_toupper(f->echar) : f->echar;
	f->isfirst = 0;
	while (++i < f->ly)
	{
		while (++j < f->lx)
		{
			if (map[i][j] == f->echar ||
			(map[i][j] == ft_toupper(f->echar) && f->isfirst))
			{
				f->sx = j;
				f->sy = i;
				return (0);
			}
		}
	}
	return (1);
}
