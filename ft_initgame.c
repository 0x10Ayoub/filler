/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initgame.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:11:19 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/27 16:06:10 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

unsigned char	**ft_mallocmap(int x, int y)
{
	int				i;
	unsigned char	**map;

	i = -1;
	map = ft_memalloc(sizeof(unsigned char *) * y + 1);
	while (++i < y)
		map[i] = ft_memalloc(sizeof(unsigned char) * x + 1);
	map[i] = NULL;
	return (map);
}

void			ft_initmap(t_filler *f)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < f->ly)
	{
		j = -1;
		get_next_line(0, &line);
		while (++j < f->lx)
			f->map[i][j] = line[4 + j];
		free(line);
	}
}

void			ft_initpiece(unsigned char **piece, int x, int y)
{
	int		i;
	int		j;
	char	*line;

	i = -1;
	while (++i < y)
	{
		j = -1;
		get_next_line(0, &line);
		while (++j < x)
			piece[i][j] = line[j];
		free(line);
	}
}

int				**ft_malloc_xymap(int x, int y)
{
	int		i;
	int		**map;

	i = 0;
	map = ft_memalloc(sizeof(int *) * y + 1);
	while (i < y)
		map[i++] = ft_memalloc(sizeof(int) * x + 1);
	map[i] = NULL;
	return (map);
}
