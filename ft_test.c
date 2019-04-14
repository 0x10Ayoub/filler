/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 11:41:36 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/12 11:49:32 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void ft_printmap(unsigned char **map,int ly,int lx,int fd)
{
		for(int i = 0; i < ly; i++)
	{
		for(int j = 0; j < lx; j++)
		{
			ft_putchar_fd(map[i][j],fd);
		}
		ft_putchar_fd('\n',fd);
	}
}
