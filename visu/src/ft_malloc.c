/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 20:46:56 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/29 22:20:09 by akhourba         ###   ########.fr       */
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
	//int		i;

	/*v->isread = get_next_line(0, &line);
	i = ft_atoi(line + 6);
	free(line);*/
	//dprintf(2,"ok test\n");
	while(v->isread == 1)
	{
		v->isread = get_next_line(0,&line);
	//	dprintf(2,"|%s\n",line);
		if(line[0] == 'P' && line[1] == 'l')
		{

			free(line);
			break;
		}
		free(line);
	}
	//v->isread = get_next_line(0,&line);
	//free(line);
}
