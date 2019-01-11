/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:47:33 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/11 23:18:17 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_point	ft_movepoints(int x, int y, int start, int end)
{
	t_point	q;

	q.x = x;
	q.y = y;
	if (q.y != end)
		q.y++;
	if (q.y == end && q.x != end)
	{
		q.x++;
		q.y = start;
	}
	if (q.y == end && q.x == end)
	{
		q.x = -1;
		q.y = -1;
	}
	return (q);
}

t_point	ft_basicsolver(char **map, char *str, t_point x, int size)
{
	int n;

	n = 0;
	while ((n = ft_check_map(map, str, x, size - 1)) == 0)
	{
		if (x.x == size - 1 && x.y == size - 1)
		{
			n = -1;
			break;
		}
		x = (ft_movepoints(x.x, x.y, 0, size));
		if (x.x < 0)
			break;
	}
	if (n <= 0)
		x.x = -1;
	return (x);
}
/*
   table = ft_savetotable(str);
   size = ft_minsize(count);
   map = ft_create_map(size, map);
   i = 0;
   */
char	**ft_del(char **map, char *str, int x, int y)
{
	int		i;
	int		start;

	i = 0;
	start = y;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			++x;
			++i;
			y = start;
		}
		if ((str[i] >= 'A' && str[i] <= 'Z'))
			map[x][y] = '.';
		++i;
		++y;
	}
	return (map);
}

char	**ft_backtracking(char **map, char **table, int i,  t_position z)
{

	t_point y;
	int size;

	size = ft_strlen(map[0]);
	y.x = 0;
	y.y = 0;
	ft_place(map, table[i], z.current.x, z.current.y);	
//	ft_printmap(map, size);
//	printf("\n---------\n");
	i++;
	if (table[i] != NULL)
	{
		y = ft_basicsolver(map, table[i], y, size);
		if (y.x >= 0)
		{
			z.previous = z.current;
			z.current = y;
			ft_backtracking(map, table, i, z);
		}
		else
		{	
			i--;
			map = ft_del(map, table[i], z.current.x, z.current.y);
			z.current = ft_movepoints(z.current.x, z.current.y, 0, size);;
			z.current  = ft_basicsolver(map, table[i], z.current, size);
			//	printf("%s\n", table[i]);
			if (z.current.x < 0)
			{
//				printf("fail\n");
//				ft_printmap(map, size);
//				printf("-----------\n\n");
				map[0] = NULL;
				return (map);
			}

			//	printf("%d\n", i);
			ft_backtracking(map, table, size, z);
		}
	}
	return (map);
}

char **ft_solving(char **map, char **table, t_position z, int i)
{
	int size;

	size = ft_strlen(map[0]);
	z.previous.x = 0;
	z.previous.y = 0;
	z.current.x = 0;
	z.current.y = 0;
	ft_backtracking(map, table, i, z);
	while (map[0] == NULL)
	{
	//	printf("impossible\n\n");
		ft_strdel(map);
		size++;
		i = 0;
		map = ft_create_map(size, map);
	//	printf("x = %d y = %d\n\n", z.current.x, z.current.y);
		ft_backtracking(map, table, i, z);
	}
	return (map);
}

