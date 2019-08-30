/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:47:33 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/17 13:37:14 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_point	ft_basicsolver(char **map, char *str, t_point x, int size)
{
	int			n;

	n = 0;
	while ((n = ft_check_map(map, str, x, size - 1)) == 0)
	{
		if (x.x == size - 1 && x.y == size - 1)
		{
			n = -1;
			break ;
		}
		x = (ft_movepoints(x.x, x.y, 0, size));
		if (x.x < 0)
			break ;
	}
	if (n <= 0)
		x.x = -1;
	return (x);
}

static char		**ft_del(char **map, char *str, int size)
{
	int			i;
	int			count;
	t_point		x;

	count = 0;
	i = 0;
	while (ft_isalpha(str[i]) == 0)
		++i;
	x.x = 0;
	x.y = 0;
	while (count != 4)
	{
		if (map[x.x][x.y] == str[i])
		{
			map[x.x][x.y] = '.';
			count++;
		}
		x = ft_movepoints(x.x, x.y, 0, size);
	}
	return (map);
}

static char		**ft_backtracker(char **map, char **table, int i, t_point z)
{
	map = ft_del(map, table[i], ft_strlen(map[1]));
	z = ft_movepoints(z.x, z.y, 0, ft_strlen(map[1]));
	z = ft_basicsolver(map, table[i], z, ft_strlen(map[1]));
	if (z.x < 0)
	{
		if (i == 0)
		{
			free(map[0]);
			map[0] = NULL;
		}
		return (NULL);
	}
	else
		return (ft_backtracking(map, table, i, z));
}

char			**ft_backtracking(char **map, char **table, int i, t_point z)
{
	t_point		y;
	char		**sign;

	y.x = 0;
	y.y = 0;
	sign = map;
	if (table[i] != NULL)
	{
		ft_place(map, table[i], z.x, z.y);
		if (table[i + 1] != NULL)
		{
			y = ft_basicsolver(map, table[i + 1], y, ft_strlen(map[1]));
			if (y.x >= 0)
				sign = ft_backtracking(map, table, i + 1, y);
			else
				sign = NULL;
			if (sign == NULL)
				map = ft_backtracker(map, table, i, z);
		}
	}
	return (map);
}

void			ft_solving(char **map, char *str, t_point z)
{
	int			size;
	int			i;
	char		**table;

	i = 0;
	table = ft_savetotable(str);
	if (table == NULL)
		return (ft_putstr("error\n"));
	size = ft_minsize(ft_count_tmn(str), table);
	map = ft_create_map(size, map);
	if (map == NULL)
		return (ft_putstr("error\n"));
	ft_backtracking(map, table, i, z);
	while (map[0] == NULL)
	{
		ft_freearray(map, size);
		size++;
		map = ft_create_map(size, map);
		if (map == NULL)
			return (ft_putstr("error\n"));
		ft_backtracking(map, table, i, z);
	}
	ft_printmap(map, size);
	ft_freearray(table, ft_count_tmn(str));
	ft_freearray(map, size);
}
