/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:15 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/27 16:06:27 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main()
{
	char *line;
	//int fd;
	t_filler f;

	//fd = open("out.txt", O_RDONLY);
	f.pchar = ft_getplayer();
	f.echar = f.pchar == 'X' ? 'O' : 'X';
	ft_getsizemap(&f);
	f.map = ft_mallocmap(f.lx, f.ly);
	f.xymap = ft_malloc_xymap(f.lx, f.ly);
	f.isread = get_next_line(0, &line);
	free(line);
	while(1 && f.isread == 1)
	{
		ft_initmap(&f);
		//ft_printmap(f.map,f.lx,f.ly,2);
		ft_map_to_xy(&f);
		ft_getsizepiece(&f.px, &f.py);
		f.piece = ft_mallocmap(f.px, f.py);
		ft_initpiece(f.piece, f.px, f.py);
		ft_fullscan(&f);
		ft_play(&f);
		f.isread = get_next_line(0, &line);
		free(line);
		f.isread = get_next_line(0, &line);
		free(line);
	}
	return (0);
}