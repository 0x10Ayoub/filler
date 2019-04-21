/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:25:17 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/18 00:57:01 by akhourba         ###   ########.fr       */
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
