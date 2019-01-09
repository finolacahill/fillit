/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/09 14:05:07 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
//This is very much just a test main. It's a giant mess but it's a workign mess. To be cleaned up.
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
	int p = 0;
	int q = 0;
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
	table = ft_save_tmn(str); 
	while (table[n]) 
	{
		while (ft_moveup(table[n]) == 1);
		while (ft_moveleft(table[n]) == 1);
		++n;
	}
	ft_clean(table);
	size = ft_minsize(count);
	map = ft_create_map(size, map);
	i = 0;
	//to here, we're just creating our map and saving our tetris pieces. 

//this is the solving part, without backtracking. 
	while (i < count)
	{
		p = 0;
		q = 0;

		while (i < count && (n = ft_check_map(map, table[i], p, q)) == 0)
		{ 
			if (q != size) //if it's not the end of the line
				q++;
			if (q == size && p != size) //if it's the end of the line but not the end of the map
			{
				p++;
				q = 0;
			}
			if (p == size) //it's the end of the map
				break;
		}
		if (n > 0) // we could place all the pieces on the map
		{
			map = ft_place(map, table[i], p, q);
			i++;
		}
		if (n == 0) // we couldn't place all the pieces, so we increase map size
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
