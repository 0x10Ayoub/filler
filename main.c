/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 16:48:15 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/14 17:57:50 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int main()
{
	char *line;
	int fd;
	t_filler f;

	f.isfirst = 1;
	fd = open("out.txt", O_RDWR);
	f.pchar = ft_getplayer();
	f.echar = f.pchar == 'X' ? 'O' : 'X';
	ft_getsizemap(&f.ly, &f.lx);
	f.map = ft_mallocmap(f.lx, f.ly);
	get_next_line(0, &line);
	free(line);

	ft_initmap(f.map, f.lx, f.ly);
	ft_getsizepiece(&f.py, &f.px);
	f.piece = ft_mallocmap(f.px, f.py);
	ft_initpiece(f.piece, f.px, f.py);
	ft_fullscan(&f);

	return (0);
}
