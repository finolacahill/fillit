/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill  <fboudyaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 20:44:25 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/18 19:02:19 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_len(int i, char **table, int j)
{
	j = 0;
	if (i == 2)
	{
		if (ft_isalpha(table[j][0]) != 1 || ft_isalpha(table[j][1]) != 1
				|| table[j][2] != '\n' || ft_isalpha(table[j][3]) != 1
				|| ft_isalpha(table[j][4]) != 1)
			i = 3;
	}
	if (i == 3)
	{
		if (ft_isalpha(table[j][0]) == 1 && ft_isalpha(table[j][1]) == 1
				&& ft_isalpha(table[j][2]) == 1
				&& ft_isalpha(table[j][3]) == 1)
			i = 4;
		if (i == 3 && ft_isalpha(table[j][0]) == 1
				&& ft_isalpha(table[j][2]) == 1
				&& table[j][3] == '\n' && table[j][1] == '\n'
				&& table[j][5] == '\n' && ft_isalpha(table[j][4]) == 1
				&& ft_isalpha(table[j][6]) == 1)
			i = 4;
	}
	return (i);
}

int				ft_minsize(int quantity, char **table)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	quantity = quantity * 4;
	while (quantity > (i * i))
		++i;
	i = ft_len(i, table, j);
	return (i);
}

char			**ft_create_map(int size, char **map)
{
	int			i;
	int			j;

	j = 0;
	if (!(map = (char**)malloc((sizeof(char*) * (size + 1)))))
		return (NULL);
	while (j < size)
	{
		i = 0;
		if (!(map[j] = (char*)malloc((sizeof(char) * (size + 1)))))
			return (NULL);
		while (i < size)
			map[j][i++] = '.';
		map[j][size] = '\0';
		j++;
	}
	map[size] = NULL;
	return (map);
}

int				ft_check_map(char **map, char *str, t_point x, int limit)
{
	int			i;
	int			start;

	start = x.y;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (i++ || 1))
		{
			if (x.x == limit)
				return (0);
			x.x++;
			x.y = start;
		}
		if (str[i] == '.' && (i++ || 1))
			x.y++;
		if ((str[i] >= 'A' && str[i] <= 'Z') && (i++ || 1))
		{
			if (map[x.x][x.y] == '.')
				x.y++;
			else
				return (0);
		}
	}
	return (1);
}

char			**ft_place(char **map, char *str, int x, int y)
{
	int			i;
	int			start;

	i = 0;
	start = y;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			++x;
			if (map[x] == NULL)
			{
				map[0] = NULL;
				return (NULL);
			}
			++i;
			y = start;
		}
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			map[x][y] = str[i];
		++i;
		++y;
	}
	return (map);
}
