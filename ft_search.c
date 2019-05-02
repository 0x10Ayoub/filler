/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:39:50 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/01 20:21:37 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_fullscan(t_filler *f)
{
	int i;
	int max;

	max = f->lx > f->ly ? f->lx : f->ly;
	i = 0;
	ft_scanmap(f->xymap, f->lx, f->ly, -1);
	while (i < max)
	{
		ft_heatmap(f->xymap, f->lx, f->ly, i);
		i++;
	}
	return (0);
}

int		ft_scanmap(int **map, int lx, int ly, int c)
{
	int i;
	int j;
	char mc;

	mc = ft_tolower(c);
	i = -1;
	while (++i < ly)
	{
		j = -1;
		while (++j < lx)
		{
			if (map[i][j] == 0 &&
			((j + 1 < lx && map[i][j + 1] == c)
			|| (i + 1 < ly && map[i + 1][j] == c)
			|| (j - 1 >= 0 && map[i][j - 1] == c)
			|| (i - 1 >= 0 && map[i - 1][j] == c)
			|| (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == c)
			|| (i + 1 < ly && j + 1 < lx && map[i + 1][j + 1] == c)
			|| (i - 1 >= 0 && j + 1 < lx && map[i - 1][j + 1] == c)
			|| (i + 1 < ly && j - 1 >= 0 && map[i + 1][j - 1] == c)))
				map[i][j] = 1;
			else if (map[i][j] == 0 &&
			((j + 1 < lx && map[i][j + 1] == mc)
			|| (i + 1 < ly && map[i + 1][j] == mc)
			|| (j - 1 >= 0 && map[i][j - 1] == mc)
			|| (i - 1 >= 0 && map[i - 1][j] == mc)
			|| (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == mc)
			|| (i + 1 < ly && j + 1 < lx && map[i + 1][j + 1] == mc)
			|| (i - 1 >= 0 && j + 1 < lx && map[i - 1][j + 1] == mc)
			|| (i + 1 < ly && j - 1 >= 0 && map[i + 1][j - 1] == mc)))
				map[i][j] = 1;
		}
	}
	return (0);
}

int		ft_heatmap(int **map, int lx, int ly, int v)
{
	int i;
	int j;

	i = -1;
	while (++i < ly)
	{
		j = -1;
		while (++j < lx)
		{
			if ((map[i][j] == 0 || map[i][j] == -2) &&
			((j + 1 < lx && map[i][j + 1] == 1 + v)
			|| (i + 1 < ly && map[i + 1][j] == 1 + v)
			|| (j - 1 >= 0 && map[i][j - 1] == 1 + v)
			|| (i - 1 >= 0 && map[i - 1][j] == 1 + v)
			|| (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == 1 + v)
			|| (i + 1 < ly && j + 1 < lx && map[i + 1][j + 1] == 1 + v)
			|| (i - 1 >= 0 && j + 1 < lx && map[i - 1][j + 1] == 1 + v)
			|| (i + 1 < ly && j - 1 >= 0 && map[i + 1][j - 1] == 1 + v)))
				map[i][j] = 2 + v;
		}
	}
	return (0);
}
