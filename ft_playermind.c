/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playermind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:07:59 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/03 11:43:42 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_checkpalce(t_filler *f, int posx, int posy)
{
	int i;
	int j;
	int r;

	i = -1;
	r = 0;
	if (posy + f->ybnd > f->ly || posx + f->xbnd > f->lx)
		return (0);
	while (++i < f->ybnd)
	{
		j = -1;
		while (++j < f->xbnd)
		{
			if (f->piece[i + f->ey][j + f->ex] == '*' &&
			(f->map[posy + i][posx + j] == f->echar
			|| f->map[posy + i][posx + j] == ft_tolower(f->echar)))
				return (0);
			if (f->piece[i + f->ey][j + f->ex] == '*' &&
			(f->map[posy + i][posx + j] == f->pchar ||
			f->map[posy + i][posx + j] == ft_tolower(f->pchar)))
				r++;
		}
	}
	return (r != 1 ? 0 : 1);
}

int			ft_testpalce(t_filler *f, int posx, int posy)
{
	int i;
	int j;

	i = -1;
	f->tpos = 0;
	while (++i < f->ybnd)
	{
		j = -1;
		while (++j < f->xbnd)
		{
			if (f->piece[i + f->ey][j + f->ex] == '*' &&
			f->xymap[posy + i][posx + j] != -2)
				f->tpos += f->xymap[posy + i][posx + j];
		}
	}
	return (0);
}

int			ft_place(t_filler *f)
{
	int i;
	int j;

	i = -1;
	f->mapos = -1;
	f->setx = 0;
	f->sety = 0;
	ft_setoffset(f);
	if (f->ex == -1 || f->ey == -1)
		return (0);
	ft_setbounds(f);
	while (++i < f->ly)
	{
		j = -1;
		while (++j < f->lx)
		{
			if (ft_checkpalce(f, j, i))
			{
				ft_testpalce(f, j, i);
				if (f->mapos < 0 || f->tpos < f->mapos)
					ft_setplace(f, i, j);
			}
		}
	}
	return (f->mapos < 0 ? 0 : 1);
}

void		ft_play(t_filler *f)
{
	if (ft_place(f) == 1)
	{
		ft_putnbr_fd(f->setx, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(f->sety, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putnbr_fd(0, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(0, 1);
		ft_putchar_fd('\n', 1);
	}
	ft_freemap(&f->piece, f->py);
}

void		ft_setplace(t_filler *f, int i, int j)
{
	f->mapos = f->tpos;
	f->setx = i - f->ey;
	f->sety = j - f->ex;
}
