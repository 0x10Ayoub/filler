/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:46:56 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/30 18:58:48 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

unsigned char	**ft_mallocgrid(int w, int h)
{
	int				i;
	unsigned char	**map;

	i = -1;
	map = ft_memalloc(sizeof(unsigned char *) * h + 1);
	while (++i < h)
		map[i] = ft_memalloc(sizeof(unsigned char) * w + 1);
	map[i] = NULL;
	return (map);
}

void		ft_getskippiece(t_visu *v)
{
	char	*line;
	while (v->isread == 1)
	{
		v->isread = get_next_line(0, &line);
		if (line[0] == 'P' && line[1] == 'l')
		{
			free(line);
			break;
		}
		else if (line[0] == '<' && line[6] == 'O')
			v->co ++;
		else if (line[0] == '<' && line[6] == 'X')
			v->cx ++;
		free(line);
	}
}
