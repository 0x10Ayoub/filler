/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhourba <akhourba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 15:40:44 by akhourba          #+#    #+#             */
/*   Updated: 2019/04/11 15:18:15 by akhourba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_gstrdup(char *s2, const char *s1)
{
	char	*t;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	t = (char*)malloc(sizeof(char) * (len + 1));
	if (t == NULL)
	{
		t = NULL;
		return (t);
	}
	while (*s1 != '\0')
		*(t + i++) = *s1++;
	*(t + i) = '\0';
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	return (t);
}

static char	*ft_gstrjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	str = (char *)ft_memalloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	ft_strcat(str, (char *)s1);
	ft_strcat(str, (char *)s2);
	free(s1);
	return (str);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str;
	int			i;

	i = 0;
	if (fd < 0 || read(fd, &buf, 0) < 0 || !line)
		return (-1);
	if (!str)
		str = ft_strnew(0);
	while ((ret = read((int)fd, &buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		str = ft_gstrjoin(str, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	i = ft_strlenc(str, '\n');
	*line = ft_strsub(str, 0, i);
	if (!ret && !ft_strlen(str) && !i)
		return (0);
	str = ft_gstrdup(str, str + i + 1);
	return (1);
}
