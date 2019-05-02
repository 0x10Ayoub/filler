/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsleak.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:05:37 by akhourba          #+#    #+#             */
/*   Updated: 2019/05/01 20:09:57 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void    ft_freemap(unsigned char ***map, int y)
{
	int				i;
	unsigned char	**lmap;

    lmap = *map;
	i = -1;
	while (++i < y)
    {
        free(lmap[i]);
        lmap[i] = NULL;
    }
	free(lmap);
    lmap = NULL;
}