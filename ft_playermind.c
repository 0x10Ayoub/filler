/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playermind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:07:59 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/29 22:11:03 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
int		ft_checkpalce(t_filler *f, int posx, int posy)
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
			(f->map[posy + i][posx + j] == f->pchar||
			f->map[posy + i][posx + j] == ft_tolower(f->pchar)))
				r++;
		}
	}
	if (r != 1)
		return (0);
	return (1);
}

int		ft_testpalce(t_filler *f, int posx,int posy)
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
			if(f->piece[i + f->ey][j + f->ex] == '*' &&
			f->xymap[posy + i][posx + j] != -2)
			f->tpos += f->xymap[posy + i][posx + j];
		}
	}
	return (0);
}

int ft_place(t_filler *f)
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
				if (f->mapos < 0 || f->tpos <= f->mapos)
				{
					f->mapos = f->tpos;
					f->setx = i - f->ey;
					f->sety = j - f->ex;
				}
			}
		}
	}
	return (f->mapos < 0 ? 0 : 1);
}

void		ft_play(t_filler *f)
{
	if(ft_place(f) == 1)
	{
		ft_putnbr_fd(f->setx,1);
		ft_putstr_fd(" ",1);
		ft_putnbr_fd(f->sety,1);
		ft_putchar_fd('\n',1);
	}else
	{
		ft_putnbr_fd(0, 1);
		ft_putstr_fd(" ", 1);
		ft_putnbr_fd(0, 1);
		ft_putchar_fd('\n',1);
	}
	
}

void	ft_setoffset(t_filler *f)
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
				if(f->ey < 0 && f->ex < 0 )
					f->ey = i;
				if(f->ex < 0 || f->ex > j)
					f->ex = j;
			}
		}
	}
}

void	ft_setbounds(t_filler *f)
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
				if(f->xbnd  <= j )
					f->xbnd  = j + 1;
				f->ybnd = i + 1;
			}
		}
	}
	if(f->ybnd >0 && f->ybnd > 0)
	{
		f->ybnd -= f->ey;
		f->xbnd -= f->ex;
	}
}