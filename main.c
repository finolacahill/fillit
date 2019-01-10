/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/10 21:48:04 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
//This is very much just a test main. It's a giant mess but it's a workign mess. To be cleaned up.
//this function belongs in the solver, just hanging out here for now. 
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
int		main(void)
{
	int		fd;
	int		n;
	char str[5000]; 
	char **table;
	char **map;
	int size;
	int count;
	int i;
	t_point x;
	fd = open("valide_26", O_RDONLY);
	while ((n = read(fd, str, 5000)) > 0)
		str[n] = '\0';
	//from here
	count = ft_count_tmn(str);
	if (ft_1validate(str) != 1)
	{
		ft_putstr("input error");
		return (0);
	}
	n = 0;
	table = ft_savetotable(str); 
	size = ft_minsize(count); 
	map = ft_create_map(size, map);
	i = 0;
	//to here, we're just creating our map and saving our tetris pieces. 
	//this is the solving part, without backtracking. 
	while (i < count)
	{
		x.x = 0;
		x.y = 0;

		while (i < count && (n = ft_check_map(map, table[i], x, size - 1)) == 0)
		{
			if (x.x == size - 1 && x.y == size - 1)
				break;
			x = (ft_movepoints(x.x, x.y, 0, size));

			if (x.x < 0)
				break;
		}
		if (n > 0) // we could place all the pieces on the map
		{
			map = ft_place(map, table[i], x.x, x.y);
			i++;
		}
		if (n <= 0) // we couldn't place all the pieces, so we increase map size
		{
			ft_strdel(map);
			size++;
			i = 0;
			map = ft_create_map(size, map);
		}
	}
	n = 0; //this is to print the map
	while (n < size)
	{
		ft_putstr(map[n]);
		ft_putchar('\n');
		++n;
	}
	return (0);
}
