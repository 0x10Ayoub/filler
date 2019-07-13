/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:25:17 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/02 17:40:20 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_map_to_xy(t_filler *f)
{
	int i;
	int j;

	i = -1;
	while (++i < f->ly)
	{
		j = -1;
		while (++j < f->lx)
		{
			if (f->map[i][j] == f->echar ||
				f->map[i][j] == ft_tolower(f->echar))
				f->xymap[i][j] = -1;
			else if (f->map[i][j] == f->pchar ||
				f->map[i][j] == ft_tolower(f->pchar))
				f->xymap[i][j] = -2;
			else
				f->xymap[i][j] = 0;
		}
	}
}

void		ft_setoffset(t_filler *f)
{
	int i;
	int j;

	i = -1;
	f->ex = -1;
	f->ey = -1;
	while (++i < f->py)
	{
		j = -1;
		while (++j < f->px)
		{
			if (f->piece[i][j] == '*')
			{
				if (f->ey < 0 && f->ex < 0)
					f->ey = i;
				if (f->ex < 0 || f->ex > j)
					f->ex = j;
			}
		}
	}
}

void		ft_setbounds(t_filler *f)
{
	int i;
	int j;

	i = f->ey - 1;
	f->ybnd = -1;
	f->xbnd = -1;
	while (++i < f->py)
	{
		j = f->ex - 1;
		while (++j < f->px)
		{
			if (f->piece[i][j] == '*')
			{
				if (f->xbnd <= j)
					f->xbnd = j + 1;
				f->ybnd = i + 1;
			}
		}
	}
	if (f->ybnd > 0 && f->ybnd > 0)
	{
		f->ybnd -= f->ey;
		f->xbnd -= f->ex;
	}
}
