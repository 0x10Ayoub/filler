/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getgameinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:07:21 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/12 12:39:26 by akhourba         ###   ########.fr       */
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

void		ft_getsizemap(int *x, int *y)
{
	char	*table;
	int		i;

	i = 0;
	get_next_line(0, &table);
	while (table[i] != ' ' && table[i] != '\0')
		i++;
	*x = ft_atoi(&table[i]);
	i++;
	while (table[i] != ' ' && table[i] != '\0')
		i++;
	*y = ft_atoi(&table[i]);
}

void		ft_getsizepiece(int *px, int *py)
{
	char	*piece;
	int		i;

	i = 6;
	get_next_line(0, &piece);
	*px = ft_atoi(&piece[i]);
	while (piece[i] != ' ' && piece[i] != '\0')
		i++;
	*py = ft_atoi(&piece[i]);
	free(piece);
}
