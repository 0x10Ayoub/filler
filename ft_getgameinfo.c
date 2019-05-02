/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgameinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:07:21 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/01 20:16:18 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		ft_getplayer(void)
{
	char *player;
	char c;

	c = '\0';
	get_next_line(0, &player);
	if (player[10] == '1')
		c = 'O';
	else if (player[10] == '2')
		c = 'X';
	free(player);
	return (c);
}

void		ft_getsizemap(t_filler *f)
{
	char	*table;
	int		i;

	i = 8;
	get_next_line(0, &table);
	f->ly = ft_atoi(&table[i]);
	i++;
	while (table[i] != ' ' && table[i] != '\0')
		i++;
	f->lx = ft_atoi(&table[i]);
	free(table);
}

void		ft_getsizepiece(int *px, int *py)
{
	char	*piece;
	int		i;

	i = 6;
	get_next_line(0, &piece);
	*py = ft_atoi(piece + i);
	while (piece[i] != ' ' && piece[i] != '\0')
		i++;
	*px = ft_atoi(&piece[i]);
	free(piece);
}
