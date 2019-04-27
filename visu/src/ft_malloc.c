/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:46:56 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/26 20:25:40 by akhourba         ###   ########.fr       */
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

void		ft_getskippiece()
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	i = ft_atoi(line + 6);
	free(line);
	while(--i >=0 )
	{
		get_next_line(0,&line);
	}
	
}
