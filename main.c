/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 23:28:43 by fcahill           #+#    #+#             */
/*   Updated: 2019/01/09 13:33:03 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

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
	while (i < count)
	{
		p = 0;
		q = 0;

		while (i < count && (n = ft_check_map(map, table[i], p, q)) == 0)
		{ 
			if (q != size)
				q++;
			if (q == size && p != size)
			{
				p++;
				q = 0;
			}
			if (p == size)
				break;
		}
		if (n > 0)
		{
			map = ft_place(map, table[i], p, q);
			i++;
		}
		if (n == 0)
		{
		 	ft_strdel(map);
			size++;
			i = 0;
			map = ft_create_map(size, map);
		}
	}
	n = 0;
	while (n < size)
	{
	printf("%s\n", map[n]);
	++n;
	}
return (0);
}
