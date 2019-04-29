/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:41:36 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/27 15:49:36 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
void ft_printmap(unsigned char **map,int lx,int ly,int fd)
{
	for(int i = 0; i < ly; i++)
	{
		for(int j = 0; j < lx; j++)
		{
			ft_putstr_fd("wtfk  ",fd);
			ft_putchar_fd(map[i][j],fd);
		}
		ft_putchar_fd('\n',fd);
	}
}

void ft_printxymap(int **map,int lx,int ly,int fd)
{
		for(int i = 0; i < ly; i++)
	{
		for(int j = 0; j < lx; j++)
		{
			dprintf(fd,"%4d",map[i][j]);
		}
		dprintf(fd,"\n");
	}
}

void ft_printmapoffset(unsigned char **map,t_filler *f)
{
	int ly = f->py - f->ey;
	int lx = f->px - f->ex;
		for(int i = 0; i < ly; i++)
	{
		for(int j = 0; j < lx; j++)
		{
			ft_putchar_fd(map[i + f->ey][j+f->ex],2);
		}
		ft_putchar_fd('\n',2);
	}
}
