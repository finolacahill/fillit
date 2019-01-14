/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 21:47:33 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/14 20:03:12 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

t_point	ft_basicsolver(char **map, char *str, t_point x, int size)
{
	int		n;

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

char	**ft_del(char **map, char *str, int size)
{
	int		i;
	int		count;
	t_point	x;

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
char **ft_backtracker(char **map, char **table, int i, t_point z)
{
	map = ft_del(map, table[i], ft_strlen(map[1])); //delete where we previously put the piece
	z = ft_movepoints(z.x, z.y, 0, ft_strlen(map[1])); //move the coordinates forward to avoid repition 
	z = ft_basicsolver(map, table[i],z, ft_strlen(map[1])); // find next open space
		if (z.x <0) // if there is no open spaces
		{
			if (i == 0) //if we are also at i = 0 it means we have backtracked the whole way through are map and there are no open spaces left. I.e. this map is impossible and we need to increase it. We are using map[0] = NULL as a flag to let our ft_solver know it's time to increase the size of the map. 
				map[0] = NULL;
			return (NULL); //if we haven't finished backtracking we return NULL back to the backtracking function letting it know to go backwards and continue searching for possible solutions.
		}
		else
			return (ft_backtracking(map, table, i, z)); //there is a possible solution and our ft_backtracking can continue to try and move forward. 
}

char	**ft_backtracking(char **map, char **table, int i,  t_point z)
{
	t_point	y;
	char	**sign;
	
	y.x = 0;
	y.y = 0;
	sign = map;
	if (table[i] != NULL)
	{
		ft_place(map, table[i], z.x, z.y); // we placed the tetris piece, starting at A, 0,0 
		if (table[i + 1]!= NULL) // if there is another tetris piece
		{	
			y = ft_basicsolver(map, table[i + 1], y, ft_strlen(map[1])); 
			if (y.x >= 0)		//there is space for the next piece. we recall the function which will place the next piece and check the next next piece
				sign = ft_backtracking(map, table, i + 1, y);
			else
				sign = NULL; //we can not place the piece. We only reach here when the statement is moving forwards.
			if (sign == NULL) // we can not put this in the else because if we do, it will not be read when the function is moving backwards. 
				map = ft_backtracker(map, table, i, z);
		}
	}	
	return (map);
}

char **ft_solving(char **map, char *str, t_point z, int i)
{
	int size;
	int count;
	char ** table;

	z.x = 0;
	z.y = 0;

	count = ft_count_tmn(str);
	size = ft_minsize(count);
	table = ft_savetotable(str);
	map = ft_create_map(size, map);
	ft_backtracking(map, table, i, z);
	while (map[0] == NULL) // our flag to let us know if current map size is impossible
	{
		printf("impossible\n\n");
		ft_strdel(map);
		size++;
		i = 0;
		map = ft_create_map(size, map);
		map = ft_backtracking(map, table, i, z);
		
	}
	ft_printmap(map, size);
	return (map);
}

